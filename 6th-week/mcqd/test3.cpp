#include<iostream>

using namespace std;

int main()
{
    int l, n,m;
    int range_n;
    int range_m;
    cin>>n>>m;
    //cin>>range_n;
    //cin>>range_m;
cout<<1<<endl;
cout<<n<<" "<<m<<endl;
for(int i =0;i<m;i++)
{

int a = rand() % n + 1;
int b = rand() % n + 1;
int c = rand() % 10000 + 1;
cout<<a<<" "<<b<<endl;
}
    
return 0;

}
