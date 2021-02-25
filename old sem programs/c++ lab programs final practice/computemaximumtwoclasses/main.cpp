#include<iostream>
using namespace std;
class B;
class A
{
 int a;
 public:
 void geta()
 {
  cout<<"\nEnter the value of a:";
  cin>>a;
 }
 void dispa()
 {
  cout<<"\na="<<a;
 }
 friend void max(A x,B y);
};
class B
{
 int b;
 public:
 void getb()
 {
  cout<<"\nEnter the value of b:";
  cin>>b;
 }
 void dispb()
 {
  cout<<"\nb="<<b;
 }
 friend void max(A x,B y);
};
void max(A x,B y)
{
 if(x.a>y.b)
 {
  cout<<"\n"<<x.a<<" is greater than "<<y.b<<" or a is greater than b";
 }
 else
 cout<<"\n"<<y.b<<" is greater than "<<x.a<<" or b is greater than a";
}
int main()
{
 A x;
 B y;
 x.geta();
 y.getb();
 x.dispa();
 y.dispb();
 max(x,y);
 return 0;
}
