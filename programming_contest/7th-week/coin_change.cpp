#include<iostream>
#include<algorithm>
using namespace std;

//http://condor.depaul.edu/rjohnson/algorithm/coins.pdf
const int MAX = 200;
const long int SIZE = 1000004;
const int debug = 0;
const long int INF = 100000000; 

void dynamic_coin_change(int d[],int n, int A , int c[], int used[],int count[])
{
int coin;
    c[0] = 0;
    for ( int p = 1 ; p<=A;p++)
    {

        int min = INF;
        for ( int i = 1;i<=n ; i++)
        {

            if( d[i] <= p)
            {

                if( 1 + c[p - d[i]] < min)
                {

                    min = 1 + c[ p - d[i]];
                    coin = i;

                }


            }
c[p] = min;
used[p] = coin;
//count[used[p]] = used[p];
        }

    }

}

void optimal_coins_set( int n,int d[] , int count[], int used[])
{

while( n > 0)
{
if(debug)
{
    cout<<"optimal sol: "<<used[n]<<' '<<d[used[n]]<<endl;
}
count[used[n]]++;
n = n - d[used[n]];
}
}

void print_matrix( int c [][MAX], int n, int A )
{

    for ( int i = 0 ; i<=n ; i++)
    {

        for( int j = 0;j<=A; j++)
        {
            cout<<c[i][j]<<" ";

        }

        cout<<endl;


    }
}
int main ()
{

    int t;
    cin>>t;
    for ( int i = 1;i<=t;i++)
    {

        int n,A;
        int denom[MAX];
        int c[SIZE];
        int used[SIZE];
       // denom.push_back(0);
        cin>>n>>A;
        for ( int j = 1 ; j<=n;j++)
        {
            cin>>denom[j];

        }
        //std::sort(denom  ,std::end(denom ), [](int a, int b){  return b < a;  });
        int count[MAX]={0};
        dynamic_coin_change( denom, n,  A ,  c,  used,count);
        if(debug)
        {
           // print_matrix(c,n,A);
            cout<<"********\n";
            //print_matrix(used,n,A);
        }
               optimal_coins_set(  A,  denom ,  count,  used);
        cout<<"Case #"<<i<<": ";
        for (int j = 1 ;j<=n ; j ++) 
        {

            cout<<count[j]<<" " ;
        }
        cout<<endl;

    }

    return 0;
}
