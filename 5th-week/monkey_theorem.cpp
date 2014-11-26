#include <cstdio>
#include <algorithm>
#include <cstring>
#include<iostream>
using namespace std;

#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

const int MAXN = 500000;
class SuffixArray
{
    private:
        string S;
        int N, gap;
        int sa[MAXN], pos[MAXN], tmp[MAXN]; 
        int sof[MAXN];
    public:
        int strcmp( string s  , string t)
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


        bool search( string str)
        {
            int min = 0;
            int max = N ;
            int cmp;
            bool found = false;
            while ( min < max - 1 )
            {
                int  mid = std::ceil(min + max) / 2;
                string tmp = S.substr(sof[mid] , N);
                cmp = strcmp(tmp , str);
                //cmp = tmp[0] - str[0];
                if(cmp == 0)
                {

                    found = true;
                    break;
                }

                else  if(cmp > 0)
                {

                    max = mid  ;
                }
                else
                {
                    min = mid  ;
                }
            }
            /* int s = min;
               max = N;
               while ( min < max - 1)
               {
               int  mid = std::ceil(min + max) / 2;
               string tmp = S.substr(sof[mid] , N);
               cmp = tmp.compare(str);

               if(cmp < 0)
               {

               min = mid ;
               }
               else
               {
               max = mid  ;
               }
               }

               cout<<"s : r" <<s<<" "<<max<<endl;
               return (max - s +1 >=1); 
               */
            return found;
        }

        SuffixArray( string text)
        {
            S = text;
        }
        void buildSA(); 

        bool sufCmp(int i, int j);
        /*
           void buildLCP()
           {
           for (int i = 0, k = 0; i < N; ++i) if (pos[i] != N - 1)
           {
           for (int j = sa[pos[i] + 1]; S[i + k] == S[j + k];)
           ++k;
           lcp[pos[i]] = k;
           if (k)--k;
           }
           }
           */
}; // end namespace SuffixArray
bool SuffixArray::sufCmp(int i, int j)
{
    if (pos[i] != pos[j])
        return pos[i] < pos[j];
    i += gap;
    j += gap;
    return (i < N && j < N) ? pos[i] < pos[j] : i > j;
}
void SuffixArray::buildSA()
{
    N = S.length();
    for (int i =0; i<N;i++)
    {
        sa[i] = i;
        pos[i] = S[i];
    }
    for (gap = 1;; gap *= 2)
    {
        std::sort(sa, sa + N, [this](int i, int j){

                if (pos[i] != pos[j])
                return pos[i] < pos[j];
                i += gap;
                j += gap;
                return (i < N && j < N) ? pos[i] < pos[j] : i > j;




                });
        REP(i, N - 1) tmp[i + 1] = tmp[i] + sufCmp(sa[i], sa[i + 1]);
        REP(i, N) pos[sa[i]] = tmp[i];
        if (tmp[N - 1] == N - 1) break;
    }

    for( int i =0 ;i<N;i++)
    {
        sof[ pos[i] ]  = i ;
    }
    
       cout<<"suffix array\n";
       for( int i =0 ;i<N;i++)
       {
       cout<<sof[i]<<endl;
       }
         
}
int main()
{

    string text;
    getline(cin,text);
    SuffixArray sf(text);
    sf.buildSA();
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
