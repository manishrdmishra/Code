#include<iostream>

using namespace std;
const int N = 20;
const int debug = 0;
//www.geeksforgeeks.org/backtracking-set-3-n-queen-problem/


bool isSafe ( int board[N][N] , int row , int col,int max_row)
{

    //check  prevois rows
    for ( int i = 0; i<= max_row; i++)
    {

        if(board[i][col])
        {

            return false;
        }
    }
    // from right to left in upper sqare
    for ( int i= row , j= col; i>=0 && j>=0; i--,j--)
    {
        if( board[i][j])
        {
            return false;
        }

    }
    //lower part of 1st diagonal 
    for ( int i= row , j= col; i<=max_row && j<=max_row; i++,j++)
    {
        if( board[i][j])
        {
            return false;
        }

    }
    // diag from left to right upper part
    for (int i= row , j= col; i>=0 && j<= max_row; i--,j++)
    {
        if( board[i][j])
        {
            return false;
        }

    }

    // diag from left to right lower part
    for (int i= row , j= col; i<=max_row && j>=0 ; i++,j--)
    {
        if( board[i][j])
        {
            return false;
        }

    }
    return true;
}

bool solveNQUtil ( int board[N][N] , int qrow[],int row,int max_row)
{

    if( row > max_row)
    {
        return true;
    }

    if(qrow[row])
    {
        if(debug)
            cout<<"queen found at row:"<<row<<endl;
        if(  solveNQUtil ( board ,qrow, row + 1, max_row) == true)
        {
            return true;

        }

    }


    for (  int i = 0 ; i<= max_row; i++)
    {
        if( isSafe(board,row,i,max_row))
        {

            if(debug)
                cout<<"queen possible pos:"<<row<<" " <<i<<endl;
            board[row][i]= 1;

            if( solveNQUtil ( board ,qrow, row+ 1, max_row) == true)
            {

                return true;

            }

            if(debug)
                cout<<"queen possible pos are failed:"<<row<<" " <<i<<endl;
            board[row][i] = 0;
        }
        /*
        if(i == max_row)
        {
            return false;

        }
        */
    }
   
    return false;
}

void initialize( int board[][N] ,int row[], int n)
{

    for ( int i = 0; i< n ; i++)
    {

        for ( int j = 0; j< n ; j++)
        {

            board[i][j] = 0;
        }

    }
    for( int i = 0 ; i<n ; i ++)
    {

        row[i] = 0;

    }

}
void printBoard(int board[N][N] , int n)
{

    if(debug)
        cout<<"board"<<endl;
    for ( int j = 0 ; j<n; j++)
    {

        for ( int k = 0; k<n; k++)
        {
            if( board[j][k])
            {
                cout<<'x';
            }
            else
            {

                cout<<'.';
            }
        }

        cout<<endl;
    }

}
bool intputBoard ( int board[N][N],int row[], int n)
{

    bool flag = true;
    for ( int j = 0; j<n;j++)
    {
        for ( int k = 0;k<n;k++)
        {
            char ch;
            cin>>ch;
            if(ch == 'x')
            {
                if(isSafe(board,j,k,n - 1) && !row[j])
                {

                    row[j] = 1;
                }
                else
                {

                    flag = false;

                }

                board[j][k] =1;
            }
            else
            {

                board[j][k] = 0;
            }

        }
    }
    return flag;
}
int main()
{

    int t;
    cin>>t;
    for ( int i = 1;i<= t; i++)
    {
        int n;
        bool flag = true;
        int board[N][N];
        cin>>n;
        int row[N];
        initialize(board,row, n);
        flag = intputBoard(board,row,n);
        // printBoard(board,n);
        cout<<"Case #"<<i<<":"<<endl;
        if(flag != false)
        {
            flag =  solveNQUtil( board ,row, 0,n -1);
            if( flag == true)
            {
                printBoard(board,n);
            }
        }
        if(flag == false)
        {

            cout<<"not possible"<<endl;
        }
    }
    return 0;
}

