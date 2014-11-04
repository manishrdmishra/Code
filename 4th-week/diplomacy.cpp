#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<list>
#include<utility>

using namespace std;
typedef pair<int,int>ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
const int MAX_NODES = 20005;
void bfs(int s, vvii& G,int p[],int n)
{
    int visited[MAX_NODES];
    for(int i=0;i<=n;i++)
    {
        visited[i] = false;
        p[i] =0;
    }
    list<int> Q;
    p[s] = 1;
    visited[s] = 1;
    Q.push_back(s);

    while(!Q.empty())
    {

        int v = Q.front();
        Q.pop_front();
        //cout<<v;


        for (auto  it = G[v].begin(); it != G[v ].end(); it++)
        {

            int v2 = it->first;
            int type= it->second;
            if (visited[v2] == 0)
            {
                visited[v2] =  1;
                if((p[v] == 1 && type ==1 )||(p[v] == 0 && type ==0 ))
                {           
                    p[v2] = 1;
                }
                else
                {

p[v2] = 0;
                }
                // cout<<"  "<<p[v2]<<endl;
                Q.push_back(v2);
            }
        }
    }
}

int main ()
{
    int t;
    cin>>t;
    for(int i = 1;i<=t;++i)
    {
        int n, m;
        //int  type_array[2] ={0,1};
        cin>>n>>m;
        int friends[MAX_NODES];
        vvii G(MAX_NODES);
        //int type_arry[2] = {0,1};
        for(int j = 0;j<m;++j)
        {
            char type;
            int a,b;
            cin>>type>>a>>b;
            if(type == 'F')
            {
                G[a].push_back(std::make_pair(b,1));
                G[b].push_back(std::make_pair(a,1));
            }
            else
            {
                G[a].push_back({b,0});
                G[b].push_back({a,0});

            }

        }
        bfs(1,G,friends,n);
        int count = 0;
        for (int j = 0;j<=n;j++)
        {
            if(friends[j] == 1)
            {
                count++;

            }
        }
        //       cout<<"count: "<<count<<endl;
       /* cout<<"\n***********\n";
        cout<<"friends are :";
        for(int  j=1;j<=n;j++)
        {
            if(friends[j] == 1)
            {
                cout<<j<<" ";

            }
        } 
        cout<<endl;
        */
        if(count > n/2)
        {
            cout<<"Case #"<<i<<": yes"<<endl;
        }

        else
        {

            cout<<"Case #"<<i<<": no"<<endl;
        }
    }

}
