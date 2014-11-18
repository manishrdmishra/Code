#include<iostream>
#include<cmath>

using namespace std;

const int MAX = 30;
class Nqueen {

    public:
        bool place(int k, int i);
        bool nqueen(int k , int n);

    
        void printRow();
        int n;
        int x[MAX];
};
void Nqueen::printRow()
{
    for( int i = 1;i<=n;i++)
    {
        cout<<"i: "<<x[i]<<endl;

    }

}
bool Nqueen::place (int k, int i)
{


    for (int j = 1;j<=n;j++)
    {

        // cout<<"k:i  "<<k<<"  "<<i<<endl;
        if( x[j] == 0)
        {
            continue;
        }
        if ((x[j] == i ) || ( abs( x[j] - i ) == abs( j - k)))
        {
            //    cout<<x[j] - i<<" "<< j - k<<endl;
            return false;
        }

    }

    return true;
}

bool Nqueen::nqueen(int k, int n)
{

    if(k > n) 
    {
        return true;
    }

    for(int i = 1; i<=n;i++)
    {

        if( x[k] != 0)
        {
            // nqueen(k + 1 , n);
            if(  nqueen( k + 1 , n) ==  true)
            {
                return true;
            }

        }
        else if( place(k,i))
        {
            x[k] = i;
            if( nqueen( k + 1 , n) == true )
            {
                return true;

            }
            x[k] = 0;

        }

    }
    return false;



}

int main()
{

    int t;
    cin>>t;
    for ( int i = 1;i<= t; i++)
    {
        int n;
        bool flag = true;
        cin>>n;
        Nqueen nq;
        nq.n = n;
        for ( int j = 1; j<=n;j++)
        {
            nq.x[j] = 0;
            for ( int k = 1 ; k<=n ; k++ )
            {
                char ch;
                cin>>ch;
                if(ch == 'x')
                {
                    nq.x[j]  = k;
                    /*if( nq.x[j] > 1)
                      {
                      flag = false;
                      }
                      */
                }

            }


        }

        cout<<"Case #"<<i<<":"<<endl;
        // if(flag != false)
        // {
        flag =  nq.nqueen(1 , n );
        nq.printRow();
        // }
        if( flag == true)
        {

            for ( int j = 1 ; j<=n; j++)
            {

                for ( int k = 1; k<=n; k++)
                {
                    if( nq.x[j] == k )
                    {

                        cout<<"x";
                    }
                    else
                    {
                        cout<<".";
                    }

                }
                cout<<endl;
            }

        }
        else
        {

            cout<<"not possible"<<endl;
        }
    }
    return 0;
}
