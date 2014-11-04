#include<iostream>
#include<vector>
#include<set>
#include<limits>
#include<queue>
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAX_NODES = 1005;
const int INF = std::numeric_limits<int>::max();
const int UNINITIALIZED = -1;
typedef vector<long int> vi;
typedef pair<int,double> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;


void Dijkstra(int s,int t, vvii& G, double D[],int P[])
{
    set<ii> Q;
    D[s] = 0;
    P[s] = UNINITIALIZED;
    Q.insert(ii(0,s));

    while(!Q.empty())
    {
        ii top = *Q.begin();
        Q.erase(Q.begin());
        int v = top.second;
        if( v == t)
        {
            break;
        }

        //int d = top.first;


        for (auto  it = G[v].begin(); it != G[v ].end(); it++)
        {

            int v2 = it->first;
            double cost = it->second;
            if (D[v2] > D[v] + cost)
            {
                P[v2] = v;
                if (D[v2] != std::numeric_limits<double>::max())
                {
                    Q.erase(Q.find(ii(D[v2], v2)));
                }
                D[v2] = D[v] + cost;
                Q.insert(ii(D[v2], v2));
            }
        }
    }
}

int bfs(int startNode , int endNode,vector<int> graph[],int capacities[][MAX_NODES], int flowPassed[][MAX_NODES], int parentsList[],int currentPathCapacity[] , int vcapacity[]) 
{
    // memset(parentsList, UNINITIALIZED, sizeof(parentsList));
    //memset(currentPathCapacity, 0, sizeof(currentPathCapacity));
    for(int i = 0; i<= endNode; i++)
    {
        parentsList[i] = UNINITIALIZED;
        currentPathCapacity[i] = 0;
    }
    queue<int> q;
    q.push(startNode);
    parentsList[startNode] = -2;
    currentPathCapacity[startNode]=INF;
    while(!q.empty())
    {
        int currentNode = q.front();
        q.pop();
        for(int i = 0; i<graph[currentNode].size();i++)
        {

            int to = graph[currentNode][i];
            if(parentsList[to] == UNINITIALIZED)
            {
                if(capacities[currentNode][to] - flowPassed[currentNode][to]>0)
                {
                    parentsList[to] = currentNode;
                    currentPathCapacity[to] = min(currentPathCapacity[currentNode], 
                            capacities[currentNode][to] - flowPassed[currentNode][to]);
                    //int min_node = min(vcapacity[currentNode] , vcapacity[to] );
                    //currentPathCapacity[to] = min(min_node , currentPathCapacity_temp);
                    if(to == endNode)
                    {
                        return currentPathCapacity[endNode];
                    }
                    q.push(to);
                }
            }
        }


    }
    return 0;

}
int edmondskarp(int startNode , int endNode, vector<int> graph[],int capacities[][MAX_NODES], int flowPassed[][MAX_NODES],int vcapacity[])
{


    int maxFlow =0;
    while(true)
    {

        int parentsList[MAX_NODES];
        int currentPathCapacity[MAX_NODES];
        /* for(int i =0; i<=endNode; i++)
           {
           parentsList[i] = UNINITIALIZED;
           currentPathCapacity[i] = 0;
           }
           */
        int flow = bfs(startNode , endNode, graph,capacities,flowPassed , parentsList,currentPathCapacity,vcapacity);
        if(flow == 0)
        {
            break;
        }
        //   cout<<"return value from bfs :"<<flow<<endl;
        maxFlow += flow;
        int currentNode = endNode;
        while ( currentNode != startNode)
        {
            int previousNode = parentsList[currentNode];
            flowPassed[previousNode][currentNode] += flow;
            flowPassed[currentNode][previousNode] -= flow;
            currentNode = previousNode;
        }

    }

    return maxFlow;
}


struct Coordinate{
    int x;
    int y;
    int z;
    double operator- (const Coordinate& c) const
    {
        long int dist =  ((c.x - x)* (c.x - x) + (c.y - y)*(c.y - y) +  (c.z - z)*(c.z - z)); 
        double d = sqrt(dist);
        return d;
    }
};
class Star {
    public:
        int nodesCount;
        int edgesCount;
        int startNode;
        int endNode;
        int id;
        int capacity;
        Coordinate c;
        vector<int>graph[MAX_NODES];
        int capacities[ MAX_NODES][ MAX_NODES];
        int flowPassed [ MAX_NODES][ MAX_NODES];
        int vcapacity[MAX_NODES];
    public:

        int calculateCapacity( );
        void setStarInfo(int n, int m);
        void setLocation(Coordinate c);
        void intialiseVertexCapacity();
        void printGraph();

};
void Star:: printGraph()
{
    for (int i=1;i <= nodesCount;i++)
    {
        cout<<endl;
        cout<<"From "<<i<<"-->";
        for (auto it= graph[i].begin();it != graph[i].end();it++)
        {
            cout<<*it<<" ";

        }
    }
}
void Star::setLocation(Coordinate c)
{
    this->c = c;
}
int Star:: calculateCapacity( )
{
    //printGraph();
    //   cout<<endl;
    capacity = edmondskarp(1 , nodesCount,  graph,capacities,  flowPassed, vcapacity);

    //cout<<"calculated capacity:"<<capacity<<endl;
    return capacity;

}

