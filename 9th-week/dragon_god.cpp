#include<iostream>
#include<set>
#include<queue>

using namespace std;
const long int MAX = 1000000;
struct compare{
    bool operator()(const std::pair<int , int> a, const std::pair<int , int> b)const 
    {

        return (a.second > b.second);

    }
};

int main()
{
    int t;
    cin>>t;

    for (int i = 1;i<=t ; i++)
    {
        std::priority_queue< std::pair<int, int>,vector<std::pair<int,int> >,compare> soldiers;
        int T;
        bool sending = false;
        int count = 1;
        std::pair<int, int>soldier;
        cin>>T;
        cout<<"Case #"<<i<<":"<<endl;
        for(long int k = 0 ;k<MAX ; k++)
        {

            if( k<= T)
            {
                int n;
                int p ;
                cin>>n;
                for (int j = 0; j<n; j++)
                {

                    cin>>p;
                    soldiers.push({count , p});
                    count++;

                }


            }
/* for(auto it1 = soldiers.begin(); it1 != soldiers.end(); it1++)
                    {
cout<<it1->first<<" "<<it1->second<<endl;

                    }
                    cout<<endl;
                    */

            if(k>T && soldiers.size() == 0)
            {
                break;

            }
            if(sending == false)
            {
                if(soldiers.empty() == false) 
                {
                    soldier = soldiers.top();

                                       if(k >= soldier.second)
                    {
                        soldiers.pop();
                        cout<<"send "<<soldier.first<<endl;
                        soldier.second--;
                        sending = true;
                    }
                    else
                    {
                        cout<<"wait"<<endl;

                    }
                }
                else
                {

                        cout<<"wait"<<endl;
                }



            }
            else
            {
                cout<<"wait"<<endl;
                soldier.second--;
            }
            if(soldier.second == 0)
            {
                sending = false;

            }

        }
    }



    return 0;
}
