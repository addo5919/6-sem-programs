#include<iostream>
using namespace std;
int main()
{
    int n,i,j,ind,val,count=0;
    int generator[17]={1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1}; //17 bit generator polynomial
    cout<<"\nEnter the size of the message:";
    cin>>n;
    int message[n+16],messagec[n+16];
        
    cout<<"\nEnter the message:";
    for(i=0;i<n;i++)
    {
        cin>>message[i];
        messagec[i]=message[i];
    }
 
    for(i=n;i<(n+16);i++) //adding (17-1)=16 0's to the end of message.
    {
        message[i]=0;
        messagec[i]=0;
    }
    
    cout<<"\nMessage:";
      for(i=0;i<n;i++)
    {
        cout<<message[i];
    }

    cout<<"\nMessage after adding crc bits( 16 0's) at end:";
    for(i=0;i<(n+16);i++)
    {
        cout<<message[i];
    }
    
    cout<<"\nGenerator:";
    for(i=0;i<17;i++)
    {
        cout<<generator[i];
    }
  
    //calculation of remainder (bits to be appended to message)
    for(i=0;i<n;i++)
    {
        if(message[i]==1)
        {
            for(j=0;j<17;j++) //17= length of generator
            message[i+j]=message[i+j]^generator[j];
        }
    }
    
    cout<<"\nRemainder:-";
    for(i=0;i<(n+16);i++)
    {
        cout<<message[i];
    }

    //obtaining message with remainder appended to it(crc bits)
    for(i=0;i<n;i++)
    {
        message[i]=messagec[i];
    }
    
    cout<<"\nMessage after appending crc bits(remainder) to it :";
    for(i=0;i<(n+16);i++)
    {
        cout<<message[i];
    }

    /*now we have to divide this by generator again. If the message is unchanged then the remainder will be zero otherwise
      remainder will be non-zero*/

      cout<<"\nEnter the index position of message you want to change( type in a negative no if you dont want to change):";
      cin>>ind;
      if(ind>=0)
      {
          cout<<"\nEnter the value(0 or 1):";
          cin>>val;
          message[ind]=val;
          
          cout<<"\nMessage after change of bit:";
          for(i=0;i<(n+16);i++)
          {
            cout<<message[i];
          }
      }


      //division
      for(i=0;i<n;i++)
    {
        if(message[i]==1)
        {
            for(j=0;j<17;j++) //17= length of generator
            message[i+j]=message[i+j]^generator[j];
        }
    }

    cout<<"\nRemainder:-";
    for(i=0;i<(n+16);i++)
    {
        cout<<message[i];
    }

        //checking if message was recieved succesfully( remainder 0 ) or unsuccesully( non zero remainder)

        
        for(i=0;i<(n+16);i++)
        {
            if(message[i]==0)
            count++;
        }
        
        if(count==(n+16))
        {
            cout<<"\nMessage has been received successfully";
        }
        else
        {
            cout<<"\nMessage has been received with errors.(due to change in value of one or more bit positions).";
        }

   

    return 0;
    
}