#include<iostream>
#include<vector>

struct edge{
    int x1;
    int y1;
    int x2;
    int y2;

};
/*int is_inpolygon (int nvert, std::vector<std::pair<int,int>> &vertices, int test_x , int test_y)
{
    int c = 0;
    for( int i = 0; i<nvert; i++)
    {

        if( (( edges[i].y1 > test_y) != ( edges[i].y2 > test_y))&& ( test_x < ( edges[i].x2 - edges[i].x1) * ( test_y - edges[i].y1)/(edges[i].y2 - edges[i].y1) + edges[i].x1))
        {

            c = !c;
        }

    }
    return c;
}
*/
int
cn_PnPoly( int n, std::vector<std::pair<int,int> > &V, int test_x , int test_y)
{
    int    cn = 0;    // the  crossing number counter

    // loop through all edges of the polygon
    for (int i=0; i<n; i++) {    // edge from V[i]  to V[i+1]
       if (((V[i].second <= test_y) && (V[i+1].second > test_y))     // an upward crossing
        || ((V[i].second > test_y) && (V[i+1].second <=  test_y))) { // a downward crossing
            // compute  the actual edge-ray intersect x-coordinate
            float vt = (float)(test_y  - V[i].second) / (V[i+1].second - V[i].second);
            if (test_x <  V[i].first + vt * (V[i+1].first - V[i].first)) // P.x < intersect
                 ++cn;   // a valid crossing of y=P.y right of P.x
        }
    }
    return (cn&1);    // 0 if even (out), and 1 if  odd (in)

}
void convertToVertices(std::vector<edge> &edges , std::vector< std::pair< int, int> > &vertices)
{
    int count = 1;
    vertices.push_back({edges[0].x1,edges[0].y1});
    vertices.push_back({edges[0].x2,edges[0].y2});
    edges.erase(edges.begin());
    while( edges.size() )
    {
        for(int i = 0,j = count;i<edges.size();i++)
        {
            if(edges[i].x1 == vertices[j].first && edges[i].y1 == vertices[j].second)
            {
                vertices.push_back({edges[i].x2 , edges[i].y2});
                edges.erase(edges.begin() + i);
                count++;

            }
            else if(edges[i].x2 == vertices[j].first && edges[i].y2 == vertices[j].second)
            {

                vertices.push_back({edges[i].x1 , edges[i].y1});
                edges.erase(edges.begin() + i);
                count++;
            }

        }
    }

}
void printVertices(std::vector< std::pair< int , int> > &vertices)
{

    std::cout<<"vertices in order \n";
    for(auto it = vertices.begin() ; it != vertices.end()  ; it++)

    {
        std::cout<<it->first<<"   "<<it->second<<std::endl;
    }
}
int main()
{
    int t;
    std::cin>>t;
    for(int i = 1; i<=t ; i++)
    {
        int x_test, y_test,n;
        std::cin>>x_test>>y_test>>n;
        std::vector<edge > edges;
        std::vector<std::pair<int, int> > vertices;
        for(int j = 0; j<n; j++)
        {
            edge e;
            std::cin>>e.x1>>e.y1>>e.x2>>e.y2;
            edges.push_back(e);

        }
       convertToVertices(edges, vertices); 
    //   printVertices(vertices);
              int res = cn_PnPoly(n, vertices, x_test, y_test);
        if(res == 1)
        {
            std::cout<<"Case #"<<i<<": jackpot";

        }
        else
        {

            std::cout<<"Case #"<<i<<": too bad";
        }
        std::cout<<"\n";
    }
    return 0;
}
