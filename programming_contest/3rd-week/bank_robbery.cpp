#include<cstdio>
#include<queue>
#include<vector>
#include<iostream>
#include<limits>
#include<stdio.h>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAX_NODES = 1005;
const int UNINITIALIZED = -1;
const int INF = numeric_limits<int>::max();
int bfs(int startNode , int endNode,vector<int> graph[],int capacities[][MAX_NODES], int flowPassed[][MAX_NODES], int parentsList[],int currentPathCapacity[] ) 
{
    // memset(parentsList, UNINITIALIZED, sizeof(parentsList));
    //memset(currentPathCapacity, 0, sizeof(currentPathCapacity));
    bool visitor[MAX_NODES];
    for(int i = 0; i<= endNode; i++)
    {
        parentsList[i] = UNINITIALIZED;
        currentPathCapacity[i] = 0;
        visitor[i] = false;
    }
    queue<int> q;
    q.push(startNode);
    parentsList[startNode] = -2;
    currentPathCapacity[startNode]=INF;
    while(!q.empty())
    {
        int currentNode = q.front();
        //visitor[currentNode]= true;
        q.pop();
        for(int i = 0; i<graph[currentNode].size();i++)
        {

            int to = graph[currentNode][i];
          /*  if ( visitor[to] == true)
            {
                continue;
            }*/
            if(parentsList[to] == UNINITIALIZED)
            {
                if(capacities[currentNode][to] - flowPassed[currentNode][to]>0)
                {
                    parentsList[to] = currentNode;
                    currentPathCapacity[to] = min( currentPathCapacity[currentNode], 
                            capacities[currentNode][to] - flowPassed[currentNode][to]);
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

/*http://backtrack-it.blogspot.de */
int edmondskarp(int startNode , int endNode, vector<int> graph[],int capacities[][MAX_NODES], int flowPassed[][MAX_NODES])
{


    int maxFlow =0;
    while(true)
    {

        int parentsList[MAX_NODES];
        int currentPathCapacity[MAX_NODES];
        /*for(int i =0; i<=endNode; i++)
          {
          parentsList[i] = UNINITIALIZED;
          currentPathCapacity[i] = 0;
          }
          */
        int flow = bfs(startNode , endNode, graph,capacities,flowPassed , parentsList,currentPathCapacity);
        if(flow == 0)
        {
            break;
        }
        cout<<"return value from bfs :"<<flow<<endl;
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


struct edge
{
    edge(int s, int e , int w, int f)
    {
        start = s;
        end=e;
        capacity  =  w;
        flow = f;
    }

    int start;
    int end;
    int capacity;
    int flow;
};

void printGraph(int nodes, std::vector<int> graph[MAX_NODES], int capacities[][MAX_NODES])
{

    for (int i =1 ;i<=2*nodes; i++)
    {

        cout<<"vertex from node: "<<i<<"--->";
        for(int j= 0;j<graph[i].size();j++)
        {
            cout<<" ("<<graph[i][j]<<", "<<capacities[i][graph[i][j]]<<") ";

        }

        cout<<endl;
    }


}

int main ()
{

    int t;
    cin>>t;
    for(int i = 1; i<=t; i++)
    {
        vector<int> graph[MAX_NODES];
        //vector<int>flowPassed[MAX_NODES];
        //vector<int>capacities[MAX_NODES];
        int capacities[MAX_NODES][MAX_NODES];
        int flowPassed[MAX_NODES][MAX_NODES];
        int police,nodesCount , edgesCount;
        cin>>police>>nodesCount>>edgesCount;
        // cin>>source>>sink;
        //initialize the adjacancy list
        for (int k = 1;k<= nodesCount; k++)
        {

            int from , to ;
            from = k;
            to = k + nodesCount;
            graph[from].push_back(to);
            graph[to].push_back(from);
            capacities[to][from]= std::numeric_limits<int>::max();
            capacities[from][to]= std::numeric_limits<int>::max();
            flowPassed[from][to] = 0;
            flowPassed[to][from] = 0;

        }
        //  cout<<"**********"<<endl;
        // printGraph(nodesCount,graph,capacities);

        for(int edge= 0; edge<edgesCount; edge++)
        {
            int from, to , capacity;
            cin>>from>> to>>capacity;
            if(from > to )
            {
                int temp = to;
                to = from;
                from = temp;
            }
            if( from == to )
            {
                to =  to + nodesCount;
                if(capacities[from][to] !=INF)
                {
                capacities[from][to] += capacity;
                capacities[to][from]  += capacity;
                }
                else
                {

                capacities[from][to] = capacity;
                capacities[to][from]  = capacity;

                }
            }
            else
            {

                from = from + nodesCount;


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
            }
            graph[from].push_back(to);
            graph[to].push_back(from);
            flowPassed[from][to] = 0;
            flowPassed[to][from] = 0;

        }
       /*
        cout<<"**********"<<endl;
        printGraph(nodesCount,graph,capacities);
        */
        int maxFlow = edmondskarp(1 , 2*nodesCount,graph,capacities,flowPassed); 
        //int maxFlow = edmondskarp(1 , nodesCount,graph,capacities,flowP); 
        if(maxFlow <= police)
        {
          //  cout<<"Case #"<<i<<": "<<maxFlow<<endl; 
            cout<<"Case #"<<i<<": yes"<<endl; 
        }
        else
        {

            //cout<<"Case #"<<i<<": "<<maxFlow<<endl; 
            cout<<"Case #"<<i<<": no"<<endl; 
        }
           cout<<" :"<<maxFlow<<endl; 

    }
    return 0; 
}
