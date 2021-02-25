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
 if(head->rlink==NULL)
 {
  head->rlink=temp;
  temp->llink=head;
  temp->rlink=NULL;
  return(head);
 }
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
 temp->rlink=NULL;
 if(head->rlink==NULL)
 {
  head->rlink=temp;
  temp->llink=head;
  return(head);
 }
 NODE cur;
 cur=head->rlink;
 while(cur->rlink!=NULL)
 {
  cur=cur->rlink;
 }
 cur->rlink=temp;
 temp->llink=cur;
 return(head);
}
NODE delete_front(NODE head)
{
 if(head->rlink==NULL)
 {
  printf("\nList is empty");
  return(head);
 }
 NODE cur;
 cur=head->rlink;
 if(cur->rlink==NULL)
 {
  printf("\nThe deleted item is %d",cur->info);
  head->rlink=NULL;
  freenode(cur);
  return(head);
 }
 printf("\nThe deleted item is %d",cur->info);
 head->rlink=cur->rlink;
 freenode(cur);
 return(head);
}
NODE delete_rear(NODE head)
{
 if(head->rlink==NULL)
 {
  printf("\nList is empty");
  return(head);
 }
 NODE cur;
 cur=head->rlink;
 if(cur->rlink==NULL)
 {
  printf("\nThe deleted item is %d",cur->info);
  head->rlink=NULL;
  freenode(cur);
  return(head);
 }
 NODE prev;
 while(cur->rlink!=NULL)
 {
  prev=cur;
  cur=cur->rlink;
 }
 printf("\nThe deleted item is %d",cur->info);
 prev->rlink=NULL;
 freenode(cur);
 return(head);
}
void display(NODE head)
{
 if(head->rlink==NULL)
 {
  printf("\nList is empty");
  return;
 }
  NODE cur;
  cur=head->rlink;
  printf("\nThe elements of the linked list are:");
  while(cur!=NULL)
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
 head->llink=NULL;
 head->rlink=NULL;
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
   case 5:display(head);
          break;
   case 6:exit(0);
          break;
   default:printf("\nInvalid choice. Please enter a valid choice.");
  }
 }
 return 0;
}




