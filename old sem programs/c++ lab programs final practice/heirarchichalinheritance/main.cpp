#include<iostream>
using namespace std;
class student
{
 char name[20];
 public:
 void getstudent()
 {
  cout<<"\nEnter the name of the student:";
  cin>>name;
 }
 void putstudent()
 {
  cout<<"\nThe name of the student is "<<name;
 }
};
class medical:public student
{
 int neetrank;
 char medcolname[20];
 public:
 void getmed()
 {
  cout<<"\nEnter the neet rank:";
  cin>>neetrank;
  cout<<"\nEnter the medical college name:";
  cin>>medcolname;
 }
 void putmed()
 {
  cout<<"\nThe neet rank is "<<neetrank;
  cout<<"\nThe name of the medical college is "<<medcolname;
 }
};

class engineering:public student
{
 int jeerank;
 char engcolname[20];
 public:
 void geteng()
 {
  cout<<"\nEnter the jee rank:";
  cin>>jeerank;
  cout<<"\nEnter the engineering college name:";
  cin>>engcolname;
 }
 void puteng()
 {
  cout<<"\nThe jee rank is "<<jeerank;
  cout<<"\nThe name of the engineering college is "<<engcolname;
 }
};
int main()
{
 int ch;
 cout<<"\nMENU";
 cout<<"\n1.engineering\n2.medical";
 cout<<"\nEnter your choice:";
 cin>>ch;
 switch(ch)
 {
  case 1: engineering x;
          x.getstudent();
          x.geteng();
          x.putstudent();
          x.puteng();
          break;
  case 2: medical y;
          y.getstudent();
          y.getmed();
          y.putstudent();
          y.putmed();
          break;
 default: cout<<"\nInvalid choice! Program terminated";
 }
 return 0;
}
