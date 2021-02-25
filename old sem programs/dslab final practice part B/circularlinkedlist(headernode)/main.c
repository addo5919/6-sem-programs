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
NODE insert_front(int item,NODE head)
{
 NODE temp;
 temp=getnode();
 temp->info=item;
 if(head->link==head)
 {
  head->link=temp;
  temp->link=head;
  return(head);
 }
 NODE cur;
 cur=head->link;
 head->link=temp;
 temp->link=cur;
 return(head);
}
NODE delete_front(NODE head)
{
 if(head->link==head)
 {
  printf("\nList is empty");
  return(head);
 }
 NODE cur;
 cur=head->link;
 if(cur->link==head)
 {
  printf("\nThe deleted item is %d",cur->info);
  head->link=head;
  freenode(cur);
  return(head);
 }
 printf("\nThe deleted item is %d",cur->info);
 head->link=cur->link;
 freenode(cur);
 return(head);
}
NODE insert_rear(int item,NODE head)
{
 NODE temp;
 temp=getnode();
 temp->info=item;
 temp->link=head;
 if(head->link==head)
 {
  head->link=temp;
  return(head);
 }
 NODE cur;
 cur=head->link;
 while(cur->link!=head)
 {
  cur=cur->link;
 }
 cur->link=temp;
 return(head);
}
NODE delete_rear(NODE head)
{
 if(head->link==head)
 {
  printf("\nList is empty");
  return(head);
 }
 NODE cur;
 cur=head->link;
 if(cur->link==head)
 {
  printf("\nThe deleted item is %d",cur->info);
  head->link=head;
  freenode(cur);
  return(head);
 }
 NODE prev;
 while(cur->link!=head)
 {
  prev=cur;
  cur=cur->link;
 }
 printf("\nThe deleted item is %d",cur->info);
 prev->link=head;
 freenode(cur);
 return(head);
}
void display(NODE head)
{
 if(head->link==head)
 {
  printf("\nList is empty");
  return;
 }
 NODE cur;
 cur=head->link;
 printf("\nThe elements of the linked list are:");
 while(cur!=head)
 {
  printf("%d\t",cur->info);
  cur=cur->link;
 }
}
int main()
{
 int ch,item;
 NODE head;
 head=getnode();
 head->info=0;
 head->link=head;
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


