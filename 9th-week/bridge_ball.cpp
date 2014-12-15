#include <iostream>

using namespace std;
int main()
{
    int t;
    cin>>t;
    for (int i = 1 ; i<=t ;i++)
    {
        cout<<"Case #"<<i<<":"<<endl;
        int a,b;
        int count = 0;
        bool flatrate = false;
        string str;
        cin>>a>>b;
        count = a;
        getline(cin,str);
        while(true)
        {
            //cin>>str;
            getline(cin,str);
            if(!str.compare("success"))
            {
                break;
            }

            if(!flatrate)
            {
                if(count < b)
                {
                    cout<<"buy_one"<<endl;
                    count += a;
                }
                else
                {
                    cout<<"buy_flatrate"<<endl;
                    flatrate = true;
                }
            }
            else
            {
                cout<<"use_flatrate"<<endl;

            }


        }

      //  getline(cin,str);

    }



    return 0;
}
