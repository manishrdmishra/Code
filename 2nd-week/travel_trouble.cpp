#include<iostream>
#include<vector>
#include<set>
#define INFINITE 1000000000000 

struct edge{
    int   u_;
    int   v_;
    int weight_;
    edge()
    {
    }
    edge(int u , int v, int weight ):u_(u ), v_(v), weight_(weight)
    {

    }
    bool operator< ( const edge& e) const
    {
        return (weight_ < e.weight_ );
    }
};

struct node
{

    int number_;
    bool visited_;
    long int dist_;
    int previous_;
    bool operator<(const node& n)
    {
        return (dist_ < n.dist_);
    }
};


struct list_node{

    list_node(int v, int dist):v_(v),dist_(dist)
    {

    }
    int v_;
    int dist_;
};



class Dijkstra{

    public:
        Dijkstra(int node_count, int edge_count):nodes_count_(node_count),edges_count_(edge_count)
                                                 , adjacancy_list_(nodes_count_)
    {
    }
         void findShortestPath(int source, int dest);
        void printShortesPath();    
        void intialiseEdges();
        void intialiseNodes();
        void printPath(int target);
        void printGraph();
        long int  getCostByVertexId(int id)
        {

return nodes_.at( id - 1).dist_;
        }
    private:

        // std::vector<edge> edges_;

        std::vector<node> nodes_;
        typedef std::vector<list_node> nodes;
        //std::vector<line> lines;
        int nodes_count_;
        int edges_count_;
        std::vector<std::vector<list_node>> adjacancy_list_;
};

void Dijkstra::printPath(int target)
{
    std::vector<int> seq;
    int u = target;
    seq.insert(seq.begin(), u);
    while ( nodes_.at( u - 1).previous_ != 0)
    {
        u = nodes_.at(u - 1).previous_;
        seq.insert(seq.begin(),u);

    }
    //  std::cout<<"number of nodes:"<<seq.size()<<"\n";
    for (auto it = seq.begin();it != seq.end(); it++)
    {

        // std::cout<<*it<<" ";
    }

}
void Dijkstra::intialiseEdges()
{

    int u , v, c;
    // take input here
    for (int i = 0; i<edges_count_; i++)
    {
        std::cin>>u>>v>>c;

        adjacancy_list_[u -1 ].push_back(list_node(v,c));

    }
}

void Dijkstra::printGraph(){



    int count = 0;
    std::cout<<"grap************\n";
    for (auto it = adjacancy_list_.begin();it != adjacancy_list_.end();it++)
    {
        std::cout<<"from node:"<< ++count<<" " <<it->size()<<std::endl;
        for(auto it1 = it->begin(); it1 != it->end(); it1++)
        {

            std::cout<<it1->v_<<" ";//<<it1->dist_;
        }
        std::cout<<std::endl;
    }

}

void Dijkstra::intialiseNodes()
{
    //create nodes here
    for(int i = 0; i<nodes_count_; i++)
    {
        node n;
        n.number_ = i + 1;
        n.visited_ = false;
        n.dist_ = INFINITE;
        n.previous_ = 0;
        nodes_.push_back(n);

    }
}


void Dijkstra::findShortestPath(int source , int dest)
{
    typedef std::pair<int , int> vertex_cost_pair;
    std::set< vertex_cost_pair > pq;



    nodes_[source - 1].dist_ = 0;
    pq.insert(vertex_cost_pair(0,source));

    while (pq.size()>0)
    {

        vertex_cost_pair top = *pq.begin();
        pq.erase(pq.begin());
        int u = top.second;

        //int cost = top.first;

        nodes_[u - 1].visited_ = true;
        //if ( u == dest ) break;
        for ( auto it = adjacancy_list_.at(u - 1).begin() ; it != adjacancy_list_.at( u -1 ).end(); it++)
        {
            int v = it->v_;
            int dist = it->dist_;

            //if (nodes_.at(v - 1).visited_ i== true) continue;
            if( nodes_[v - 1].dist_ > nodes_[ u - 1].dist_ + dist)
            {
                
                if (nodes_.at(v - 1).dist_ != INFINITE)
                {
                    pq.erase(pq.find(vertex_cost_pair(nodes_.at( v -1 ).dist_,v)));

                }
                nodes_.at(v - 1).dist_ = nodes_[u -1 ].dist_ + dist;
                //nodes_.at(v - 1).previous_ = u;
                pq.insert(vertex_cost_pair(nodes_.at(v - 1).dist_ ,v)); 

            }


        }
    }
}


int main()
{
    int t;
    int n;
    int m;
    std::cin>>t;
    for (int num = 1; num <= t; num++) 
    {
        std::cin>>m>>n;
        Dijkstra dj(m,n);
        dj.intialiseEdges();
        dj.intialiseNodes();
       //dj.printGraph();
        dj.findShortestPath(1, n);
          std::cout<<"Case #"<<num<<": "<<dj.getCostByVertexId( m )<<std::endl;
   //       dj.printPath(n);
         // std::cout<<std::endl;




    }

    return 0;
}
