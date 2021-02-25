#include<stdio.h>
#define max 6
int q[max];
int front=0,rear=-1;
void insert(int item)
{
 if(rear==max-1)
 printf("\nQueue is full");
 else
 {
  int j;
  j=rear;
  while((j>=front)&&(item<q[j]))
  {
   q[j+1]=q[j];
   j--;
  }
  q[j+1]=item;
  rear++;
 }
}
void delete()
{
 if(front>rear)
 printf("\nQueue is empty");
 else
 {
  int item;
  item=q[front];
  printf("\nThe deleted item is %d",item);
  front++;
 }
}
void display()
{
 if(front>rear)
 printf("\nQueue is empty");
 else
 {
  int i;
  printf("\nThe elements of the queue are:");
  for(i=front;i<=rear;i++)
  printf("%d\t",q[i]);
 }
}
int main()
{
 int ch,item;
 printf("\nMENU");
 printf("\n1.insert\n2.delete\n3.display\n4.exit");
 while(1)
 {
  printf("\nEnter your choice:");
  scanf("%d",&ch);
  switch(ch)
  {
   case 1: printf("\nEnter the item to be inserted:");
           scanf("%d",&item);
           insert(item);
           break;
   case 2: delete();
           break;
   case 3: display();
           break;
   case 4: exit(0);
           break;
   default:printf("\nInvalid choice. Please enter a valid choice.");
  }
 }
 return 0;
}
