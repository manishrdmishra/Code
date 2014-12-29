#include<iostream>


using namespace std;

int main()
{

    int t;
    cin>>t;
    for(int i = 1; i<= t; i++)
    {
        cout<<"Case #"<<i<<":"<<endl;
        int n, m, mid,low,high;
        bool win_flag = false;
        string str;
        cin>>n>>m;
        low = 1;
        high = n;
        getline(cin, str);
        while(win_flag == false)
        {
            if(m>1)
            {
                mid = (low + high )/2;
                cout<<mid<<endl;
                getline(cin, str);
                if(str.compare("fail") == 0)
                {
                    m--;
                    high = mid -1;
                }
                else if(str.compare("retry") == 0)
                {
                    low = mid + 1;
                }
                else
                {
                    win_flag = true;
                }

            } 
            else
            {
                cout<<low<<endl;
                getline(cin, str);
                if(str.compare("retry") == 0)
                {
                    low = low + 1;
                }
                else
                {
                    win_flag = true;
                }

            }

        }
    }

return 0;
}
