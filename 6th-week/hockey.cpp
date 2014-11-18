#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;

const int MAX  = 10005;
class hockey 
{
    public:
        hockey(int n, int m):al(MAX)
    {

        nodes = n;
        edges = m;
    l =0;
    } 
        void input();
        void sortBySize();    
        void printData(int id);
        void searchLargestSet();
        void printLargestSet();


    private:
        int nodes;
        int edges;
        int l;
        vector<set<int> > al;
       // vector<set<int> > sorted_al;


};
struct greater_than 
{
    inline bool operator ()( set<int> a, set<int> b)
    {

        return a.size()>b.size();

    }
};

void hockey::printLargestSet()
{

    for(auto it = al[l].begin();it != al[l].end();it++)
    {
        cout<<*it<<" ";

    }

}
void hockey::searchLargestSet()
{


    for( int i = 0;i< nodes; i ++)
    {

        set<int> s = al[i];
        int count = 0;
        for( int j  = 0;j < nodes;j++)
        {
            bool found = true;
            for(auto it1 = s.begin();it1 != s.end();it1++)
            {
                if(al[j].find(*it1) == al[j].end())
                {
                    found = false;
                    break;
                }

            }
            if(found == true)
            {
                count++;

            }


        }
        if( count>= s.size())
        {
            l = i;
            break;
        }

    }

}
void hockey::sortBySize()
{
    //sorted_al = al;
    std::sort(al.begin(),al.end(),greater_than());
}

void hockey::printData(int id)
{
    cout<<"\n graph \n";
    std::vector<set<int>> al_;
    if ( id == 0)
    {
        al_ =  al;
    }

    for (auto i = 0;i<nodes; i++) 
    {
        cout<<i<<"--> ";
        for( auto it =  al_[i].begin();it != al_[i].end();it++)
        {
            cout<<*it<<" ";

        }
        cout<<endl;

    }

}
void hockey::input()
{
    for (int j = 0;j< nodes;j++)
    {
        al[j].insert(j + 1);
    }

    for (int j = 1;j<= edges;j++)
    {

        int a, b;
        cin>>a>>b;
        al[a - 1].insert(b );
        al[b - 1].insert(a);

    }



}


int main()
{

    int t;
    cin>>t;
    for (int i = 1; i<=t; i++)
    {

        int n, m;
        cin>>n>>m;
        hockey h(n,m);
        h.input();
    //    h.printData(0);
        h.sortBySize();
     //   h.printData(0);
        h.searchLargestSet();
        cout<<"Case #"<<i<<": ";
        h.printLargestSet();
        cout<<endl;

    }
    return 0;
}
