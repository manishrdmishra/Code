#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

const int MAX = 10;
const int N = 20;
const int ROWS = 4;
const int COLS = 4;
const int debug = 1;
std::pair<int,int> find_neighbour(int garden[][N],std::pair<int,int>tile,int num)
{

    int i = tile.first;
    int j = tile.second;
    std::pair<int,int> n;
    bool no_neighbour = false;

    switch(num)
    {
        case 0:
            if(j>0) 
            {
                n.first = i;
                n.second = j - 1;

            }
            else
            {
                no_neighbour = true;
            }
            break;
        case 1:
            if(i>0) 
            {
                n.first = i -1 ;
                n.second = j; 

            }
            else
            {
                no_neighbour = true;
            }
            break;
        case 2:
            if(j<COLS) 
            {
                n.first = i ;
                n.second = j + 1; 

            }
            else
            {
                no_neighbour = true;
            }
            break;

        case 3:
            if(i<ROWS) 
            {
                n.first = i+1 ;
                n.second = j ; 

            }
            else
            {
                no_neighbour = true;
            }
            break;
        default:
            break;
    }

    if( no_neighbour || garden[n.first][n.second] == '-')
    {

        n.first = -1;
        n.second = -1;

    }
    return n;

}


void traverse_tiles(int garden[][N] ,bool visited[][N],std::pair<int,int>s )
{
    std::pair<int,int> neighbour;
    // bool visited[N][N];
    for(int i =0;i<ROWS;i++)
    {
        for (int j = 0;j<COLS;j++)
        {
            visited[i][j] = false;

        }
    }
    visited[s.first][s.second] = true;

    queue<std::pair<int,int> > q;
    q.push(s);

    while( q.empty() != true)
    {
        std::pair<int,int> tile = q.front();
        q.pop();
        for ( int i =  0 ;i<4;i++)
        {

            neighbour =  find_neighbour(garden,tile,i);

            if(visited[neighbour.first][neighbour.second]== true)
            {

                continue;
            }
            if( garden[tile.first][tile.second] >= garden[neighbour.first][neighbour.second] && visited[tile.first][tile.second])
            {

                visited[neighbour.first][neighbour.second] = true;
                q.push(neighbour);

            }

        }

    }


}
bool is_valid(bool visited[][N], std::vector<std::pair<int, int> > plants)
{

    for ( auto it = plants.begin();it!= plants.end();it++)
    {

        if( visited[it->first][it->second] != true)
        {

            return false;
        }
        return true;
    }


}
int main ()

{
    int t;
    cin>>t;
    for( int i = 1;i<=t;i++)
    {
        int garden[N][N];
        std::pair<int,int> s;
        int h,w;
        long int count = 0;
        bool visited[N][N];
        std::vector<std::pair<int, int> > plants;
        vector<std::pair<int, int>  > tiles;
        cin>>h>>w;
        if(debug)
            cout<<h<<w;
        char ch;
        for(int j=0;j<ROWS;j++)
        {
            for(int k = 0;k<COLS;k++)
            {

                cin>>ch;
                if(ch == '-')
                {
                    garden[j][k] = MAX;
                }
                else if( ch == '*')
                {

                    garden[j][k] = w;
                    s.first = j;
                    s.second = k;

                }
                else if( ch == '?')
                {

                    garden[j][k] = 0;
                    tiles.push_back({j,k});
                }
                else
                {
                    garden[j][k] = ch - '0';
                    plants.push_back({j,k});
                }


            }
        }
        vector <int> range;
        for( int j = 0;j<h;j++)
        {
            range.push_back(j);
        }

        // produce the list and check for valid configuration
        do {
            for(int j =0;j<tiles.size();j++)
            {

                int x = tiles[j].first;
                int y = tiles[j].second;
                garden[x][y] = range[j];
                if(debug)
                {

                    cout<<" x : y : value"<<x <<" "<<y<<" "<<range[j]<<endl;
                }
                //cout<<myints[i]<<" ";
                //count++;
            }

            traverse_tiles( garden ,visited,s );

            if(is_valid(visited,plants))

            {

                count++;
            }

        } while ( std::next_permutation(range.begin(),range.end()) );

        cout<<"Case #"<<i<<": "<<count;
    }
    return 0;
}
