#include<iostream>
#include<cmath>
#include<limits>
using namespace std;
const long long   MAX = 10000000;
const int debug = 0;
class Loan
{
    public:
        Loan(double l, double r, double p, double y)
        {
            l_ = l;
            r_ = r;
            p_ = p;
            y_ = y;


        }
        long long max_loan_paid(long long min, long long max);
        long long max_integral_rate(long long min, long long  max);
        long long min_integral_monthly_payment(long long min,long long max);
        double outstanding_amount(double l,double r , double p, int y);
    private:
        double l_;
        double p_;
        int r_;
        int y_;
};
long long Loan::max_integral_rate(long long min, long long max)
{
long long current_rate;
long long previous_rate=0;
    long long current_outstanding = 0;
   // double previous_outstanding = 0 ;
    while ( min <= max )
    {
        if( current_outstanding < 0)
        {
previous_rate = current_rate;
        }
       current_rate=std::ceil(min + max ) / 2;

        current_outstanding = outstanding_amount(l_,current_rate,p_,y_);
        /*
        if( previous_outstanding < 0 && current_outstanding >=0)
        {
current_rate = previous_rate;
break;

        }
        */
//previous_outstanding = current_outstanding;
        if(debug)
        {
        cout<<"rate  min max  outstanding rate"<<min<<":"<<max<<":"<<current_outstanding<<":"<<current_rate<<endl;
        }
        if(current_outstanding == 0 || min == max)
        {
            break;
        }
        
        if ( current_outstanding > 0)
                {
                max = current_rate + 1  ;

                }
                else
                {
                min = current_rate - 1  ;
                }

    }

    if(current_outstanding > 0)
    {
current_rate = previous_rate; 

    }

            return current_rate;
     

}

long long Loan::min_integral_monthly_payment(long long min, long long max)
{
long long current_payment;
long long previous_payment = 0;
    long long current_outstanding;


 //   double previous_outstanding = 0 ;
    while ( min <= max  )
    {
    
        if( current_outstanding < 0)
        {
previous_payment = current_payment;
        }
       current_payment = std::ceil( (max + min ) / 2);
        current_outstanding = outstanding_amount(l_,r_,current_payment,y_);
if(debug)
{
cout<<"m p -- min max  outstanding payment:"<<min<<":"<<max<<":"<<current_outstanding<<":"<<current_payment<<endl;
}
/*
        if( previous_outstanding < 0 && current_outstanding >=0)
        {
current_payment = previous_payment ;
break;

        }
       */ 
//previous_outstanding = current_outstanding;
                if(current_outstanding == 0 || min == max)
        {
            break;
        }
        else if ( current_outstanding > 0)
                {
                min = current_payment + 1   ;

                }
                else
                {
                max = current_payment - 1  ;
                }

                }

    if(current_outstanding > 0)
    {
current_payment = previous_payment;

    }
            return current_payment ;
     

}
long long Loan:: max_loan_paid(long long min, long long max)
{
    long long current_amount;
    long long previous_amount = 0;
//    double previous_outstanding = 0;
    long long current_outstanding;
    while ( min < max - 1 )
    {
        if( current_outstanding < 0)
        {
previous_amount = current_amount;
        }
       current_amount= std::ceil ((min + max ) / 2);
       
        current_outstanding = outstanding_amount(current_amount,r_,p_,y_);
        /*
        if( previous_outstanding < 0 && current_outstanding >=0)
        {
current_amount = previous_amount;
break;

        }
        */
//previous_outstanding = current_outstanding;

       
     if(debug)
     {
        cout<<"ma -- min max  outstanding amount :"<<min<<":"<<max<<":"<<current_outstanding<<":"<<current_amount<<endl;

     }
     if(current_outstanding == 0 || (min == max))
        {
            break;
        }
       
        else   if ( current_outstanding > 0)
                {
                max = current_amount   ;

                }
                else
                {
                min = current_amount  ;
                }

                }
    if(current_outstanding > 0)
    {
current_amount = previous_amount;

    }
 
            return current_amount;
                }


                double Loan::outstanding_amount(double l,double r, double p,int y)
                {
                double current_amount = l;
                int months = y * 12;
                double j = (double )r/100; 
             //   cout<<"\ncurrent amount calculation\n";
                for(int i =0;i<months;i++)
                { current_amount -= p;
                    current_amount = floor(current_amount + (current_amount * j));
               //     cout<<current_amount<<" ";

                }
                return current_amount;
                }
int main()
{
    int t;
    cin>>t;
    //cout<<MAX;
    //cout<<numeric_limits<long long>::max();
    for(int i = 1; i<=t ; i++)
    {
        double l, r, p, y;
        cin>>l>>r>>p>>y;
        Loan loan ( l,r,p,y);
       long long l_max  =loan.max_loan_paid(1,MAX);
long long r_max =loan.max_integral_rate(0,100);
long long p_min = loan.min_integral_monthly_payment( 1, MAX);
//    cout<<"l max :"<<l_max<<endl;
 //       cout<<"r max :"<<r_max<<endl;
//        cout<<"p min :"<<p_min<<endl;

cout<<"Case #"<<i<<": "<<l_max;
if( r_max == 100)
{
cout<<" infinity";

}
else if (r_max < 0)
{
cout<<" impossible";

}
else
{
cout<<" "<<r_max;

}
cout<<" "<<p_min<<endl;
    }
    return 0;
}
