#include<iostream>
#include<string.h>
using namespace std;
class S
{
 char *name;
 int length;
 public:
 S()
 {
  length=0;
  name=new char[length+1];
 }
 S(char *s)
 {
  length=strlen(s);
  name=new char[length+1];
  strcpy(name,s);
 }
 void display()
 {
  cout<<"\n"<<name;
 }
 void join(S a,S b)
 {
  length=a.length+b.length;
  name=new char[length+1];
  strcpy(name,a.name);
  strcat(name,b.name);
 }
};
int main()
{
 char name1[20],name2[20];
 cout<<"\nEnter two names:";
 cin>>name1>>name2;
 S s1(name1);
 S s2(name2);
 S s3;
 s3.join(s1,s2);
 s1.display();
 s2.display();
 s3.display();
 return 0;
}
