#include<iostream>
#include<cmath>
using namespace std;
const long long   MAX = 10000000;

class Loan
{
    public:
        Loan(long long l, long long r, long long p, long long y)
        {
            l_ = l;
            r_ = r;
            p_ = p;
            y_ = y;


        }
        long long  max_loan_paid(long long min, long long max);
        int max_integral_rate();
        long long min_integral_monthly_payment();
        long long outstanding_amount(long long l,long long r , long long p, int y);
    private:
        long long l_;
        long long p_;
        int r_;
        int y_;
};

long long Loan:: max_loan_paid(long long min, long long max)
{
    long long current_amount;
    long long current_outstanding;
    while ( min < max)
    {
       current_amount= (min + max ) / 2;
        current_outstanding = outstanding_amount(current_amount,r_,p_,y_);
        cout<<"current outstanding for amount :"<<current_outstanding<<":"<<current_amount<<endl;

        if(current_outstanding == 0)
        {
            break;
        }
        else if ( current_outstanding > 0)
                {
                max = current_amount- 1;

                }
                else
                {
                min = current_amount+ 1;
                }

                }

            return current_amount;
                }


                long long Loan::outstanding_amount(long long l,long long r, long long p,int y)
                {
                long long current_amount = l;
                int months = y * 12;
                double j = r/100;

                for(int i =0;i<months;i++)
                {
                    current_amount -= p;
                    current_amount = current_amount * ( 1 + j);

                }
                return current_amount;
                }
int main()
{
    int t;
    cin>>t;
    cout<<MAX;
    for(int i = 1; i<=t ; i++)
    {
        long long l, r, p, y;
        cin>>l>>r>>p>>y;
        Loan loan ( l,r,p,y);
        long long m =loan.max_loan_paid(1,MAX);
        cout<<"l max :"<<m<<endl;

    }
    return 0;
}
