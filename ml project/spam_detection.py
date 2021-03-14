# -*- coding: utf-8 -*-
"""
Created on Tue Feb 23 19:06:55 2021

@author: aditya
"""

from nltk.tokenize import RegexpTokenizer, word_tokenize
from nltk.stem import PorterStemmer
from nltk.corpus import stopwords
import numpy as np
import pandas as pd
from sklearn.preprocessing import LabelEncoder
from sklearn.feature_extraction.text import CountVectorizer
from sklearn.model_selection import train_test_split

df = pd.read_csv('spam.csv', encoding='ISO-8859-1')
le = LabelEncoder()

data = df.to_numpy()

X = data[:, 1]
y = data[:, 0]
print(X.shape)
print(y.shape)

tokenizer = RegexpTokenizer('\w+')
sw = set(stopwords.words('english'))
ps = PorterStemmer()

def getStem(review):
    review = review.lower()
    tokens = tokenizer.tokenize(review) # breaking into small words
    removed_stopwords = [w for w in tokens if w not in sw]
    stemmed_words = [ps.stem(token) for token in removed_stopwords]
    clean_review = ' '.join(stemmed_words)
    return clean_review

# get a clean document
def getDoc(document):
    d = []
    for doc in document:
        d.append(getStem(doc))
    return d

stemmed_doc = getDoc(X)
print(stemmed_doc[:10])

cv = CountVectorizer()
# create my vocab
vc = cv.fit_transform(stemmed_doc)
X = vc.todense()
X_train, X_test, y_train, y_test = train_test_split( X, y, test_size=0.33, random_state=42)
# NB from sklearn
from sklearn.naive_bayes import MultinomialNB
model = MultinomialNB()
model.fit(X_train, y_train)
print(model.score(X_test, y_test))
'''------------------------------------------------------------------------------------------------------------------------
messages = [
    """
    Hi Aditya,
We invite you to participate in MishMash - India’s largest online diversity hackathon. 
The hackathon is a Skillenza initiative and sponsored by Microsoft, Unity, Unilever, Gojek, Rocketium and Jharkhand Government. 
We have a special theme for you - Deep Tech/Machine Learning - sponsored by Unilever, which will be perfect for you.
    """,
    """Join us today at 12:00 PM ET / 16:00 UTC for a Red Hat DevNation tech talk on AWS Lambda and serverless Java with Bill Burke.
Have you ever tried Java on AWS Lambda but found that the cold-start latency and memory usage were far too high? 
In this session, we will show how we optimized Java for serverless applications by leveraging GraalVM with Quarkus to 
provide both supersonic startup speed and a subatomic memory footprint.""",

    """We really appreciate your interest and wanted to let you know that we have received your application.
There is strong competition for jobs at Intel, and we receive many applications. As a result, it may take some time to get back to you.
Whether or not this position ends up being a fit, we will keep your information per data retention policies, 
so we can contact you for other positions that align to your experience and skill set.
"""
]
----------------------------------------------------------------------------------------------------------------------------
'''
def prepare(messages):
    d = getDoc(messages)
    # dont do fit_transform!! it will create new vocab.
    return cv.transform(d)


#---------------------GUI---------------------------------------------------------------------------------------------------

from tkinter import *
from tkinter import messagebox

def myClick():
    message=myTextBox.get(1.0,END)
    messages=[message]
    messages=prepare(messages)
    y_pred=model.predict(messages)
    result=y_pred[0]
    if(result=='ham'):
         messagebox.showinfo("Result","The entered message is not spam")
    else:
         messagebox.showinfo("Result","The entered message is spam")
    myTextBox.delete(1.0,END)
        
root=Tk()
root.title("Spam message checker")
myLabel=Label(root,text="Enter the message:")
myTextBox=Text(root,width=60,height=20)
myButton=Button(root,text="Check",command=myClick)
myLabel.grid(row=0,column=0)
myTextBox.grid(row=1,column=0)
myButton.grid(row=2,column=0)
root.mainloop()
