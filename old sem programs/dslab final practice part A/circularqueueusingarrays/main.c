
#include<stdio.h>
#define max 6
int q[max];
int count=0;
int front=0,rear=-1;
void insert(int item)
{
 if(count==max)
 printf("\nQueue is full");
 else
 {
  rear=(rear+1)%max;
  q[rear]=item;
  count++;
 }
}
void delete()
{
 if(count==0)
 printf("\nQueue is empty");
 else
 {
  int item;
  item=q[front];
  printf("\nThe deleted item is %d",item);
  front=(front+1)%max;
  count--;
 }
}
void display()
{
 if(count==0)
 printf("\nQueue is empty");
 else
 {
  int j,i;
  j=front;
  printf("\nThe elements of the queue are:");
  for(i=0;i<count;i++)
  {
   printf("%d\t",q[j]);
   j=(j+1)%max;
  }
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
   case 1:printf("\nEnter the item to be inserted:");
          scanf("%d",&item);
          insert(item);
          break;
   case 2:delete();
          break;
   case 3:display();
          break;
   case 4:exit(0);
          break;
   default:printf("\nInvalid choice. Please enter a valid choice.");
  }
 }
 return 0;
}
