#include <iostream>
#include<string.h>

using namespace std;

int main()
{  //Sender side
  cout<<"\nAt Sender side:";
  int i,j;
  char message[20],generator[20];
  cout<<"\nEnter the message bits:";
  cin>>message;
  cout<<"\nEnter the generator(divisor):";
  cin>>generator;
  int data[strlen(message)+strlen(generator)-1],divisor[strlen(generator)];
  for(i=0;i<(sizeof(data)/sizeof(int));i++)
    data[i]=0;

  for(i=0;i<strlen(message);i++)
  {
    data[i]=message[i]-'0'; // -'0' for converting character to integer

  }
  for(i=0;i<strlen(generator);i++)
  {
    divisor[i]=generator[i]-'0';

  }

  for(int i=0;i<strlen(message);i++)
  {
    if(data[i]==1)
    {
        for(int j=0;j<(sizeof(divisor)/sizeof(int));j++)
         data[i+j]^=divisor[j];

    }
  }

  cout<<"\nThe checksum code(sent data) is: ";
for(i=0;i<strlen(message);i++)
	data[i] = message[i]-'0';
for(i=0;i<(sizeof(data)/sizeof(int));i++)
    cout<<data[i];
cout<<"\n";


//Reciever side
cout<<"\nAt receiver side";
cout<<"\nEnter checksum code(received data): ";
	cin>>message;
cout<<"\nEnter generator: ";
	cin>>generator;

int data2[strlen(message)+strlen(generator)-1],divisor2[strlen(generator)];
for(i=0;i<sizeof(data2)/sizeof(int);i++)
    data2[i]=0;

for(i=0;i<strlen(message);i++)
	data2[i]=message[i]-'0';
for(i=0;i<strlen(generator);i++)
	divisor2[i]=generator[i]-'0';

//Calculation of remainder
for(i=0;i<strlen(message);i++) {
	if(data2[i]==1)
		for(j=0;j<(sizeof(divisor2)/sizeof(int));j++)
			data2[i+j] ^= divisor2[j];
}

//Display validity of data
int flag=1;  //at this point data2 contains remainder
for(int i=0;i<(sizeof(data2)/sizeof(int));i++)
	if(data2[i]==1){
		flag=0;
		break;
}

if(flag==1)
	cout<<"Message received successfully"; //remainder was zero
else
	cout<<"Message not received correctly! CRC error occurred!"; //remainder was not zero

return 0;
}