void Star::intialiseVertexCapacity()
{
    //intialise vertex capacity nodes
    for (int i = 0 ; i<=nodesCount; i++)
    {
        vcapacity[i] = std::numeric_limits<int>::max();
    }

}
void Star::setStarInfo(int n, int m)
{
    nodesCount = n;
    edgesCount = m;
    //intialiseVertexCapacity();
    //input edges

    for(int edge= 0; edge<edgesCount; edge++)
    {
        int from, to , capacity;
        scanf("%d %d %d",&from , &to, &capacity);
        from -= (startNode - 1);
        to -= (startNode -1);
        //edge e;
        // e (from, to, capacity,0);
        if( from == to)
        {

            vcapacity[from] = capacity;
            continue;
        }
        if(find(graph[from].begin(), graph[from].end(),to) != graph[from].end())
        {

            capacities[from][to] += capacity;
            capacities[to][from] += capacity;
        }
        else
        {

            capacities[from][to]  = capacity;
            capacities[to][from]  = capacity;
        }
        graph[from].push_back(to);
        //edge b(to, from, capacity,0);
        graph[to].push_back(from);
        flowPassed[from][to] = 0;
        flowPassed[to][from] = 0;

    }


}
class Galaxy
{
    private:
        vector<Star> stars;
        int N;
        int M;
        int m;
        int n;
        int parentsList[MAX_NODES];
        vvii graph;
        double D[MAX_NODES];
    public:
        Galaxy():graph(MAX_NODES)
    {

    }
        void setGalaxyInfo();
        void calculateShortesPath();
        long int getMaxFlow(int parentsList[]);
        void calculateStarsCapacity();
        double maxTransferCapacity();
        void printGraph();
        void printStarsCapacity();
};
void Galaxy:: printStarsCapacity()
{
    cout<<"Stars capacity *******\n";
    for(auto it = stars.begin();it != stars.end(); it++)
    {
        cout<<it->capacity<<endl;
    }
}
void Galaxy:: printGraph()
{
    for (int i=1;i <=N;i++)
    {
        cout<<endl;
        cout<<"From "<<i<<"-->";
        for (auto it = graph[i].begin();it != graph[i].end();it++)
        {
            cout<<it->first<<" ";

        }
    }

}
double Galaxy::maxTransferCapacity()
{
    int currentNode = N;
    //int startNode =1;
    double  minvCapacity = 0;
    double  mineCapacity =0;
    double  edgeCapacity = 0;
    double  minCapacity = std::numeric_limits<double>::max();
    // cout<<"\nshortest path lengeth:"<<D[N]<<endl;
    //cout<<"\n";
    if(D[N] == std::numeric_limits<double>::max())
    {

        return 0 ;
    }

    int c1 =  stars.at(currentNode -1).calculateCapacity();
    int previousNode = parentsList[currentNode];
    if(previousNode == UNINITIALIZED)
    {

        return 0;
    }

    while ( currentNode != 1)
    {previousNode = parentsList[currentNode];
        edgeCapacity = D[currentNode] - D[previousNode];
        int c2 = stars.at(previousNode -1).calculateCapacity();
        //cout<<c1<<" "<<c2<<endl;
        minvCapacity = min(c1 , c2 );
        c1 = c2;

        mineCapacity = min(minvCapacity,edgeCapacity*edgeCapacity);   
        if(minCapacity > mineCapacity)
        {
            minCapacity = mineCapacity;

        }
        currentNode = previousNode;
    }
    return minCapacity;
}
void Galaxy::calculateShortesPath()
{
    for(int i=0;i<=N;i++)
    {
        D[i] = std::numeric_limits<double>::max();
        parentsList[i] = -1;

    }
    Dijkstra( 1 , N, graph, D,parentsList);
}
void Galaxy:: calculateStarsCapacity()
{
    for(auto it = stars.begin();it != stars.end();it++)
    { 

        it->calculateCapacity();

    }
}
void Galaxy::setGalaxyInfo()
{

    cin>>N>>M>>n>>m;
    for(int i=1;i<=N;i++)
    {

        Star s;
        Coordinate c;
        scanf("%d %d %d",&c.x, &c.y, &c.z);
        s.startNode = (i -1 )*n + 1; 
        s.endNode = i *n ; 
        s.setLocation( c);
        stars.push_back(s);
    }
    for(int i=0;i<M;i++)
    {
        int from , to;
        scanf("%d %d",&from, &to);
        double capacity= stars.at(from -1).c - stars.at(to - 1).c;
        graph[from ].push_back({to,capacity});

    }
    for(int i=0;i<N;i++)
    {
        stars.at(i).setStarInfo(n,m);
    }


}
int main ()
{

    int t;
    double maxFlow = 0;
    cin>>t;
    for(int i=1;i<=t; i++)
    {

        Galaxy g;
        g.setGalaxyInfo();
        //g.printGraph();
        // g.calculateStarsCapacity();
        //g.printStarsCapacity();
        g.calculateShortesPath();
        maxFlow = g.maxTransferCapacity();
        if(maxFlow == 0)
        {
            cout<<"Case #"<<i<<": impossible"<<endl;
        }
        else
        {

            cout<<"Case #"<<i<<": "<<maxFlow<<endl;
        }
    }
    return 0;
}
