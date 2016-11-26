#include<iostream>
using namespace std;



long int gcd_iter(long int u,long  int v) {
  long   int t;
    while (v) {
        t = u; 
        u = v; 
        v = t % v;
    }
    return u < 0 ? -u : u; /* abs(u) */
}

int main()
{

int t;
cin>>t;
for(int i = 1 ; i<=t; i++)
{
long int a, b, c;
cin>>a>>b;
c = gcd_iter(a,b);
cout<<"Case #"<<i<<": "<<c<<endl;

}
    return 0;
}
