#include<stdio.h>
#define max 20
int top=-1;
char s[max];
void push(char item)
{
 if(top==max-1)
 {
  printf("\nStack is full");
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
int main()
{
 char exp[20];
 int i,n,count=0;
 printf("\nEnter the string:");
 scanf("%s",exp);
 n=strlen(exp);
 for(i=0;i<n;i++)
 push(exp[i]);
 for(i=0;i<n;i++)
 {
  if(exp[i]==pop())
  count++;
 }
 if(count==n)
 printf("\nThe entered string is palindrome");
 else
 printf("\nThe entered string is not palindrome");
 return 0;
}
