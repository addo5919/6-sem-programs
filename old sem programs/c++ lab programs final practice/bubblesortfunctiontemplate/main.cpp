#include<iostream>
using namespace std;
template<class X>
void bubble(X a[100],int n)
{
 int i,j;
 for(i=1;i<n;i++)
 for(j=0;j<n-i;j++)
 {
  if(a[j]>a[j+1])
  {
   X temp;
   temp=a[j];
   a[j]=a[j+1];
   a[j+1]=temp;
  }
 }
}
int main()
{
 int a[100];
 float b[100];
 int n,i;
 cout<<"\nEnter the no of elements in the array:";
 cin>>n;
 cout<<"\nEnter the elements of integer array:";
 for(i=0;i<n;i++)
 cin>>a[i];
 cout<<"\nEnter the elements of float array:";
 for(i=0;i<n;i++)
 cin>>b[i];
 cout<<"\nBefore sorting";
 cout<<"\nInteger array:";
 for(i=0;i<n;i++)
 cout<<"\t"<<a[i];
 cout<<"\nFloat array:";
 for(i=0;i<n;i++)
 cout<<"\t"<<b[i];
 bubble(a,n);
 bubble(b,n);
 cout<<"\nAfter sorting";
 cout<<"\nInteger array:";
 for(i=0;i<n;i++)
 cout<<"\t"<<a[i];
 cout<<"\nFloat array:";
 for(i=0;i<n;i++)
 cout<<"\t"<<b[i];
 return 0;
}

