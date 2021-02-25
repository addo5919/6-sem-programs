#include<stdio.h>
#define max 50
char s[max];
int top=-1;
void push(char item)
{
 if(top==max-1)
 {
  printf("\nStack is full. Program terminated");
  exit(0);
 }
 else
 {
  top++;
  s[top]=item;
 }
}
char pop()
{
 char item;
 item=s[top];
 top--;
 return(item);
}
int priority(char item)
{
 if(item=='(')
 return(0);
 if(item=='+'||item=='-')
 return(1);
 if(item=='*'||item=='/')
 return(2);
 if(item=='$'||item=='^')
 return(3);
}
int main()
{
 char item;
 char exp[50],*e;
 printf("\nEnter the infix expression:");
 scanf("%s",exp);
 e=&exp[0];
 printf("\nThe postfix expression is ");
 while(*e!='\0')
 {
  if(isalnum(*e))
  printf("%c",*e);
  else if(*e=='(')
  push(*e);
  else if(*e==')')
  {
   while((item=pop())!='(')
   printf("%c",item);
  }
  else
  {
   while(priority(s[top])>=priority(*e))
   printf("%c",pop());
   push(*e);
  }
  e++;
 }
 while(top!=-1)
 {
  printf("%c",pop());
 }
 return 0;
}
