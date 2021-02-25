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
NODE insert_front(int item,NODE start)
{
 NODE temp;
 temp=getnode();
 temp->info=item;
 if(start==NULL)
 {
  temp->link=NULL;
  return(temp);
 }
 NODE cur;
 cur=start;
 temp->link=cur;
 return(temp);
}

NODE insert_rear(int item,NODE start)
{
 NODE temp;
 temp=getnode();
 temp->info=item;
 temp->link=NULL;
 if(start==NULL)
 {
  return(temp);
 }
 NODE cur;
 cur=start;
 while(cur->link!=NULL)
 {
  cur=cur->link;
 }
 cur->link=temp;
 return(start);
}
NODE delete_rear(NODE start)
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
  start=NULL;
  return(start);
 }
 NODE prev;
 while(cur->link!=NULL)
 {
  prev=cur;
  cur=cur->link;
 }
 printf("\nThe deleted item is %d",cur->info);
 prev->link=NULL;
 freenode(cur);
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
  start=NULL;
  freenode(cur);
  return(start);
 }
 NODE cur2;
 cur2=cur->link;
 printf("\nThe deleted item is %d",cur->info);
 freenode(cur);
 return(cur2);
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
 int ch,item;
 NODE start;
 start=NULL;
 printf("\nMENU");
 printf("\n1.insert_front\n2.delete_front\n3.insert_rear\n4.delete_rear\n5.display\n6.exit");
 while(1)
 {
  printf("\nEnter your choice:");
  scanf("%d",&ch);
  switch(ch)
  {
   case 1:printf("\nEnter the item to be inserted:");
          scanf("%d",&item);
          start=insert_front(item,start);
          break;
   case 2:start=delete_front(start);
          break;
   case 3:printf("\nEnter the item to be inserted:");
          scanf("%d",&item);
          start=insert_rear(item,start);
          break;
   case 4:start=delete_rear(start);
          break;
   case 5:display(start);
          break;
   case 6:exit(0);
          break;
   default:printf("\nInvalid choice. Please enter a valid choice.");
  }
 }
 return 0;
}
