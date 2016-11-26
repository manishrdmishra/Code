#include<iostream>
#include<cstdlib>
#include<algorithm>

using namespace std;
const long long int MAX_INT = 2147483648;
const int ALPHABET_SIZE = 2; 
struct node 
{

    bool is_end;
    int prefix_count;
    struct node *child[ALPHABET_SIZE];
};
//Reference from algoking
class Trei
{

    public:
        Trei()
        {
            head = NULL;
        }
        void init();
        void insert (vector<int>& word);
        vector<int> nearest_matched_string(vector<int>& prefix);
    private:
        struct node *head;
};

void Trei::init()
{
    head = new node();
    head->prefix_count = 0;
    head->is_end = false;

}

void Trei:: insert(vector<int>& word)
{
    node *current = head;
    current->prefix_count++;
    //char a[2]={'a','A'};
    for(auto it =word.begin();it != word.end();++it)
    {



        int letter = *it;
        if(current->child[letter] == NULL)
        {
            current->child[letter] = new node();

        }
        current->child[letter]->prefix_count++;
        current = current->child[letter];
    }
    current->is_end = true;

}

vector<int> Trei::nearest_matched_string(vector<int>& prefix)
{
    node * current = head;
    //   char a[2] ={'a','A'};
    vector<int> a; 
  //  cout<<"matched bits"<<endl;
    for(auto it =prefix.begin();it != prefix.end();++it)
    {
        int num = *it;
        if(current->child[num] != NULL)
        {
            a.push_back( num);
            //cout<<num<<" ";
        current = current->child[num];
        }
        else
        {
            a.push_back(!(num));
        current = current->child[!num];
    //        cout<<(!num)<<" ";

        }
    }

   // cout<<"matched bits ends here"<<endl;
    return a;          
}

vector<int> bitString(long long int x)
{

    vector<int> ret;
    int count = 0;
    while(x)
    {
        if (x&1)
        {
            ret.push_back(1);
        }
        else
        {
            ret.push_back(0);
        }
        x>>=1;  
        count++;
    }
    while (count++<=31)
    {
        ret.push_back(0);
    }
    reverse(ret.begin(),ret.end());
    ret[0] = 0;
    //cout<<"bits for :"<<x<<endl;
    //cout<<"count value:"<<count<<endl;
   /* for(auto it = ret.begin();it != ret.end();it++)
    {

        cout<<" "<<*it;
    }
    */
    return ret;
}

long long bitToInt(vector<int>& bits)
{
    long long int num =0;
    for (int c : bits)
    {
        num = (num << 1) |  (c); 
    }
  //  cout<<"nearest matched numbere:"<<num<<endl;
    return num;
}
vector<int> notOfBitString(vector<int> ret)
{
 for(auto it = ret.begin();it != ret.end();it++)
    {

 //       cout<<" "<<*it;
        int a = !(*it);
        *it = a;
    }
 /*cout<<"after changing the bits"<<endl;
for(auto it = ret.begin();it != ret.end();it++)
    {
        cout<<" "<<*it;
    }
*/
 ret[0] = 0;
    return ret;

    
}
int main()
{
        Trei td;
        td.init();
        long long int a, c, s;
 vector<int> word ;
        cin>>a>>c>>s;
        word = bitString(s);
            td.insert(word);
           long long  w = s;
        for(int k = 2;k<=10000;k++)
        {
            long long int w_1 = (a * w + c)%MAX_INT;
             word = bitString(w_1);
            w = w_1;
            td.insert(word);
        }
        int n;
        cin>>n;
        //std::vector<string> contacts;
        for(int j= 0; j<n;++j)
        {
            long long int ws;
            cin>> ws;
            vector<int> word = bitString(ws);
            word = notOfBitString(word);
word =  td.nearest_matched_string(word);
/*for(auto it = word.begin();it != word.end();it++)
    {

        cout<<" "<<*it;
    }
*/

                long long max_val = bitToInt(word);
            cout<<"Case #"<<j+1<<": "<<max_val<<endl;

        }


    return 0;
}
