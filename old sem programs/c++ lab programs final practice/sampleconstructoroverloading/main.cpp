#include<iostream>
using namespace std;
class sample
{
 int a;
 char b;
 float c;
 public:
 sample()
 {
  a=10;
  b='a';
  c=10.5;
 }
 sample(int x,char y,float z)
 {
  a=x;
  b=y;
  c=z;
 }
 sample(sample &x)
 {
  a=x.a;
  b=x.b;
  c=x.c;
 }
 void display()
 {
  cout<<"\na="<<a;
  cout<<"\nb="<<b;
  cout<<"\nc="<<c;
 }
};
int main()
{
 sample x1;
 x1.display();
 sample x2(20,'x',20.5);
 x2.display();
 sample x3=x2;
 x3.display();
 return 0;
}
