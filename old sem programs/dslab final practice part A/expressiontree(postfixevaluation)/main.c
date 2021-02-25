#include<stdio.h>
#include<math.h>
struct node
{
 struct node *lchild;
 char info;
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
NODE s[50];
int top=-1;
void push(NODE temp)
{
 top++;
 s[top]=temp;
}
NODE pop()
{
 NODE temp;
 temp=s[top];
 top--;
 return(temp);
}
NODE create(char exp[50])
{
 NODE temp;
 int i;
 char sym;
 for(i=0;exp[i]!='\0';i++)
 {
  sym=exp[i];
  temp=getnode();
  temp->info=sym;
  temp->lchild=NULL;
  temp->rchild=NULL;
  if(isalnum(sym))
  push(temp);
  else
  {
   temp->rchild=pop();
   temp->lchild=pop();
   push(temp);
  }
 }
 return(pop());
}
 float eval(NODE root)
{
 float num;
 switch(root->info)
 {
  case '+':return(eval(root->lchild)+eval(root->rchild));
  case '-':return(eval(root->lchild)-eval(root->rchild));
  case '*':return(eval(root->lchild)*eval(root->rchild));
  case '/':return(eval(root->lchild)/eval(root->rchild));
  case '^':
  case '$':return(pow(eval(root->lchild),eval(root->rchild)));
  default:
  if(isalpha(root->info))
  {
   printf("%c:",root->info);
   scanf("%f",&num);
   return(num);
  }
  else
  return(root->info-'0');
 }
}
int main()
{
 float res;
 int ch;
 char exp[50];
 NODE root;
 root=NULL;
 printf("\nMENU");
 printf("\n1.create expression tree\n2.evaluate tree\n3.exit");
 while(1)
 {
  printf("\nEnter your choice:");
  scanf("%d",&ch);
  switch(ch)
  {
   case 1:printf("\nEnter the postfix expression:");
          scanf("%s",exp);
          root=create(exp);
          break;
   case 2:res=eval(root);
          printf("\nThe result is %f",res);
          break;
   case 3:exit(0);
          break;
   default:printf("\nInvalid choice. Please enter a valid choice.");
  }
 }
 return 0;
}

