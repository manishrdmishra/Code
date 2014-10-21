#include <iostream>
#include <set>
#include <vector>
#include<limits>
using namespace std;

typedef vector<long int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;

const int MAX = 10005;
const long long  int MAXINT = 1000000000000000000;
struct node
{

    int number_;
    bool visited_;
    long int dist_;
    long int sdist_;
    bool operator<(const node& n)
    {
        return (dist_ < n.dist_);
    }   
};
    //source : algolist.com
    int  Dijkstra(int s,int t, vvii& G, vi& D)
    {
        set<ii> Q;
        D[s] = 0;
        Q.insert(ii(0,s));

        while(!Q.empty())
        {
            ii top = *Q.begin();
            Q.erase(Q.begin());
            int v = top.second;
            if ( v == t)
            {
                return D[ t-1];
            }
            //int d = top.first;

            for (auto  it = G[v].begin(); it != G[v ].end(); it++)
            {

                int v2 = it->first;
                int cost = it->second;
                if (D[v2] > D[v] + cost)
                {
                    if (D[v2] != MAXINT)
                    {
                        Q.erase(Q.find(ii(D[v2], v2)));
                    }
                    D[v2] = D[v] + cost;
                    Q.insert(ii(D[v2], v2));
                }
            }
        }
        return -1;
    }
    void printTime(int i,  long long int time)
    {
        int hours = time / 60;
        int minutes = time % 60;

        if( minutes < 10 )
        {
            cout<<"Case #"<<i<<": "<<hours<<":"<<"0"<<minutes<<endl;
        }
        else
        {
            cout<<"Case #"<<i<<": "<<hours<<":"<<minutes<<endl;
        }

    }
    int main()
    {
        int n,m,s,t = 0,start,end;
        // scanf("%d %d %d %d", &n, &m, &s, &t);
        cin>>t;
        for(int i = 1 ; i<= t; i++)
        {
            vvii G(MAX);
            vi D(MAX);
            vii S(MAX);
            cin>>n>>m>>s>>start>>end;
            {
                int a=0, b=0, w = 0;
                cin>>a>>b>>w;
                G[a - 1].push_back(ii(b -1  , w));
                G[b - 1].push_back(ii(a - 1 , w));
            }

            for( int j = 0; j<s;j++)
            {
                int num , sdist;
                cin>>num>>sdist;
                S.push_back(std::pair<int, int>(num, sdist));
            }
            for (int j = 0; j<= n ; j++)
            {
                D[j] = std::numeric_limits<long>::max();

            }
            long int time = std::numeric_limits<long>::max();
            for(auto &s:S)
            {
                int sm = s.first;
                int stime = s.second;
                int d1 = Dijkstra(start-1 , sm -1, G , D);
                int d2 = Dijkstra(sm-1 , end-1,G, D) ;
                if( d1 == -1 || d2 == -1)
                {
                    continue;
                }

                int d = d1 + d2 + stime ;
                if( time > d)
                {
                    time = d;
                }


                if( time == std::numeric_limits<long>::max())

                {

                    cout<<"Case #"<<i<<": not possible"<<endl;


                } 
                else
                {
                    printTime(i ,time);
                }
            }
        }

        return 0;
    }
