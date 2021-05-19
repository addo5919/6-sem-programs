//reference- lab program in moodle or lab manual present in 6th sem google drive

#include<iostream>
using namespace std;

struct packet { //each packet has a size and a arrival time
    int size;
    int at; //At every clock tick(1s), one packet is transmitted 
};

int main()
{
    struct packet packets[20];
    int bsize=250; //bucket size or maximum capacity or amount of free space left
    int outrate=25; //packet output rate (from leaky bucket) (represents size not no of packets)
    int rem=0; //size (total size) of packets still present inside bucket that have yet to be transmitted
    int j=0; //acts as index for packets array
    int n,i;  
    cout<<"\nEnter the no of packets(to be sent into leaky bucket):";
    cin>>n;

    for(i=0;i<n;i++)
    {
     cout<<"\nEnter the arrival time and size of packet "<<i+1<<":";
     cin>>packets[i].at>>packets[i].size;
    }

    /* Initially leaky bucket is empty. Let the leaky bucket receive packets for 30 seconds
    and send a packet out (output-constant rate) every 5 seconds (within those 30 seconds)*/
   /*packet is inserted into bucket only if its size is less than or equal to bucket size.
   If its size is greater than bucket size then it is rejected*/

    for(i=0;i<=30;i++) //this for loop represents 30 second timer
    {
        if(packets[j].at==i) //if packets arrival time matches the current time
        {  //either packet will be accepted or rejected entry to leaky bucket
           if(packets[j].size<=bsize) 
           {
               bsize=bsize-packets[j].size;
               rem=rem+packets[j].size;
               cout<<"\nAt time "<<i<<" packet "<<j+1<<" was inserted(received) into bucket";
               cout<<"\nRemaining space inside bucket is "<<bsize;
               j++;
               cout<<"\n";
           }
           else 
           {
               cout<<"\nAt time "<<i<<" packet "<<j+1<<" was rejected or discarded since the packet size is more than the size of the bucket";
               j++;
               cout<<"\n";
           }
        }

        if(i%5==0) //for every 5 seconds, send packets out of leaky bucket (constant rate)
        { //either rem is less than output rate or greater than output rate
            if(rem<outrate)
            {
                bsize=bsize+rem; //remaining free space increases
                
                cout<<"\nAt time "<<i<<" , "<<rem<<" KB has been sent out of leaky bucket";
                cout<<"\nRemaining space inside bucket is "<<bsize;
                rem=rem-rem; //0
                cout<<"\n";
            }
            else
            {
                bsize=bsize+outrate;
                rem=rem-outrate;
                cout<<"\nAt time "<<i<<" , "<<outrate<<" KB has been sent out of leaky bucket";//outrate=25
                cout<<"\nRemaining space inside bucket is "<<bsize;
                cout<<"\n";
            }

        }
    } //for loop close

    /*there might still be some packets remaining in leaky bucket. So we need to empty
    the leaky bucket i.e.., send all the remaining packets out of leaky bucket*/
    cout<<"\n";
    while(rem>0)
    { //either rem is less than outrate or greater than outrate
      if(rem<outrate) //same code as inside if(i%5==0)
            {
                bsize=bsize+rem; //remaining free space increases
                
                cout<<"\nAt time "<<i++<<" , "<<rem<<" KB has been sent out of leaky bucket";
                cout<<"\nRemaining space inside bucket is "<<bsize;
                rem=rem-rem; //0
                cout<<"\n";
            }
            else
            {
                bsize=bsize+outrate;
                rem=rem-outrate;
                cout<<"\nAt time "<<i++<<" , "<<outrate<<" KB has been sent out of leaky bucket";//or=25
                cout<<"\nRemaining space inside bucket is "<<bsize;
                cout<<"\n";
            }

    }
   
    cout<<"\nBucket is empty";
    return 0;

    }


