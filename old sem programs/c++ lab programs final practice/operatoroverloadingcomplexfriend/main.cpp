#include<iostream>
using namespace std;
class complex
{
 int i,r;
 public:
 void getdata()
 {
  cout<<"\nEnter the real and imaginary parts respectively:";
  cin>>r>>i;
 }
 void putdata()
 {
  if(i<0)
  cout<<"\n"<<r<<i<<"i";
  else
  cout<<"\n"<<r<<"+i"<<i;
 }
 friend complex operator +(complex c1,complex c2);
 friend complex operator -(complex c1,complex c2);
};
 complex operator +(complex c1,complex c2)
 {
  complex t;
  t.r=c1.r+c2.r;
  t.i=c1.i+c2.i;
  return(t);
 }
 complex operator -(complex c1,complex c2)
 {
  complex t;
  t.r=c1.r-c2.r;
  t.i=c1.i-c2.i;
  return(t);
 }
int main()
{
 int ch;
 cout<<"\nMENU";
 cout<<"\n1.add\n2.subtract";
 cout<<"\nEnter your choice:";
 cin>>ch;
 if(ch==1)
 {
  complex c1,c2,c3;
  c1.getdata();
  c2.getdata();
  c3=c1+c2;
  c1.putdata();
  c2.putdata();
  c3.putdata();
 }
 else if(ch==2)
 {
  complex c1,c2,c3;
  c1.getdata();
  c2.getdata();
  c3=c1-c2;
  c1.putdata();
  c2.putdata();
  c3.putdata();
 }
 else
 {
  cout<<"\nInvalid choice! Program terminated";
 }
 return 0;
}
