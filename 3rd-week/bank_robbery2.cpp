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
                    int currentPathCapacity_temp = min(currentPathCapacity[currentNode], 
                            capacities[currentNode][to] - flowPassed[currentNode][to]);
                    int min_node = min(vcapacity[currentNode] , vcapacity[to] );
                    currentPathCapacity[to] = min(min_node , currentPathCapacity_temp);
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
int edmondskarp(int startNode , int endNode, vector<int> graph[],int capacities[][MAX_NODES], int flowPassed[][MAX_NODES],int vcapacity[])
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
        int flow = bfs(startNode , endNode, graph,capacities,flowPassed , parentsList,currentPathCapacity,vcapacity);
        if(flow == 0)
        {
            break;
        }
        //cout<<"return value from bfs :"<<flow<<endl;
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


int main ()
{

    int t;
    cin>>t;
    for(int i = 1; i<=t; i++)
    {
        vector<int> graph[MAX_NODES];
        int capacities[MAX_NODES][MAX_NODES];
        int flowPassed[MAX_NODES][MAX_NODES];
        int vcapacity[MAX_NODES];

        int p,nodesCount , edgesCount;
        cin>>p>>nodesCount>>edgesCount;
        //intialise vertex capacity nodes
        for (int i = 0 ; i<=nodesCount; i++)
        {
            vcapacity[i] = std::numeric_limits<int>::max();
        }
        // cin>>source>>sink;
        for(int edge= 0; edge<edgesCount; edge++)
        {
            int from, to , capacity;
            cin>>from>> to>>capacity;
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
        int maxFlow = edmondskarp(1 , nodesCount,graph,capacities,flowPassed,vcapacity); 
        //int maxFlow = edmondskarp(1 , nodesCount,graph,capacities,flowP); 
        if(maxFlow <= p)
        {
            cout<<"Case #"<<i<<": yes"<<endl; 
        }
        else
        {

            cout<<"Case #"<<i<<": no"<<endl; 
        }
            //cout<<"Case #"<<i<<": "<<maxFlow<<endl; 
    }
    return 0; 
}
