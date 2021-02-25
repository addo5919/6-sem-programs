#include<stdio.h>
#define max 5
struct stack
{
 int s[max];
 int top;
};
void push(struct stack *s,int item)
{
 if(s->top==max-1)
 printf("\nStack is full(overflow)");
 else
 {
  (s->top)++;
  s->s[s->top]=item;
 }
}
void pop(struct stack *s)
{
 if(s->top==-1)
 printf("\nStack is empty(underflow)");
 else
 {
  int item;
  item=s->s[s->top];
  printf("\nThe deleted item is %d",item);
  (s->top)--;
 }
}
void display(struct stack *s)
{
 if(s->top==-1)
 printf("\nStack is empty");
 else
 {
  int i;
  printf("\nThe elements of the stack are:");
  for(i=0;i<=(s->top);i++)
  printf("%d\t",s->s[i]);
 }
}
int main()
{
 struct stack s;
 s.top=-1;
 int ch,item;
 printf("\nMENU");
 printf("\n1.push\n2.pop\n3.display\n4.exit");
 while(1)
 {
  printf("\nEnter your choice:");
  scanf("%d",&ch);
  switch(ch)
  {
   case 1: printf("\nEnter the item to be inserted:");
           scanf("%d",&item);
           push(&s,item);
           break;
   case 2: pop(&s);
           break;
   case 3: display(&s);
           break;
   case 4: exit(0);
           break;
   default: printf("\nInvalid choice. Please enter a valid choice.");
  }
 }
 return 0;
}
