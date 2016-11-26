#include<iostream>
#include<cmath>


using namespace std;

const int ALPHABETSIZE = 255; 
const int MAX = 50000;
class SuffixArray{

    private:
        string text;
        int n;//length of string 
        int suf[MAX];
        int pos[MAX];
        bool bucketstart[MAX];
        bool bucketstart2[MAX];
        int bucketsize[MAX];
        int bucket[MAX];
    public: 
        SuffixArray(string str)
        {
            text = str;
            n = text.length();

        }
        void initialize();
        void buildSA();
        void printdata();
        int strcmp(string a, string b);
        bool search(string str);


};
int SuffixArray::strcmp( string s  , string t)
{

    int l1 = s.length();
    int l2 = t.length();
    int i = 0;
    while(l1 && l2)
    {
        if( s[i] != t[i])
        {

            return s[i] - t[i];
        }
        i++;
        l1--;
        l2--;

    }

    if(l2 > 0)
    {
        return t[i];

    }
    else
    {
        return 0;

    }
}


bool SuffixArray::search( string str)
{
    int min = 0;
    int max = n ;
    int cmp;
    bool found = false;
    while ( min < max - 1 )
    {
        int  mid = std::ceil(min + max) / 2;
        string tmp = text.substr(pos[mid] , n);
        cmp = strcmp(tmp , str);
        //cmp = tmp[0] - str[0];
        if(cmp == 0)
        {

            found = true;
            break;
        }
        else if( cmp >0)
        {
            max = mid;

        }
        else
        {
            min = mid;
        }


    }
    return found;
}

void SuffixArray::buildSA()
{
    int max_loop = std::log2(n);
    for ( int h = 0;h<=max_loop;h++)
    {
        //  cout<<"in h = "<<h<<endl;
        int pw;
        int l,r;
        for( int i = 0;i<n;i++)
        {

            if(bucketstart[i])
            {

                l =i;
                int  c = l;
                while (bucketstart[++c] == 0 && c<n);
                // r = c - 1;
                r = c;


                //     cout<<"left : right"<<l<<"  "<<r<<endl;
                bucketsize[l] = 0;
                for( int j = l;j<r;j++)
                {

                    suf[ pos[ i] ] = l;
                }
            }
        }
        // cout<<"1st for is done"<<endl;
        for(int i = 0; i<n;i++)
        {
            int d;
            if(bucketstart[i])
            {

                l =i;
                int  c = l;
                while (bucketstart[++c] == 0 && c<n);
                //           r = c - 1;
                r = c;


                for ( int j = l;j<r;j++)
                {
                    pw = 1;
                    for(int k = 1;k<=h;k++)
                    {
                        pw = pw * 2;
                    }

                    d = pos[j] - pw;


                    if( d < 0 || d>= n)
                    {
                        continue;
                    }
                    int k = suf[d];
                    suf[d] = k + bucketsize[k];
                    bucketsize[k]++;
                    bucketstart2[ suf[d] ] = true;
                }

                for(int j = l;j<r;j++)
                {

                    int d = pos[j] -  pw;
                    if( d <0 || d>=n || !bucketstart2[suf[d]])
                    {
                        continue;

                    }
                    //intialize k
                    int k = 0;
                    for(int m = 0;m<n;m++)
                    {

                        if( (m > suf[d]) && ( bucketstart[m] || !bucketstart2[m]))
                        {
                            k = m;
                            break;
                        }

                    }
                    for( int m = suf[d] + 1; m<k;m++)
                    {
                        bucketstart2[m] = false;


                    }
                }
            }
        }

        // cout<<"3rd for is done"<<endl;
        for( int i = 0;i<n;i++)
        {
            pos[ suf[i]] = i;
            bucketstart[ i] = bucketstart[i] || bucketstart2[i];

        }
printdata();
    }
}

void SuffixArray::printdata()
{
    cout<<"\npos-bucketstart-suf--\n";
    for (int i = 0;i< n;++i)
    {

        cout<<pos[i]<< "    "<< bucketstart[i]<<"   "<< suf[i]<<endl;


    }

    cout<<"\n bucket desc\n";
    for(int i = 0;i<ALPHABETSIZE;i++)
    {
        if( bucket[i] != -1)
        {
            cout<<i<<" "<< bucket[i]<<endl;
        }
    }

}
void SuffixArray::initialize()
{

    for(int i = 0; i< ALPHABETSIZE;i++)
    {
        bucket[i] = -1;
    }
    for( int i = 0;i<n; i++)
    {
        int b = bucket[(int)text[i]];
        bucket[(int)text[i]] = i;
        pos[i] = b;

    }
    int c =0;
    for(int d = 0;d<ALPHABETSIZE;d++)
    {
        int i = bucket[d];
        while ( i != -1)
        {
            int j= pos[i];
            suf[i ] = c;
            if( i == bucket[d])
            {
                bucketstart[c] = true;

            }
            else
            {

                bucketstart[c] = false;

            }
            c++;
            i = j;
        } 


    }
    bucketstart[n] = true;
    for ( int i = 0; i<n ; i++)
    {

        pos[ suf[i]] = i;

    }

}


int main ()
{
    /*
       SuffixArray sf("ccbanana");
       sf.initialize();
       sf.buildSA();
       sf.printdata();
       */
    string text;
    getline(cin,text);
    SuffixArray sf(text);
    sf.initialize();
    sf.printdata();
    sf.buildSA();
    sf.printdata();
    int t;
    cin>>t;
    for( int i = 1;i<= t;i++)
    {
        string str;
        cin>>str;
        bool b=   sf.search(str);
        cout<<"Case #"<<i<<": ";
        if( b == true)
        {
            cout<<"yes\n";
        }
        else
        {

            cout<<"no\n";
        }
    }
    return 0;
}
