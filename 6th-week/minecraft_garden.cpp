#include<iostream>
#include<algorithm>
#include<queue>
#include<cmath>
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

    if( no_neighbour || garden[n.first][n.second] == MAX)
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
            int x = neighbour.first;
            int y = neighbour.second;
            if((visited[x][y]== true)||  (x == -1 && y == -1))
            {
                continue;

            }
            if( garden[tile.first][tile.second] >= garden[neighbour.first][neighbour.second] )
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
            if(debug)
                cout<<"water is not reachable at"<<it->first<<it->second<<endl;

            return false;
        }
    }

    return true;

}
void printGarden(int garden[][N])
{
    cout<<"*** garden ***"<<endl;
    for ( int i = 0 ; i< ROWS;i++)
    {
        for ( int j = 0;j<COLS; j++)
        {
            if(garden[i][j]== 47)
                cout<<"_";
            else
            {
                cout<<garden[i][j]<<" ";
            }


        }

        cout<<endl;
    }

}
void printvisited(bool garden[][N])
{
for ( int i = 0 ; i< ROWS;i++)
    {
        for ( int j = 0;j<COLS; j++)
        {
            if(garden[i][j])
                cout<<"1";
            else
                cout<<"0";


        }

        cout<<endl;
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
        long int count = 1;
        bool visited[N][N];
        std::vector<std::pair<int, int> > plants;
        vector<std::pair<int, int>  > tiles;
        vector <int> range;
        cin>>h>>w;
        if(debug)
            cout<<"h:w "<<h<<w<<endl;
        char ch;
        for(int j=0;j<ROWS;j++)
        {
            for(int k = 0;k<COLS;k++)
            {

                cin>>ch;
                if(ch == '_')
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
        printGarden(garden);
        cout<<"plants locations"<<endl;
         for( int j = 0;j<plants.size();j++)
           {
               cout<<plants[j].first<<"  "<<plants[j].second<<endl;
           }

        // produce the list and check for valid configuration
        int bits = std::log(h);
        cout<<"bits req:"<<bits;

        int v = h; // 32-bit word to find the log base 2 of
        int r = 0; // r will be lg(v)

        while ( v != 0) // unroll for more speed...
        {
            r++;
            v = v>>1;
        }
        cout<<"total bits req:"<<r;
        int total_bits = tiles.size() * r; 
        int max = pow(2,total_bits);
        for(int l = 0 ;l< max; l++)
        {
            int z = l;
            for(int j =0;j<tiles.size();j++)
            {

                int x = tiles[j].first;
                int y = tiles[j].second;
                switch(r)
                {
                    case 1:


                        garden[x][y] = z & 0x01;
                        z = z>>1;
                        break;
                    case 2:
                        garden[x][y] = z & 0x03;
                        z = z>>2;
                        break;
                    case 3:
                        garden[x][y] = z & 0x07;
                        z = z>>3;
                        break;
                    default:
                        break;

                }
                if(debug)
                {

                    // cout<<" x : y : value"<<x <<" "<<y<<" "<<garden[x][y]<<endl;
                }

                //cout<<myints[i]<<" ";
                //count++;
            }
            printGarden(garden);

            traverse_tiles( garden ,visited,s );
printvisited(visited);
bool valid = is_valid(visited,plants);
            if(valid)

            {
                if( debug)
                    cout<<"found a valid configuration"<<endl;

                count++;
            }

        } 

        cout<<"Case #"<<i<<": "<<count<<endl;
    }
    return 0;
}
