#include<iostream>
#include<vector>

using namespace std;


struct rational
{
    rational(int a = 0 , int b = 1)
    {

        numerator = a;
        denominator = b;
    }
    rational operator+( rational x)
    {
        rational y;
        if( denominator == x.denominator)
        {
y.numerator = numerator + x.numerator;
y.denominator = denominator ;
        }
        else
        {
        y.numerator = ( numerator * x.denominator)+(x.numerator * denominator);
        y.denominator = denominator *  x.denominator;
        }
        return y;
    }
    // std::ostream& operator<<(std::ostream& out);
    int numerator;
    int denominator;

};
std::ostream& operator<<(std::ostream& out, const rational& x)
{
    return out<<x.numerator<<"/"<<x.denominator;
}
rational find_probability(int n)
{
    rational p[50][30];
    int sides = 20;
    p[1][0] = rational(1,1);
    for(int j = 1;j<=15;j++)
    {
        if(j>6)
        {
            p[1][j] = 0;
        }
        else
        {
            p[1][j] = rational(6-j + 1, 6);
        }
        cout<<p[1][j]<<"  ";
    }
    for(int i = 2; i<=3;i++)
    {
        //p[i][0] = 0;
        cout<<"\n****************\n";
        for (int j= 0;j<=15;j++)
        {
            rational x(0,1);
            for(int k = 1;k<=sides;k++)
            {
                if(k>j) 
                {

                    x = x+rational(1,1*sides);
                }
                else
                {
                    x = x + rational(p[i-1][j-k].numerator , p[i-1][j-k].denominator*sides);
                }
            }

            p[i][j] = x;
            cout<<p[i][j]<<" ";
        }

    }
    return p[3][15];
}

int main()
{
    rational x = find_probability(3);
    cout<<x.numerator <<" "<< x.denominator<<endl;
}
