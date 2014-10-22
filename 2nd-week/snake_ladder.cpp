#include<iostream>
#include<limits>
#include<vector>
#include<set>
#include<utility>

typedef std::vector<std::pair<int,int>> vii;
typedef std::vector<vii> vvii;
const int MAX = 10000; 
class SnakeLadder{ 
    public:
        SnakeLadder(int nodes, int snakes, int ladders):node_count_(nodes), snakes_count_(snakes),ladders_count_(ladders),
        nodes_(nodes){

        }
         vvii  createEdges(int n);
    void   inputSnakeLadder();
        int dijkstra(int source,const vvii &edges);
        void printBoard(const vvii &edges);
       // void clear(){edges_.clear();}
    private:
        int node_count_;
        int snakes_count_;
        int ladders_count_; 
        std::vector<long int > nodes_;
        std::vector<std::pair<int,int>>snakes_;
        std::vector<std::pair<int,int>>ladders_;
};
void SnakeLadder::printBoard(const vvii &edges_)
{
    for (int i = 0 ; i<node_count_;i++)
    {
        std::cout<<"node:"<<i + 1<<" ";
        for(auto it = edges_[i].begin();it != edges_[i].end();it++)
        {

            std::cout<<it->first+1<<" ";

        }
        std::cout<<std::endl;
    }

}
int  SnakeLadder::dijkstra(int s,const vvii &edges_)
{
    std::set<std::pair<int, int>> Q;
    std::vector<int> D(node_count_);
    for(int i = 0 ; i<node_count_;i++)
    {

        D[i] = std::numeric_limits<int>::max();
    }
    D[s] = 0;
    Q.insert({0,s});

    while(!Q.empty())
    {
        auto top = *Q.begin();
        Q.erase(Q.begin());
        int v = top.second;
        /* if ( v == t) */
        /* { */
        /*     return D[t]; */
        /* } */
        //int d = top.first;

        for (auto  it = edges_[v].begin(); it != edges_[v ].end(); it++)
        {

            int v2 = it->first;
            int cost = it->second;
            if (D[v2] > D[v] + cost)
            {
                if (D[v2] != std::numeric_limits<int>::max())
                {
                    Q.erase(Q.find({D[v2], v2}));
                }
                D[v2] = D[v] + cost;
                Q.insert({D[v2], v2});
            }
        }
    }
    return D[node_count_ - 1];
}
void SnakeLadder::inputSnakeLadder()
{
    int head, tail;
    for(int i = 0; i<snakes_count_; i++)
    {
        std::cin>>head>>tail;
        snakes_.push_back({head, tail});

    }
    for(int i = 0; i<ladders_count_; i++)
    {
        std::cin>>head>>tail;
        ladders_.push_back({head, tail});

    }

}
 vvii  SnakeLadder::createEdges(int n)
{
        std::vector<std::vector<std::pair<int , int>>> edges_(MAX);
    int start = 0,end=0;
    //std::cout<<"nodes pushed for "<<n<<std::endl;
    for( int i = 1;i <node_count_; i= i + n)
    {
        end = start + n;
        start = end;
        if(end + 1 > node_count_)
        {
            end = node_count_ - 1;
        }

        edges_[i-1].push_back({end ,1});
      //  std::cout<<start<<" "<<end<<" "<<std::endl;
    }

    for(auto &s:snakes_)
    {
        int snake_mouth = s.first;
        int snake_tail = s.second;
        if( edges_[snake_mouth - 1].size())
        {
        edges_[snake_mouth - 1].at(0).first = snake_tail - 1;
        edges_[snake_mouth -1].at(0).second = 0;
    }}
    for(auto &l:ladders_)
    {
        int ladder_start= l.first;
        int ladder_end = l.second;
       if(edges_[ladder_start - 1].size())
       {
       edges_[ladder_start - 1].push_back({ladder_end - 1,1});
    }}
//printBoard(edges_);
    return edges_;
}

int main()
{
    int t,n,s,l;
    std::cin>>t;
    for(int i = 0; i<t; i++)
    {
        std::cin>>n>>s>>l;
        SnakeLadder sl(n,s,l);
        sl.inputSnakeLadder();
        std::set<std::pair<int,int>> edge_count;
        int min_count = std::numeric_limits<int>::max();
        for (int i = 1;i<=1;i++)
        {
         //   sl.clear();
         const vvii edges =  sl.createEdges(5);
            std::cout<<"*******************"<<std::endl;
            sl.printBoard(edges);
                

                   int  num =  sl.dijkstra(0,edges);
                   if(min_count >= num)
                   {
                   min_count = num;
                   std::cout<<"cost:"<<min_count<<std::endl;
                   }

                   edge_count.insert({num,i});
                   
        }
        /*

           if(min_count == std::numeric_limits<int>::max())
           {
           std::cout<<"Case #"<<i<<": not possible"<<std::endl;
           continue;
           }


           std::cout<<"Case #"<<i<<": "; 
           for(auto &s:edge_count)
           {
           if(s.first != min_count)
           {
           break;
           }

           std::cout<<s.second;
           }
           */

    }
    return 0;
}
