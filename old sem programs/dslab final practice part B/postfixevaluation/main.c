#include<stdio.h>
#define max 50
float s[max];
int top=-1;
void push(float item)
{
 if(top==max-1)
 {
  printf("\nError stack overflow, program terminated");
  exit(0);
 }
 else
 {
  top++;
  s[top]=item;
 }
}
float pop()
{
 float item;
 item=s[top];
 top--;
 return(item);
}
int main()
{
 char exp[50],*e;
 float item,res,op1,op2;
 printf("\nEnter the postfix expression to be evaluated:");
 scanf("%s",exp);
 e=&exp[0];
 while(*e!='\0')
 {
  if(isdigit(*e))
  {
   item=*e-'0';
   push(item);
  }
  else
  {
   op2=pop();
   op1=pop();
   switch(*e)
   {
    case '+':res=op1+op2;
             break;
    case '-':res=op1-op2;
             break;
    case '/':res=op1/op2;
             break;
    case '*':res=op1*op2;
             break;
    case '^':
    case '$':res=pow(op1,op2);
             break;
    default:printf("\nInvalid symbol. Program terminated");
            exit(0);
   }
   push(res);
  }
  e++;
 }
 printf("\nThe result of %s is %f",exp,pop());
 return 0;
}

