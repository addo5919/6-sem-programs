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
 int i;
 char d[10];
 temp=getnode();
 temp->info=item;
 temp->lchild=NULL;
 temp->rchild=NULL;
 if(root==NULL)
 {
  return(temp);
 }
 printf("\nEnter the direction where you want to insert:");
 scanf("%s",d);
 toupper(d);
 cur=root;
 for(i=0;i<=strlen(d);i++)
 {
  if(cur==NULL)
  break;
  prev=cur;
  if(d[i]=='L')
  cur=cur->lchild;
  else
  cur=cur->rchild;
 }
 if(cur!=NULL||i!=strlen(d))
 {
  printf("\nInsertion is not possible");
  freenode(temp);
  return(root);
 }
 if(d[i-1]=='L')
 prev->lchild=temp;
 else
 prev->rchild=temp;
 return(root);
}
void preorder(NODE root)
{
 if(root==NULL)
 return;
 printf("%d\t",root->info);
 preorder(root->lchild);
 preorder(root->rchild);
}
void inorder(NODE root)
{
 if(root==NULL)
 return;
 inorder(root->lchild);
 printf("%d\t",root->info);
 inorder(root->rchild);
}
void postorder(NODE root)
{
 if(root==NULL)
 return;
 postorder(root->lchild);
 postorder(root->rchild);
 printf("%d\t",root->info);
}
int main()
{
 int item,ch;
 NODE root;
 root=NULL;
 printf("\nMENU");
 printf("\n1.insert\n2.preorder\n3.inorder\n4.postorder\n5.exit");
 while(1)
 {
  printf("\nEnter your choice:");
  scanf("%d",&ch);
  switch(ch)
  {
   case 1:printf("\nEnter the item to be inserted:");
          scanf("%d",&item);
          root=create(item,root);
          break;
   case 2:preorder(root);
          break;
   case 3:inorder(root);
          break;
   case 4:postorder(root);
          break;
   case 5:exit(0);
          break;
   default:printf("\nInvalid choice. Please enter a valid choice.");
  }
 }
 return 0;
}
