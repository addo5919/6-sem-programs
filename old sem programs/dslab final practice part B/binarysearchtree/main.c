#include<stdio.h>
struct node
{
 struct node *lchild;
 int info;
 struct node *rchild;
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
NODE create(int item,NODE root)
{
 NODE temp,prev,cur;
 temp=getnode();
 temp->info=item;
 temp->lchild=NULL;
 temp->rchild=NULL;
 if(root==NULL)
 {
  return(temp);
 }
 cur=root;
 while(cur!=NULL)
 {
  prev=cur;
  if(item==cur->info)
  {
   printf("\nDuplicate!");
   freenode(temp);
   return(root);
  }
  if(item<cur->info)
  cur=cur->lchild;
  else
  cur=cur->rchild;
 }
 if(item<prev->info)
 prev->lchild=temp;
 else
 prev->rchild=temp;
 return(root);
}
void inorder(NODE root)
{
 if(root==NULL)
 return;
 inorder(root->lchild);
 printf("%d\t",root->info);
 inorder(root->rchild);
}
void search(int item,NODE root)
{
 if(root==NULL)
 {
  printf("\nTree does not exist");
  return;
 }
 NODE cur;
 cur=root;
 while(cur!=NULL)
 {
  if(item==cur->info)
  break;
  if(item<cur->info)
  cur=cur->lchild;
  else
  cur=cur->rchild;
 }
 if(cur==NULL)
 printf("\nKey not found");
 else
 printf("\nKey found");
}
void max(NODE root)
{
 if(root==NULL)
 {
  printf("\nTree does not exist");
  return;
 }
 NODE cur;
 cur=root;
 while(cur->rchild!=NULL)
 {
  cur=cur->rchild;
 }
 printf("\nThe greatest or maximum element is %d",cur->info);
}
int main()
{
 int ch,item;
 NODE root;
 root=NULL;
 printf("\nMENU");
 printf("\n1.insert\n2.inorder\n3.search\n4.find max\n5.exit");
 while(1)
 {
  printf("\nEnter your choice:");
  scanf("%d",&ch);
  switch(ch)
  {
   case 1: printf("\nEnter the item to be inserted:");
           scanf("%d",&item);
           root=create(item,root);
           break;
   case 2: inorder(root);
           break;
   case 3: printf("\nEnter the item to be searched for:");
           scanf("%d",&item);
           search(item,root);
           break;
   case 4: max(root);
           break;
   case 5: exit(0);
           break;
   default: printf("\nInvalid choice. Please enter a valid choice.");
  }
 }
 return 0;
}

