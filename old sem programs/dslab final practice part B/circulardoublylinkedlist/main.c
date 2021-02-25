#include<stdio.h>
struct node
{
 int info;
 struct node *llink;
 struct node *rlink;
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
NODE insert_front(int item,NODE head)
{
 NODE temp;
 temp=getnode();
 temp->info=item;
 NODE cur;
 cur=head->rlink;
 head->rlink=temp;
 temp->llink=head;
 temp->rlink=cur;
 cur->llink=temp;
 return(head);
}
NODE insert_rear(int item,NODE head)
{
 NODE temp;
 temp=getnode();
 temp->info=item;
 NODE cur;
 cur=head->llink;
 cur->rlink=temp;
 temp->llink=cur;
 temp->rlink=head;
 head->llink=temp;
 return(head);
}
NODE delete_front(NODE head)
{
 if(head->rlink==head)
 {
  printf("\nList is empty");
  return(head);
 }
 NODE cur;
 cur=head->rlink;
 printf("\nThe deleted item is %d",cur->info);
 head->rlink=cur->rlink;
 freenode(cur);
 return(head);
}
NODE delete_rear(NODE head)
{
 if(head->rlink==head)
 {
  printf("\nList is empty");
  return(head);
 }
 NODE cur;
 cur=head->llink;
 NODE prev;
 prev=cur->llink;
 prev->rlink=head;
 head->llink=prev;
 printf("\nThe deleted item is %d",cur->info);
 freenode(cur);
 return(head);
}
NODE insert_right(int item,NODE head)
{
 NODE temp;
 temp=getnode();
 temp->info=item;
 if(head->rlink==head)
 {
  head->rlink=temp;
  head->llink=temp;
  temp->llink=head;
  temp->rlink=head;
  return(head);
 }
 int key;
 printf("\nEnter the info part of the node after which you want to insert a new node:");
 scanf("%d",&key);
 NODE cur;
 cur=head->rlink;
 while(cur!=head)
 {
  if(key==cur->info)
  break;
  else
  cur=cur->rlink;
 }
 if(cur==head)
 {
  printf("\nKey not found");
  return(head);
 }
 else
 {
  if(cur->rlink==head)
  {
   cur->rlink=temp;
   temp->llink=cur;
   temp->rlink=head;
   head->llink=temp;
   return(head);
  }
  else
  {
   NODE cur2;
   cur2=cur->rlink;
   temp->llink=cur;
   temp->rlink=cur2;
   cur->rlink=temp;
   cur2->llink=temp;
   return(head);
  }
 }
}
void display(NODE head)
{
 if(head->rlink==head)
 {
  printf("\nList is empty");
  return;
 }
  NODE cur;
  cur=head->rlink;
  printf("\nThe elements of the linked list are:");
  while(cur!=head)
  {
   printf("%d\t",cur->info);
   cur=cur->rlink;
  }
}
int main()
{
 int ch,item;
 NODE head;
 head=getnode();
 head->info=0;
 head->llink=head;
 head->rlink=head;
 printf("\nMENU");
 printf("\n1.insert_front\n2.delete_front\n3.insert_rear\n4.delete_rear\n5.insert_right\n6.display\n7.exit");
 while(1)
 {
  printf("\nEnter your choice:");
  scanf("%d",&ch);
  switch(ch)
  {
   case 1:printf("\nEnter the item to be inserted:");
          scanf("%d",&item);
          head=insert_front(item,head);
          break;
   case 2:head=delete_front(head);
          break;
   case 3:printf("\nEnter the item to be inserted:");
          scanf("%d",&item);
          head=insert_rear(item,head);
          break;
   case 4:head=delete_rear(head);
          break;
   case 5:printf("\nEnter the item to be inserted:");
          scanf("%d",&item);
          head=insert_right(item,head);
          break;
   case 6:display(head);
          break;
   case 7:exit(0);
          break;
   default:printf("\nInvalid choice. Please enter a valid choice.");
  }
 }
 return 0;
}
