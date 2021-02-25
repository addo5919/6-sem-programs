#include<iostream>
using namespace std;
class shape
{
 protected: double x,y;
 public:
 void getdata()
 {
  cout<<"\nEnter two values:";
  cin>>x>>y;
 }
 virtual void displayarea()
 {
 }
};
class triangle:public shape
{
 public:
 void displayarea()
 {
  cout<<"\nArea of the triangle is "<<(0.5*x*y);
 }
};
class rectangle:public shape
{
 public:
 void displayarea()
 {
  cout<<"\nArea of the rectangle is "<<(x*y);
 }
};
int main()
{
 shape *ptr;
 triangle t;
 rectangle r;
 ptr=&t;
 ptr->getdata();
 ptr->displayarea();
 ptr=&r;
 ptr->getdata();
 ptr->displayarea();
 return 0;
}
