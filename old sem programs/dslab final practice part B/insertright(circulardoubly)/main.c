#include<stdio.h>
struct node
{
 struct node *llink;
 int info;
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
 printf("\nEnter the info part of the node after which you want to insert the new node:");
 scanf("%d",&key);
 NODE cur;
 cur=head->rlink;
 while(cur!=head)
 {
  if(key==cur->info)
  break;
  cur=cur->rlink;
 }
 if(cur==head)
 {
  printf("\nNode with entered info field is not found");
  freenode(temp);
  return(head);
 }
 else if(cur->rlink==head)
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
 NODE head;
 head=getnode();
 head->info=0;
 head->llink=head;
 head->rlink=head;
 int ch,item;
 printf("\nMENU");
 printf("\n1.insert_right\n2.display\n3.exit");
 while(1)
 {
  printf("\nEnter your choice:");
  scanf("%d",&ch);
  switch(ch)
  {
   case 1: printf("\nEnter the item to be inserted:");
           scanf("%d",&item);
           head=insert_right(item,head);
           break;
   case 2: display(head);
           break;
   case 3: exit(0);
           break;
   default:printf("\nInvalid choice. Please enter a valid choice.");
  }
 }
 return 0;
}
