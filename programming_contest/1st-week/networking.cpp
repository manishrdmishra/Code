#include<iostream>
#include <list>
#include<vector>
#include<algorithm>
struct coordinate{
    int x;
    int y;
    int z;
    int operator- (const coordinate& c) const
    {
        return (abs(c.x - x) + abs(c.y - y) + abs (c.z - z)); 
    }
};

struct node
{

    int number_;
    coordinate c_;
    int operator-( const node& a) const
    {
        return (a.c_ - c_); 

    }


};

struct edge{
    int   u_;
    int   v_;
    int weight_;
    std::string greet;
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
    void merge_node()
    {
        std::string node_1 = std::to_string(u_);
        std::string node_2 = std::to_string(v_);
        greet = node_1 + node_2;
    }
    static bool sort(const edge&  a , const edge&  b)
    {
        return (( a.u_ < b.u_) || (a.u_ == b.u_ && a.v_ < b.v_ ) );
    }
};

//source: taken from wordpress.com 
class disjoint_sets {
    struct disjoint_set {
        size_t parent;
        unsigned rank;
        disjoint_set(size_t i) : parent(i), rank(0) { }
    };
    std::vector<disjoint_set> forest;
    public:
    disjoint_sets(size_t n){
        forest.reserve(n);
        for (size_t i=0; i<n; i++)
            forest.push_back(disjoint_set(i));
    }
    size_t find(size_t i){
        if (forest[i].parent == i)
            return i;
        else {
            forest[i].parent = find(forest[i].parent);
            return forest[i].parent;
        }
    }
    void merge(size_t i, size_t j) {
        size_t root_i = find(i);
        size_t root_j = find(j);
        if (root_i != root_j) {
            if (forest[root_i].rank < forest[root_j].rank)
                forest[root_i].parent = root_j;
            else if (forest[root_i].rank > forest[root_j].rank)
                forest[root_j].parent = root_i;
            else {
                forest[root_i].parent = root_j;
                forest[root_j].rank += 1;
            }
        }
    }
};
int main()
{
    //std::vector<disjoint_set> dsets;
    int t;
    int n;
    int d;
    typedef std::vector<int> line;
    std::cin>>t;
    for (int num = 1; num <= t; num++) 
    {
        std::cin>>n;
        disjoint_sets dsets(n);
        std::vector<line> lines;
        std::vector<edge> edges;
        std::vector<edge> mst;
        for (int i = 0; i<n; i++)
        {
            line l;
            for(int j= 0; j<n; j++)
            {

                std::cin>>d;
                l.push_back(d);

            }
            lines.push_back(l);
        }

        for(int i = 1; i<=n; i ++)
        {
            for (int j = i + 1; j<=n; j++)
            {
                edge e;
                e.u_ = i;
                e.v_ = j;
                e.weight_ = lines[i - 1][j -1 ];
                edges.push_back(e);
               //  std::cout<<e.u_<<" "<<e.v_<<" "<<e.weight_<< std::endl;

            }
        }
        // std::cout<< edges.size();
        std::sort(edges.begin() , edges.end());
        //std::cout<<std::endl;
        /*
           for (auto it = edges.begin();it != edges.end(); it++)
           {

           std::cout<<it->weight_<<std::endl;
           }
           */
        //start the kruskal algorithm
        long long int min_weight = 0;
        for(auto &e : edges)
        {

            if ( dsets.find(e.u_ - 1 ) != dsets.find(e.v_ - 1))
            {
                //e.merge_node();
                mst.push_back(e);
                min_weight += e.weight_;
                dsets.merge(e.u_ - 1  , e.v_ - 1);
            }

        }

        std::cout<<"Case #"<<num<<":"<<std::endl;
        //std::cout<<"weight "<<min_weight<<std::endl;
        std::sort(mst.begin(), mst.end(),edge::sort);
        for (auto i = 0; i<mst.size(); i++)
        {

            std::cout<<mst.at(i).u_<<" "<<mst.at(i).v_<<std::endl;

        }
        std::cout<<std::endl;
    }
    return 0;
}
