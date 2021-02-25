#include<iostream>
using namespace std;
class employee
{
 int eno;
 char ename[20];
 float salary;
 public:
 void getdata()
 {
  cout<<"\nEnter the employee's no:";
  cin>>eno;
  cout<<"\nEnter the employee's name:";
  cin>>ename;
  cout<<"\nEnter the employee's salary:";
  cin>>salary;
 }
 void putdata()
 {
  cout<<"\nThe employee's no is "<<eno;
  cout<<"\nThe employee's name is "<<ename;
  cout<<"\nThe employee's salary is "<<salary;
 }
};
int main()
{
 int n,i;
 employee x[100];
 cout<<"\nEnter the no of employees:";
 cin>>n;
 for(i=0;i<n;i++)
 {
  cout<<"\nEnter the details of employee "<<i+1<<":-";
  x[i].getdata();
 }
 for(i=0;i<n;i++)
 {
  cout<<"\nThe details of employee "<<i+1<<" are as follows:-";
  x[i].putdata();
 }
 return 0;
}
