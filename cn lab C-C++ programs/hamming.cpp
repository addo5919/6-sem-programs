//reference-http://campuscoke.blogspot.com/2015/01/hamming-code-program-in-c.html
#include<iostream>
#include<math.h>
using namespace std;

int messageb[30]; //for storing only message bits
int msgwithrb[30]; //for storing message bits along with redundant bits(this is the message that will be sent to receiver)

//calculate redundant bit value
int calculate_rbv(int position,int size)//size: size of message(m+nor)
{
  int count=0,i,j;//count: to count no of one's
  i=position-1; //-1 as array index starts at 0
  while(i<size)
  {
    for(j=i;j<i+position;j++)
    {
      if(msgwithrb[j]==1)
      count++;
    }
    i=i+2*position;
  }

  if(count%2==0) //if no of 1's is even then parity bit is set as zero
     return 0;
  else          //if no of 1's is odd then parity bit is set as 1( to make no of 1's even that is even parity)
     return 1;
}


int main()
{
    int m,i,j=0,k=0,nor=0,position=0,value=0,err_pos=0;//err_pos: error position
    cout<<"\nEnter the no of message bits:";
    cin>>m;
    cout<<"\nEnter the message bits:";
    for(i=0;i<m;i++)
    cin>>messageb[i];

  //finding no of redundant bits to be added (stored in variable i) according to formula 2**r>m+r+1
  //here this converted formula is used:- 2**r -(r+1)>m
    i=0; 
    while(m>(int)pow(2,i)-(i+1))
    {
        i++;
    }
    nor=i; //nor= no of redundant bits (to be added)
   
   /*since the no of redundant bits required has been found, we now know that the message that is sent
   to receiver (msgwithrb) will have m+nor bits*/

   //filling messagewithrb array with message bits and redundant bits
   //redudant bits are placed at power of 2 positions 
   //initially the redundant bits are set to 0, we will calculate them later
   for(i=0;i<m+nor;i++)
   {
     //if the current index is a power of 2 then put redundant bit in that position (with initial value 0)
     if(i==(int)pow(2,k)-1)//-1 as array indices start with 0
     {
       msgwithrb[i]=0;
       k++;
     }

     else
     {
       msgwithrb[i]=messageb[j];
       j++;
     }

   }

   //now we have have to find the value of each redundant bit and put it inside respective positions

   for(i=0;i<nor;i++)
   {
     position=(int)pow(2,i);
     value=calculate_rbv(position,m+nor);//value variable will either get 0 or 1
     msgwithrb[position-1]=value; //-1 as array index begins at 0
   }


   cout<<"\nThe message to be sent(message with redundant bits) is ";
   for(i=0;i<m+nor;i++)
   cout<<msgwithrb[i];
   

   cout<<"\nEnter the message that is received:";
   for(i=0;i<m+nor;i++)
   cin>>msgwithrb[i];

   for(i=0;i<nor;i++)
   {
     position=(int)pow(2,i);
     value=calculate_rbv(position,m+nor);
     if(value==1)
     err_pos+=position;
   }

   if(err_pos==0)
   {
     cout<<"\nMessage is received without errors";
   }
   
   else{
     cout<<"\nMessage is received with an error at bit position "<<err_pos;
   }

   //correcting single bit error
   if(msgwithrb[err_pos-1]==0)
      msgwithrb[err_pos-1]=1;
   else
      msgwithrb[err_pos-1]=0;

  cout<<"\nCorrected message is ";
   for(i=0;i<m+nor;i++)
   cout<<msgwithrb[i];

   return 0;
    
}
