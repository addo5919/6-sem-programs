#include <stdio.h>
#include <stdlib.h>
#include<string.h>
struct frame
{
 int no;           // Store only 3 characters of the string in each frame
 char arr[3];
}frames[20],frames2[20];

int main()
{
    char arr[20];
    char arr2[20];
    strcpy(arr2,"");
    printf("\nEnter the string:");
    gets(arr);
    int len=strlen(arr); //dividing the string into 3 parts, so divided by 3
    int nor=ceil(len/3); //nor=no of times for loop has to be repeated in order to store 3 characters of string
    int j;               //in a frame during each iteration
    for(j=0;j<nor;j++)
    {
     frames[j].no=j;
     frames[j].arr[0]=arr[3*j+0];
     frames[j].arr[1]=arr[3*j+1];
     frames[j].arr[2]=arr[3*j+2];
    }
    printf("\nBefore shuffling:-\n");
    for(j=0;j<nor;j++)
    {
     printf("frame no: %d, content: %s",frames[j].no,frames[j].arr);
     printf("\n");
    }

    int ord;
    printf("\nEnter the orders for shuffling:");
    for(j=0;j<nor;j++)
    {
     scanf("%d",&ord);
     frames2[j]=frames[ord];
    }

   printf("\nAfter shuffling:-\n");
   for(j=0;j<nor;j++)
    {
     printf("frame no: %d, content: %s",frames2[j].no,frames2[j].arr);
     printf("\n");
    }

    struct frame temp;
    int i;
    for(i=0;i<nor-1;i++)
    for(j=0;j<nor-1-i;j++)
    {
     if(frames2[j].no>frames2[j+1].no) // sorting the no's of frames2
     {
      temp=frames2[j];
      frames2[j]=frames2[j+1];
      frames2[j+1]=temp;
     }
    }


   printf("\nAfter sorting:-\n");
   for(j=0;j<nor;j++)
    {
     printf("frame no: %d, content: %s",frames2[j].no,frames2[j].arr);
     printf("\n");
     strcat(arr2,frames2[j].arr);
    }
    printf("\n");
    printf("Message at reciever side: ");
    puts(arr2);
    return 0;

}
