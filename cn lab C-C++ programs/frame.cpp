#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;

struct frame{ //each frame contains a frame no(which will be used for sorting) and data(3 letters)
    int no;
    char letters[3];
};

int main()
{
    struct frame fArray[10],fArray2[10]; //(structure) array which contains 10 frames: fArray[0],fArray[1]------fArray[9]
    char string[50];
    int i,j,ord;

    cout<<"\nEnter a string:";
    gets(string);
    cout<<"\n"<<string;

    int nof=ceil(strlen(string)/3.0); //obtaining no of frames required. Each frame holds 3 letters
    //in denominator that is 3.0, putting .0 is important otherwise we will not get point answers
    for(i=0;i<nof;i++)
    {
        fArray[i].no=i;
        fArray[i].letters[0]=string[3*i];
        fArray[i].letters[1]=string[3*i+1];
        fArray[i].letters[2]=string[3*i+2];
    }

    cout<<"\nFrames contents before shuffling :-";
    cout<<"\n";
    for(i=0;i<nof;i++)
    {
     cout<<"Frame no: "<<fArray[i].no;
     cout<<"      Content: "<<fArray[i].letters;
     cout<<"\n";
    }
    
    cout<<"\nEnter the order for shuffling:";
    
    for(i=0;i<nof;i++)
    {
     cin>>ord;    
     fArray2[i]=fArray[ord];
    }

     cout<<"\nFrames contents after shuffling :-";
    cout<<"\n";
    for(i=0;i<nof;i++)
    {
     cout<<"Frame no: "<<fArray2[i].no;
     cout<<"      Content: "<<fArray2[i].letters;
     cout<<"\n";
    }

    //now we have to sort fArray[2] according to fArray[i].no
    //bubble sort
    for(i=0;i<nof-1;i++) //for(i=0;i<=nof-2;i++) 
    {
        for(j=0;j<nof-1-i;j++)
        {
            if(fArray2[j].no>fArray2[j+1].no)
            {
                struct frame temp;
                temp=fArray2[j];
                fArray2[j]=fArray2[j+1];
                fArray2[j+1]=temp;
            }

        }
    }

     cout<<"\nFrames contents after sorting :-";
    cout<<"\n";
    for(i=0;i<nof;i++)
    {
     cout<<"Frame no: "<<fArray2[i].no;
     cout<<"      Content: "<<fArray2[i].letters;
     cout<<"\n";
    }
    
    cout<<"\nData received at receivers side: ";
    for(i=0;i<nof;i++)
    cout<<fArray2[i].letters;
    
    return 0;

}
