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
  cout<<"\n"<<r<<"+i"<<i;
 }
 friend complex add(int a,complex c);
 friend complex add(complex c1,complex c2);
};
complex add(int a,complex c)
{
 complex t;
 t.r=c.r+a;
 t.i=c.i;
 return(t);
}
complex add(complex c1,complex c2)
{
 complex t;
 t.r=c1.r+c2.r;
 t.i=c1.i+c2.i;
 return(t);
}
int main()
{
 complex c1,c2,c3;
 int a;
 c1.getdata();
 cout<<"\nEnter the value which is to be added to the real part of the first complex no in order to generate the second complex no:";
 cin>>a;
 c2=add(a,c1);
 c3=add(c1,c2);
 c1.putdata();
 c2.putdata();
 c3.putdata();
 return 0;
}
