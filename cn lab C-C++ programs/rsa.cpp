/*reference- 1. https://www.geeksforgeeks.org/modular-exponentiation-power-in-modular-arithmetic/ 
(for calculating (x^y)%p)
2.https://www.geeksforgeeks.org/rsa-algorithm-cryptography/ (for theory and little bit of code)
3. program in moodle or google drive 6th sem
*/
#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;

int gcd(int a,int b) //function to calculate gcd or hcf (for calculation of 'e')
{
    if(b==0)
      return a;
    else
      return gcd(b,a%b);
}

int power(int x,int y,int p) // for calculating (x^y) mod p
{
 int result=1;
 x=x%p; //if x>p
 if(x==0)
   return 0;
 
 while(y>0)
 {
   if(y%2==1) //if y is odd
   {
     result=(result*x)%p;
   }

   y=y/2;
   x=(x*x)%p;
 }
 
 return result;
}






int main()
{  
    int i;
    cout<<"\n"<<gcd(13,11);
    char message[30];
    int plaintext[30],ciphertext[30], dplaintext[30]; //dplaintext: plaintext obtained after decryption
    int n,p,q,phi_n,e,d; //phi_n:	Φ(n) (phi of n) eulers totient function

    cout<<"\nEnter two large prime no's:"; //n should be greater than or equal to 122
    cin>>p>>q;
    n=p*q; //simply calculated,no use
    
    phi_n=(p-1)*(q-1); //calculating phi_n

    /* now we have to find a number 'e' which is relatively prime to phi_n i.e.., gcd(e,phi_n)=1
    and 1<e<phi_n*/

    e=2; // let the value of e be 2 initially
    while(e<phi_n)                   // or for(e=2;e<phi_n;e++)
    {
        if(gcd(e,phi_n)==1)
          cout<<" "<<e;
          
          e++;
    }
    cout<<"\nChoose a value for e from above no's:";
    cin>>e;  
 
    // now we have to find a number 'd' such that e*d ≡ 1 mod Φ(n) i.e.., (e*d) mod Φ(n)=1

    d=2; //let the value of d be 2 initially
    while(d<phi_n)                 // or for(d=2;d<phi_n;d++)
    {
        if((e*d)%phi_n==1)
          break;
        else
          d++;
    }

    cout<<"\nPublic key: {"<<e<<","<<n<<"}"; //{e,n} represents public key
    cout<<"\nPrivate key: {"<<d<<","<<n<<"}"; //{d,n} represent private key
   
  /* Now that we have generated the public and the private key (obtained all the constants required 
for encryption-decryption process) , we can start encrypting and decrypting an input message or plaintext*/
    
    cout<<"\nEnter the plaintext(letters only):";
    cin>>message;
    cout<<"\nNumbers associated with each character of plaintext:-";
    for(i=0;i<strlen(message);i++)
    {
        plaintext[i]=message[i];
        cout<<"\n"<<(char)plaintext[i]<<" - "<<plaintext[i]; 
    }
    
    // forumula for getting ciphertext letters: C=M^e mod n (encryption)
    // forumula for getting plaintext letters: M=C^d mod n  (decryption)

    for(i=0;i<strlen(message);i++) //encryption C=M^e mod n
    {
       int C=power(plaintext[i],e,n);
       ciphertext[i]=C;
    }

     cout<<"\nNumbers associated with each character of ciphertext:-";
      for(i=0;i<strlen(message);i++)
    {
        cout<<"\n"<<(char)ciphertext[i]<<" - "<<ciphertext[i]; 
    }
    
    
  
   for(i=0;i<strlen(message);i++) //decryption M=C^d mod n
   {
       int M=power(ciphertext[i],d,n);
       dplaintext[i]=M;
       
   }
   
   cout<<"\nPlaintext obtained after decryption- ";
      for(i=0;i<strlen(message);i++)
    {
        cout<<"\n"<<(char)dplaintext[i]<<" - "<<dplaintext[i]; 
    }

   return 0;
}