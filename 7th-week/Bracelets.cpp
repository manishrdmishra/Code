#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

const int debug = 0;
const int MAX = 505;
int lcs(string a , string b,int c[][MAX])
{

    // int c[MAX][MAX];
    int m , n;
    m = a.length();
    n = b.length();
    /*for ( int i = 0 ; i<=m ; i++)
      {
      c[i][0] = 0;
      }
      for ( int j = 0 ; j<=n ; j++)
      {
      c[0][j] = 0;
      }
      */
    for ( int i = 1;i<= m ; i ++)
    {

        for ( int j = 1;j<= n;j ++)
        {
            if ( a[i - 1] == b[j - 1])
            {

                c[i][j] = c[i - 1][j - 1] + 1;

            }
            else
            {
                c[i][j] = std::max( c[i][j - 1] , c[i -1][j]);

            }

        }

    }

    return c[m][n];

}
int main()
{

    int t;
    cin>>t;
    for ( int i = 1;i<=t;i++)
    {

        string a,b;
        int len = 0, max_len = 0;
        int len_a, len_b;
        int c[MAX][MAX];
        cin>>a>>b;
        len_a = a.length();
        len_b = b.length();
        for ( int i = 0 ; i<=len_a ; i++)
        {
            c[i][0] = 0;
        }
        for ( int j = 0 ; j<=len_b ; j++)
        {
            c[0][j] = 0;
        }


        for ( int i = 0 ; i<len_a ; i ++)
        {
            string x =  a.substr(i);
            x.append(a.substr(0,i));
            len =  lcs(x, b,c);
            if(debug)
                cout<<"string: "<< x<<" "<<"len:"<<len<<endl;
            if(max_len < len )
            {

                max_len = len;
            }
            std::reverse(x.begin(),x.end());
            len =  lcs(x, b,c);
            if(debug)
                cout<<"string: "<< x<<" "<<"len:"<<len<<endl;
            if(max_len < len )
            {

                max_len = len;
            }


        }

        cout<<"Case #"<<i<<": "<<max_len<<endl;


    }
    return 0;

}
