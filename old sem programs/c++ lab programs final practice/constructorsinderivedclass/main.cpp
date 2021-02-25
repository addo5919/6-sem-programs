#include<iostream>
using namespace std;
class A
{
 protected: int a;
 public:
 A(int x)
 {
  a=x;
 }
 void dispa()
 {
  cout<<"\na="<<a;
 }
};
class B
{
 protected: int b;
 public:
 B(int x)
 {
  b=x;
 }
 void dispb()
 {
  cout<<"\nb="<<b;
 }
};
class C:public A,public B
{
 protected: float c,d;
 public:
 C(int a,int b,float m,float n):A(a),B(b)
 {
  c=m;
  d=n;
 }
 void dispcd()
 {
  cout<<"\nc="<<c;
  cout<<"\nd="<<d;
 }
};
int main()
{
 C x(10,20,30.5,40.5);
 x.dispa();
 x.dispb();
 x.dispcd();
 return 0;
}
