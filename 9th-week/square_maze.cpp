#include<iostream>
#include<vector>

using namespace std;
const int debug = 0;
vector<int> intToBinary(int s)
{
    vector<int> bin;
    while(s>0)
    {

        int x = s%2;
        bin.push_back(x);
        s = s/2;

    }

    if(debug)
    {
        for(auto it = bin.begin(); it != bin.end(); it++)
        {

            cout<<*it<<" ";

        }
        cout<<endl;
    }
    return bin;
}

int calc_distance(int n,int m, int x, int y, int x_cur, int y_cur,int i)
{
    int dist;
    switch(i)
    {

        case 0:
            if(x_cur > 1)
            {
                x_cur --;
            }
            break;
        case 1:
            if(y_cur < m)
            {
                y_cur ++;
            }
            break;
        case 2:
            if(x_cur < n)
            {
                x_cur ++;
            }
            break;
        case 3:
            if( y_cur > 1)
            {
                y_cur--;
            }
            break;

    }
    /*if( x_cur <1 || x_cur > n || y_cur <1 || y_cur > m)
      {

      dist = -1;


      }
      else
      */
    {

        dist = (x-x_cur)*(x - x_cur) + ( y - y_cur ) * ( y - y_cur);

    }
    return dist;
}
int findDirection(int n, int m,int x, int y,int x_cur, int y_cur,  vector<int> bin)
{
    int dist;
    int max_dist = 0; 
    int dir;
    for(unsigned int i = 0 ; i<bin.size(); i++)
    {
        if(bin[i])
        {
            dist = calc_distance(n,m,x,y,x_cur,y_cur,i);
            /*if(dist == -1)
              {
              dir = 4;
              break;
              }
              */
            if(dist >= max_dist)
            {
                max_dist = dist;
                dir = i;
            }
        }

    }
    return dir;
}
int main()
{
    int t;
    cin>>t;
    for(int i=0 ; i<t; i++)
    {
        cout<<"Case #"<<i+1<<":"<<endl;
        string str;
        int n, m, s;
        int x,y;
        int x_cur, y_cur;
        bool not_found = true;
        int dir;
        cin>>n>>m;
        cin>>x>>y;
        x_cur = x;
        y_cur = y;
        while(not_found)
        {
            cin>>s;
            if(s == 0)
            {

                cout<<"Move "<<endl;
                    continue;
            }
            vector<int> bin = intToBinary(s);
            dir = findDirection(n,m,x,y,x_cur,y_cur,bin);

            switch(dir)
            {
                case 3:
                    y_cur--;
                    if(y_cur >= 1)
                    {
                        cout<<"Move north"<<endl;
                    }
                    break;
                case 2:
                    x_cur++;
                    if(x_cur <= n)
                    {
                        cout<<"Move east"<<endl;
                    }
                    break;
                case 1:
                    y_cur++;
                    if(y_cur <= m)
                    {
                        cout<<"Move south"<<endl;
                    }
                    break;
                case 0:

                    x_cur--;
                    if(x_cur >= 1)
                    {


                        cout<<"Move west"<<endl;
                    }
                    break;
                default:
                    break;



            }
            if( (x_cur <1 || x_cur > n || y_cur <1 || y_cur > m) && ( x != x_cur || y != y_cur))
            {

                cout<<"Finished !"<<endl;
                not_found = false;
                break;


            }
            if(debug)
            {

                cout<<"x =  "<<x_cur<<"  y = "<<y_cur<<endl;
            }

        }

    }


    return 0;
}
