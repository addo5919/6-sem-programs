#include<stdio.h>
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
void push(NODE item)
{
 top++;
 s[top]=item;
}
NODE pop()
{
 NODE item;
 item=s[top];
 top--;
 return(item);
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
  case '$':
  case '^':return(pow(eval(root->lchild),eval(root->rchild)));
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
 NODE root;
 root=NULL;
 char exp[50];
 int ch;
 float res;
 printf("\nMENU");
 printf("\n1.insert postfix expression\n2.evaluate\n3.exit");
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
          printf("\nThe result of %s is %f",exp,res);
          break;
   case 3:exit(0);
          break;
   default:printf("\nInvalid choice. Please enter a valid choice.");
  }
 }
 return 0;
}


