#include <iostream>
#include <set>
#include <vector>
#include <iomanip>
#include <cmath>
#include <limits>
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
    double  dist_;
    double  ldist_;
    int previous_;
    bool operator<(const node& n)
    {
        return (dist_ < n.dist_);
    }   
};
struct edge{
    int   u_;
    int   v_;
    double  weight_;
    edge()
    {
    }
    edge(int u , int v, double  weight ):u_(u ), v_(v), weight_(weight)
    {

    }
    bool operator< ( const edge& e) const
    {
        return (weight_ < e.weight_ );
    }
};
//source : algolist.com
int  bellman_ford(int s, vector<edge>& edges, vector<node>& D)
{
    D[0].ldist_ = 0;
    D[0].dist_ = 0;
    for(int  i = 1 ; i< D.size()-1;i++)
    {
        int u , v;
        double cost, lcost;


        for (auto  it = edges.begin(); it != edges.end(); it++)
        {

            u = it->u_;
            v = it->v_;
            cost = it->weight_;
            lcost = log(cost);
            if (D[v].ldist_ > D[u].ldist_ + lcost)
            {
                D[v].ldist_ = D[u].ldist_ + lcost;
                // D[v].dist_ = D[u].dist_ + cost;
            }
        }
    }
    for (auto &e : edges)
    {
        if( D[e.v_].ldist_ > D[e.u_].ldist_ +(log(e.weight_)))
        {

            return 0;

        }
    }
    if ( D[D.size() - 1].dist_ == MAXINT)
    {
        return -1;
    }

    return 1;
}

int main()
{
    int n,m, t = 0;
    // scanf("%d %d %d %d", &n, &m, &s, &t);
    cin>>t;
    for(int i = 1 ; i<= t; i++)
    {
        vvii G(MAX);
        vector<node> D;
        vector<edge> edges;
        cin>>m>>n;
        int a=0, b=0;
        double w;
        for (int j = 0; j < n; j++)
        {
            cin>>a>>b>>w;
            //w = -log(w)
            edges.push_back(edge(a - 1, b - 1, w));
        }

        for (int j = 0; j<= m ; j++)
        {
            node n;
            n.dist_ = MAXINT;
            n.ldist_ = MAXINT;
            n.visited_ = false;
            n.previous_ = 0;
            D.push_back(n);
        }
        int res =  bellman_ford(0, edges , D);
        if(res == 0)
        {

            cout<<"Case #"<<i<<": Jackpot"<<endl;
        }
        else if (D[m-1].ldist_ != MAXINT){
            //std::setprecision(6);
            double cost = std::exp(D[m - 1].ldist_);
            std::cout<<"Case #"<<i<<": "<<std::fixed<<cost<<endl;
        }
        else
        {
            cout<<"Case #"<<i<<": impossible"<<endl;

        }
    }
    return 0;
}
