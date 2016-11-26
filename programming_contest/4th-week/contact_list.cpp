#include<iostream>
#include<cstdlib>
#include<algorithm>

using namespace std;

const int ALPHABET_SIZE = 26; 
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
        void insert (string word);
        int words_with_prefix(string prefix);
    private:
        struct node *head;
};

void Trei::init()
{
    head = new node();
    head->prefix_count = 0;
    head->is_end = false;

}

void Trei:: insert(string word)
{
    node *current = head;
    current->prefix_count++;
    char a[2]={'a','A'};
    for(unsigned int i =0;i<word.length();++i)
    {


        int letter = (int)word[i] - (int)a[i==0];

        if(current->child[letter] == NULL)
        {
            current->child[letter] = new node();

        }
        current->child[letter]->prefix_count++;
        current = current->child[letter];
    }
    current->is_end = true;

}

int Trei::words_with_prefix(string prefix)
{
    node * current = head;
    char a[2] ={'a','A'};
    for( unsigned int i = 0;i<prefix.length();++i)
    {
        if(current->child[((int) prefix[i] - (int)a[i==0])] == NULL)
        {
            return 0;

        }
        else
        {
            current = current->child[((int)prefix[i] - (int)a[i==0])];
        }
    }
    return current->prefix_count;

}



int main()
{
    int t;
    cin>>t;
    for(int i = 0;i<t;++i)
    {
        int n;
        Trei td;
        td.init();
        cin>>n;
        std::vector<string> contacts;
        for(int j= 0; j<n;++j)
        {
            string contact;
            cin>> contact;
            contacts.push_back(contact);
            td.insert(contact);

        }
        int count =0,total_count=0;
        for(auto it = contacts.begin();it != contacts.end(); ++it)
        {

            count = td.words_with_prefix(*it);
            if(count > 1)
            {
total_count++;
            }
            //cout<<"prefix for word :"<<*it<<" "<<count<<endl;

        }

        cout<<"Case #"<<i+1<<": "<<total_count<<endl;
    }
    return 0;
}
