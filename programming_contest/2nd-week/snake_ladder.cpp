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
        int dijkstra(int source,int steps);
        void printBoard(const vvii &edges);
        // void clear(){edges_.clear();}
    private:
        int node_count_;
        int snakes_count_;
        int ladders_count_; 
        std::vector<long int > nodes_;
        std::vector<std::pair<int,int>>snakes_;
        int sl[MAX];
        int ladder[MAX];
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
int  SnakeLadder::dijkstra(int s,int step)
{

    std::set<std::pair<int, int>> Q;
    std::vector<int> D(node_count_);
    std::vector<bool> V(MAX);
    for(int i = 0 ; i<node_count_;i++)
    {

        D[i] = std::numeric_limits<int>::max();
        V[i] = false;
    }
    D[s] = 0;
    int v,v2;
    while(1)
    {
        if( s >= node_count_ -1 )
        {
            break;
        }

        v2 = s + step;
        if( v2 > node_count_ -1)
        {
            v2 = node_count_  - 1;
        }

        v = s;
        if(V[v2] == false)
        {
            D[v2] = D[v] + 1;

            V[v2] = true;
            s= v2;
            if(sl[v2] != -1 )
            {

                int tail =sl[v2];
                if(D[tail] > D[v2])
                {
                    D[tail] =  D[v2];

                }
                s = tail;

            }


            if( ladder[v2] != -1 )
            {
                int top = ladder[v2];
                if (top - v2 > step)
                {
                    s = top;
                }

            }
        }

    }
    return D[node_count_ - 1];
}
void SnakeLadder::inputSnakeLadder()
{
    int head, tail;
    for (int i =0 ; i<node_count_;i++)
    {
        sl[i] = -1;
        ladder[i] = -1;

    }
    for(int i = 0; i<snakes_count_; i++)
    {
        std::cin>>head>>tail;
        sl[head -1 ] = tail - 1;
    }
    for(int i = 0; i<ladders_count_; i++)
    {
        std::cin>>tail>>head;
        ladder[tail - 1] = head - 1;
    }

}
vvii  SnakeLadder::createEdges(int n)
{
    std::vector<std::vector<std::pair<int , int>>> edges_(MAX);
    //std::cout<<"nodes pushed for "<<n<<std::endl;
    int start,end;
    for( int i = 1;i <=node_count_; i++)
    {
        for(int j = i; j<i+6&&j<node_count_;j++) 
        {
            //end = start + n;
            //start = end;
            if(j + 1 > node_count_)
            {
                end = node_count_ - 1;
            }

            edges_[i-1].push_back({j ,1});
            //  std::cout<<start<<" "<<end<<" "<<std::endl;
        }}

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
        for (int j = 1;j<=6;j++)
        {
            //   sl.clear();
            //   const vvii edges =  sl.createEdges(5);
            //std::cout<<"*******************"<<std::endl;
            // sl.printBoard(edges);


            int  num =  sl.dijkstra(0,j);
            if(min_count >= num)
            {
                min_count = num;
                //     std::cout<<"cost:"<<min_count<<std::endl;
            }

            edge_count.insert({num,j});

        }


        if(min_count == std::numeric_limits<int>::max())
        {
            std::cout<<"Case #"<<i+1<<": not possible"<<std::endl;
            continue;
        }


        std::cout<<"Case #"<<i+1<<": "; 
        for(auto &s:edge_count)
        {
            if(s.first != min_count)
            {
                break;
            }

            std::cout<<s.second<<" ";
        }
        std::cout<<std::endl;

    }
    return 0;
}
