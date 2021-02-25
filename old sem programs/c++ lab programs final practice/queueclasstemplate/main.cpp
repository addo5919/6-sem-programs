#include<iostream>
using namespace std;
#define max 5
template<class X>
class q
{
 int front=0,rear=-1;
 X q[max];
 public:
 void enqueue()
 {
  if(rear==max-1)
  cout<<"\nqueue is full";
  else
  {
   X item;
   cout<<"\nEnter the item to be inserted:";
   cin>>item;
   rear++;
   q[rear]=item;
  }
 }
 void dequeue()
 {
  if(front>rear)
  cout<<"\nqueue is empty";
  else
  {
   X item;
   item=q[front];
   front++;
   cout<<"\nThe deleted item is "<<item;
  }
 }
 void display()
 {
  if(front>rear)
  cout<<"\nqueue is empty";
  else
  {
   int i;
   cout<<"\nThe elements of the queue are:";
   for(i=front;i<=rear;i++)
   cout<<"\t"<<q[i];
  }
 }
 void operation()
 {
  int ch;
  cout<<"\nMENU";
  cout<<"\n1.insert,2.delete,3.display,4.exit";
  while(1)
  {
   cout<<"\nEnter your choice:";
   cin>>ch;
   switch(ch)
   {
    case 1: enqueue();
    break;
    case 2: dequeue();
    break;
    case 3: display();
    break;
    case 4: exit(0);
    break;
    default:cout<<"\nInvalid choice. Please enter a valid choice.";
   }
  }
 }
};
int main()
{
 int ch;
 cout<<"\n1.for integer queue\n2.for float queue";
 cout<<"\nEnter your choice:";
 cin>>ch;
 if(ch==1)
 {
  q <int>x;
  x.operation();
 }
 if(ch==2)
 {
  q <float>y;
  y.operation();
 }
 else
 cout<<"\nInvalid choice! Program terminated";
 return 0;
}
