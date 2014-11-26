#include<iostream>
#include<algorithm>
using namespace std;

//http://condor.depaul.edu/rjohnson/algorithm/coins.pdf
const int MAX = 200;
const int debug = 1;
void dynamic_coin_change(int denom[],int n, int A , int c[][MAX], int used[][MAX])
{

    for (int  j = 0 ; j<= A; j++)
    {

        c[n][j] = j;
        used [n][j] = 1; 
    }
    for (int  i =n - 1 ; i>0; i--)
    {

        for ( int j = 0 ; j<= A ; j++)
        {

            if( denom[i-1] > j || c[i + 1 ][j] < 1 + c[i ][j - denom[i - 1]])
            {

                c[i][j] = c[i + 1][j];
                used[i][j] = used[i+1][j];


            }
            else
            {
            c[i][j] = 1 + c[i ][j - denom[i -1]];
            cout<<"denom taken for j: "<<j<<" "<<denom[i - 1]<<endl;
            //used[i][j] = true;
            used[i][j] = 1 + used[i][ j - denom[ i -1 ]];
            }
        }


    }

}

void optimal_coins_set( int i , int j, int denom[] , int count[], int used[][MAX])
{

    if( j == 0)
    {
        return ;
    }
    if ( used[i][j] ) 
    {

        count[i] = count[i] + 1;
        if(debug)
        cout<<"used a coin of denomination:"<<denom[i - 1]<<endl;
        optimal_coins_set(i,j - denom[i - 1] , denom,count , used);

    }
    else
    {
        optimal_coins_set( i + 1 , j , denom , count , used);

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
        int c[MAX][MAX];
        int used[MAX][MAX];
        cin>>n>>A;
        denom[0] = 0;
        for ( int j = 1 ; j<=n;j++)
        {

            cin>>denom[j];

        }
        std::sort(std::begin(denom ) ,std::end(denom ), [](int a, int b){  return b < a;  });
        dynamic_coin_change( denom, n,  A ,  c,  used);
        if(debug)
        {
        print_matrix(c,n,A);
        cout<<"********\n";
        print_matrix(used,n,A);
        }
        int count[MAX];
        for (int j = 1;j<=n ; j ++) 
        {

            count[j] = 0;
        }
        //optimal_coins_set( 1, A,  denom ,  count,  used);
        cout<<"Case #"<<i<<": ";
        for (int j = n ;j>0 ; j --) 
        {

            cout<<count[j]<<" " ;
        }
        cout<<endl;

    }

    return 0;
}
