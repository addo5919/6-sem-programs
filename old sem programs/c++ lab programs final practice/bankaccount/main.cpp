#include<iostream>
using namespace std;
class bankaccount
{
 char name[20];
 int acno;
 float balance=0;
 public:
  bankaccount()
 {
  cout<<"\nEnter the name:";
  cin>>name;
  cout<<"\nEnter the account no:";
  cin>>acno;
 }
 void deposit()
 {
  float amount;
  cout<<"\nEnter the amount you would like to deposit:";
  cin>>amount;
  balance=balance+amount;
 }
 void withdraw()
 {
  float amount;
  cout<<"\nEnter the amount you would like to withdraw:";
  cin>>amount;
  if(amount>balance)
  cout<<"\nRequest cannot be processed as the entered amount is more than what is present in the savings.";
  else
  balance=balance-amount;
 }
 void putdata()
 {
  cout<<"\nThe name of the depositor is "<<name;
  cout<<"\nThe balance present in their account is "<<balance;
 }
};
int main()
{
 bankaccount x;
 int ch;
 cout<<"\nMENU";
 cout<<"\n1.deposit,2.withdraw,3.display,4.exit";
 while(1)
 {
  cout<<"\nEnter your choice:";
  cin>>ch;
  switch(ch)
  {
   case 1: x.deposit();
   break;
   case 2: x.withdraw();
   break;
   case 3: x.putdata();
   break;
   case 4: exit(0);
   break;
   default: cout<<"\nInvalid choice please enter a valid choice.";
  }
 }
 return 0;
}
