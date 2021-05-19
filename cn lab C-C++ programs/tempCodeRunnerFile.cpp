#include<iostream>
using namespace std;

int gcd(int a,int b) //function to calculate gcd or hcf (for calculation of 'e')
{
    if(b==0)
    return a;
    else
    gcd(b,a%b);
}

int main()
{
    char plaintext[30],ciphertext[30];
    int p,n,phi_n,e,d; //phi_n:	Φ(n) (phi of n) eulers totient function

    cout<<"\nEnter two small prime no's:";
    cin>>p>>q;
    
    phi_n=(p-1)*(q-1); //calculating phi_n

    /* now we have to find a number 'e' which is relatively prime to phi_n i.e.., gcd(e,phi_n)=1
    and 1<e<phi_n*/

    e=2; // let the value of e be 2 initially
    while(e<phi_n)                   // or for(e=2;e<phi_n;e++)
    {
        if(gcd(e,phi_n)==1)
          break;
        else
          e++;
    }

    // now we have to find a number 'd' such that e*d ≡ 1 mod Φ(n) i.e.., (e*d) mod Φ(n)=1

    d=2; //let the value of d be 2 initially
    while(d<phi_n)
    {
        if((e*d)%phi_n==1)
          break;
        else
          d++;
    }



}