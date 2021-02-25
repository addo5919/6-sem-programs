#include<stdio.h>
struct node
{
 int id;
 char name[20];
 int sem;
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
NODE insert(int id,char name[20],int sem,NODE start)
{
 NODE temp;
 temp=getnode();
 temp->id=id;
 strcpy(temp->name,name);
 temp->sem=sem;
 int pos,i;
 printf("\nEnter the position where you want to insert:");
 scanf("%d",&pos);

//incorrect position checker
 NODE cur;
 cur=start;
 int count=0;
 while(cur!=NULL)
 {
  count++;
  cur=cur->link;
 }
 if((pos>count)&&(pos!=(count+1)))
 {
  printf("\nPostion not available or exceeded");
  freenode(temp);
  return(start);
 }
//end

 if(pos==1)
 {
  temp->link=start;
  return(temp);
 }
 NODE temp2;
 temp2=start;
 for(i=0;i<(pos-2);i++)
 temp2=temp2->link;
 temp->link=temp2->link;
 temp2->link=temp;
 return(start);
}
NODE delete_front(NODE start)
{
 if(start==NULL)
 {
  printf("\nList is empty");
  return(start);
 }
 NODE cur;
 cur=start;
 if(cur->link==NULL)
 {
  printf("\nThe deleted student details are as follows:-");
  printf("\nid:%d",cur->id);
  printf("\nname:%s",cur->name);
  printf("\nsem:%d",cur->sem);
  freenode(cur);
  return(NULL);
 }
  printf("\nThe deleted student details are as follows:-");
  printf("\nid:%d",cur->id);
  printf("\nname:%s",cur->name);
  printf("\nsem:%d",cur->sem);
  start=cur->link;
  freenode(cur);
  return(start);
}
void display(NODE start)
{
 int i=1;
 if(start==NULL)
 {
  printf("\nList is empty");
  return;
 }
 NODE cur;
 cur=start;
 while(cur!=NULL)
 {
  printf("\nThe details of student %d are as follows:-",i);
  printf("\nid:%d",cur->id);
  printf("\nname:%s",cur->name);
  printf("\nsem:%d",cur->sem);
  cur=cur->link;
  i++;
 }
}
int main()
{
 int sem,id,ch;
 char name[20];
 NODE start;
 start=NULL;
 printf("\nMENU");
 printf("\n1.insert student details at specified position\n2.delete student details from the front\n3.display all student details\n4.exit");
 while(1)
 {
  printf("\nEnter your choice:");
  scanf("%d",&ch);
  switch(ch)
  {
   case 1:printf("\nEnter the student's id no:");
          scanf("%d",&id);
          printf("\nEnter the name of the student:");
          scanf("%s",name);
          printf("\nEnter the semester which the student is currently in:");
          scanf("%d",&sem);
          start=insert(id,name,sem,start);
          break;
   case 2:start=delete_front(start);
          break;
   case 3:display(start);
          break;
   case 4:exit(0);
          break;
   default:printf("\nInvalid choice. Please enter a valid choice.");
  }
 }
 return 0;
}
