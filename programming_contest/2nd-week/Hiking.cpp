#include <iostream>
#include <set>
#include <vector>
using namespace std;

typedef vector<long int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;

const int MAX = 10005;
const long long  int MAXINT = 1000000000000000000;

//source : algolist.com
void Dijkstra(int s, vvii& G, vi& D)
{
    set<ii> Q;
    D[s] = 0;
    Q.insert(ii(0,s));

    while(!Q.empty())
    {
        ii top = *Q.begin();
        Q.erase(Q.begin());
        int v = top.second;
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
}

int main()
{
    int n,m, t = 0;
   // scanf("%d %d %d %d", &n, &m, &s, &t);
cin>>t;
for(int i = 1 ; i<= t; i++)
{
    cin>>m>>n;
vvii G(MAX);
vi D(MAX);
{
        int a=0, b=0, w = 0;
         cin>>a>>b>>w;
        G[a - 1].push_back(ii(b -1  , w));
        G[b - 1].push_back(ii(a - 1 , w));
    }

    for (int j = 0; j<= m ; j++)
    {
        D[j]= MAXINT;
    }
    Dijkstra(0, G , D);

    cout<<"Case #"<<i<<": "<<D[m - 1]<<endl;
}
    return 0;
}
