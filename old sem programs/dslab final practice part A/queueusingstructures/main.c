#include<stdio.h>
#define max 6
struct queue
{
 int q[max];
 int front,rear;
};
void insert(struct queue *q,int item)
{
 if(q->rear==max-1)
 printf("\nQueue is full");
 else
 {
  (q->rear)++;
   q->q[q->rear]=item;
 }
}
void delete(struct queue *q)
{
 if(q->front>q->rear)
 printf("\nQueue is empty");
 else
 {
  int item;
  item=q->q[q->front];
  printf("\nThe deleted item is %d",item);
  (q->front)++;
 }
}
void display(struct queue *q)
{
 if(q->front>q->rear)
 printf("\nQueue is empty");
 else
 {
  int i;
  printf("\nThe elements of the queue are:");
  for(i=q->front;i<=(q->rear);i++)
  printf("%d\t",q->q[i]);
 }
}
int main()
{
 struct queue q;
 q.front=0;
 q.rear=-1;
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
          insert(&q,item);
          break;
   case 2:delete(&q);
          break;
   case 3:display(&q);
          break;
   case 4:exit(0);
          break;
   default:printf("\nInvalid choice. Please enter a valid choice.");
  }
 }
 return 0;
}
