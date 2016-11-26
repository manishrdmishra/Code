#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<iterator>
#include <sstream>
#include <algorithm>
using namespace std;

const int MEMORY_SIZE = 16;
const int CODE_SIZE = 101;
const long int MAX_COMMAND = 50000000;
//initialize memory by zero
void initialize_memory(int memory [][MEMORY_SIZE])
{

    for (int j = 0 ; j< MEMORY_SIZE;j++)
    {

        for (int k = 0 ; k< MEMORY_SIZE;k++)
        {
            memory[j][k] = 0;

        }
    }


}

void increase_pc(char dir, int& x, int& y,int count)
{

    switch(dir)
    {

        case 'L':
            x = x- count;
            break;
        case 'U':
            y = y - count;
            break;
        case 'R':
            x =  x + count;
            break;
        case 'D':
            y = y + count;
            break;

        default:

            break;

    }

}

int  execute_code(vector<string> code,int visited[][CODE_SIZE], int memory[][MEMORY_SIZE],int n ,int m, string& out)
{
    int pcx=0,pcy=0;
    char inst;
    char c;
    int mcx=0,mcy=0;
    int count = 1;
    //int loop_start_x = 0;
    //int loop_start_y= 0;
    long int command_counter = 0;
    //bool loop_flag=false;
    //flag which indicated infinite loop
    bool infinite_flag = false;
    //flag which checks for '/' which work like if 
    //bool terminate_flag = false;
    //int previous_value =-1;
    //this x and y save the value of memory location where if check for termianating the loop
    //int x=-1, y=-1;
    //int iteration=0;
    //string out;
    char dir = 'R';
    while ( true)
    {
        if(pcx < 0 || pcy < 0 || pcx >= m || pcy >= n ) 
        {
            break;
        }
if(command_counter >= MAX_COMMAND)
{
infinite_flag = true;
break;
}
        inst = code[pcy][pcx];
        //commands executed for white space it is subtracted in defalut case
        switch(inst)
        {

            case '^':
                mcy++;
                count = 1;
                command_counter++;
                increase_pc(dir,pcx,pcy, count);
                break;
            case 'v':
                mcy--;
                count = 1;
                command_counter++;
                increase_pc(dir,pcx,pcy,count);
                break;
            case '>':
                mcx++;
                count = 1;
                command_counter++;
                increase_pc(dir,pcx,pcy,count);
                break;
            case '<':
                mcx--;
                count = 1;
                command_counter++;
                increase_pc(dir,pcx,pcy,count);
                break;
            case 'U':
                count = 1;
                dir = 'U';
                command_counter++;
                increase_pc(dir,pcx,pcy,count);
                break;
            case 'D':
                count = 1;
                dir = 'D';
                command_counter++;
                increase_pc(dir,pcx,pcy,count);
                break;
            case 'R':
                count = 1;
                dir = 'R';
                command_counter++;
                increase_pc(dir,pcx,pcy,count);
                break;
            case 'L':
                count = 1;
                dir = 'L';
                command_counter++;
                increase_pc(dir,pcx,pcy,count);
                break;
            case '-':
                if( memory[mcy][mcx] == 0)
                {
                    memory[mcy][mcx] = 255;
                }
                else
                {
                    memory[mcy][mcx]--;
                } 
                count = 1;
                command_counter++;
                increase_pc(dir,pcx,pcy,count);
                break;
            case '+':
                if( memory[mcy][mcx] == 255)
                {
                    memory[mcy][mcx] = 0;
                }
                else
                {
                    memory[mcy][mcx]++;
                } 
                count = 1;
                command_counter++;
                increase_pc(dir,pcx,pcy,count);
                break;
            case '.':
                c =static_cast<char>( memory[mcy][mcx]);

                // cout<<"int value: "<<memory[mcy][mcx]<<endl;
                out.push_back(c);
                /* cout<<"string:"<<out<<endl;
                   cout<<"number:"<<memory[mcy][mcx]<<endl;*/
                count = 1;
                command_counter++;
                increase_pc(dir,pcx,pcy,count);
                break;
            case '/':
                command_counter++;
                //command_counter--;
                //cout<<"char: / execute"<<endl;
               /* if(loop_flag == true && iteration == 0)
                {

                    terminate_flag = true;
                    x = mcx;
                    y = mcy;
                    previous_value = memory[mcy][mcx];
                }
*/
                if(memory[mcy][mcx] == 0)
                {
                    count = 2;

                    increase_pc( dir, pcx, pcy , count);

                }
                else
                {
                    count = 1;
                    increase_pc( dir, pcx, pcy , count);
                }
                break;
            default:
                count = 1;
                increase_pc( dir, pcx, pcy , count);

        }


    }
    //in case of infinite loop return 0  
    if(infinite_flag)
    {
        return 0;

    }
    else
    {

        return 1;
    }
}

void  initialize_visited_array(int visited[][CODE_SIZE], int n, int m)

{

    for ( int i = 0;i<n;i++)
    {

        for ( int j = 0;j<m;j++)
        {

            visited[i][j] = false;
        }

    }
}
//void print_input(char code[][CODE_SIZE] ,int n,int m)
void print_input(vector<string> code ,int n,int m)
{
    for ( int j = 0; j<n;j++)
    {

        for(int k = 0;k<m;k++)
        {
            cout<<code[j][k];
        }
        cout<<endl;
    }


}

int main()
{

    int t;
    string str;
    //cin>>t;
    getline( cin, str,'\n');
    t = std::stoi(str);
    for(int i = 1;i<= t ; i ++ )
    {

        int m, n;
        //char code[CODE_SIZE][CODE_SIZE];
        vector<string>code;
        vector< string > vcode(CODE_SIZE);
        int visited[CODE_SIZE][CODE_SIZE];
        int memory[MEMORY_SIZE][MEMORY_SIZE];
        getline(cin,str,'\n');
        istringstream iss(str);
        vector<string> tokens{istream_iterator<string>{iss},
            istream_iterator<string>{}};
        n = std::stoi(tokens[0]);
        m = std::stoi(tokens[1]);
        for (int j=0;j<n;j++)
        {
            getline(cin,str,'\n');
            code.push_back(str);
            //str.copy(code[j],m);

        }
        getline(cin,str,'\n');
        initialize_memory(memory);
        initialize_visited_array(visited,n,m);
        //print_input(code , n,m);
        string out;
        int res = execute_code( code, visited,  memory,n ,m,out);
        cout<<"Case #"<<i<<": ";
        if( res == 0)
        {
            cout<<"endless loop";

        }
        else
        {
            cout<<out;
        }
        cout<<endl;


    }


    return 0;
}
