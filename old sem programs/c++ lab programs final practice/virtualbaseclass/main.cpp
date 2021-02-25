#include<iostream>
using namespace std;
class student
{
 protected:int roll;
 public:
 void getroll()
 {
  cout<<"\nEnter the student's roll no:";
  cin>>roll;
 }
 void putroll()
 {
  cout<<"\nThe student's roll no is "<<roll;
 }
};
class test:virtual public student
{
 protected: float mark1,mark2;
 public:
 void getmark()
 {
  cout<<"\nEnter the marks obtained in subject1:";
  cin>>mark1;
  cout<<"\nEnter the marks obtained in subject2:";
  cin>>mark2;
 }
 void putmark()
 {
  cout<<"\nThe marks obtained in subject1 is "<<mark1;
  cout<<"\nThe marks obtained in subject2 is "<<mark2;
 }
};
class sports:virtual public student
{
 protected: float sscore;
 public:
 void getsport()
 {
  cout<<"\nEnter the sport score:";
  cin>>sscore;
 }
 void putsport()
 {
  cout<<"\nThe sport score is "<<sscore;
 }
};
class result:public test,public sports
{
 protected: float total;
 public:
 void getdata()
 {
  getroll();
  getmark();
  getsport();
 }
 void putdata()
 {
  total=mark1+mark2+sscore;
  putroll();
  putmark();
  putsport();
  cout<<"\nThe total marks obtained by the student is "<<total;
 }
};
int main()
{
 int n,i;
 result x[100];
 cout<<"\nEnter the no of students:";
 cin>>n;
 for(i=0;i<n;i++)
 {
  cout<<"\nEnter the details of student "<<i+1<<":-";
  x[i].getdata();
 }
 for(i=0;i<n;i++)
 {
  cout<<"\nThe details of student "<<i+1<<" are as follows:-";
  x[i].putdata();
 }
 return 0;
}
