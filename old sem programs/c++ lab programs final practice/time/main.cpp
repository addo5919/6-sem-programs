#include<iostream>
using namespace std;
class time
{
 int hours;
 int minutes;
 public:
 void gettime()
 {
  int h1,m1,h2,m2;
  cout<<"\nEnter time1(first hours and then minutes):";
  cin>>h1>>m1;
  cout<<"\nEnter time2:";
  cin>>h2>>m2;
  minutes=m1+m2;
  hours=minutes/60;
  minutes=minutes%60;
  hours=hours+h1+h2;
 }
 void puttime()
 {
  cout<<"\nThe added time is as follows:-";
  cout<<"\n"<<hours<<" hours and "<<minutes<<" minutes";
 }
};
int main()
{
 time x;
 x.gettime();
 x.puttime();
 return 0;
}
