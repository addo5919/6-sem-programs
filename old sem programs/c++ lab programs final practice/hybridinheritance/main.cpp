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
class test:public student
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
class sports
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
 result x;
 x.getdata();
 x.putdata();
 return 0;
}
