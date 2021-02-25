#include<stdio.h>
struct node
{
 int info;
 struct node *link;
};
typedef struct node* NODE;
NODE getnode()
{
 NODE X;
 X=(NODE)malloc(sizeof(struct node));
 if(X==NULL)
 printf("\nMemory is not available");
 else
 return(X);
}
void freenode(NODE X)
{
 free(X);
}
NODE insert(int item,NODE start)
{
 NODE temp;
 temp=getnode();
 temp->info=item;
 int pos,count=0,i;
 printf("\nEnter the position where you want to insert:");
 scanf("%d",&pos);
 NODE cur;
 cur=start;
 while(cur!=NULL)
 {
  count++;
  cur=cur->link;
 }
 if((pos>count)&&(pos!=(count+1)))
 {
  printf("\nPosition not found, exceeded");
  freenode(temp);
  return(start);
 }
 if(pos==1)
 {
  temp->link=start;
  return(temp);
 }
 NODE temp2;
 temp2=start;
 for(i=0;i<(pos-2);i++)
 temp2=temp2->link;
 temp->link=temp2->link;
 temp2->link=temp;
 return(start);
}

NODE delete_front(NODE start)
{
 if(start==NULL)
 {
  printf("\nList is empty");
  return(start);
 }
 NODE cur;
 cur=start;
 if(cur->link==NULL)
 {
  printf("\nThe deleted item is %d",cur->info);
  freenode(cur);
  return(NULL);
 }
  printf("\nThe deleted item is %d",cur->info);
  start=cur->link;
  freenode(cur);
  return(start);
}
void display(NODE start)
{
 if(start==NULL)
 {
  printf("\nList is empty");
  return;
 }
 NODE cur;
 cur=start;
 printf("\nThe elements of the linked list are:");
 while(cur!=NULL)
 {
  printf("%d\t",cur->info);
  cur=cur->link;
 }
}
int main()
{
 int item,ch;
 char name[20];
 NODE start;
 start=NULL;
 printf("\nMENU");
 printf("\n1.insert element at specified position\n2.delete from the front\n3.display\n4.exit");
 while(1)
 {
  printf("\nEnter your choice:");
  scanf("%d",&ch);
  switch(ch)
  {
   case 1:printf("\nEnter the item to be inserted:");
          scanf("%d",&item);
          start=insert(item,start);
          break;
   case 2:start=delete_front(start);
          break;
   case 3:display(start);
          break;
   case 4:exit(0);
          break;
   default:printf("\nInvalid choice. Please enter a valid choice.");
  }
 }
 return 0;
}
