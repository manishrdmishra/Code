#include<iostream>
#include<cmath>
using namespace std;
struct Point
{
    double x;
    double y;
    Point( double x_ , double y_  )
    {
        x = x_;
        y = y_;

    }
    Point(){}
};
int choose_three_nearest_multiple(double number)
{
    double ceil_val= 3.0 * std::ceil(number / 3.0);
    double floor_val= 3.0 * std::floor(number / 3.0);
    double chosen_val;
    if( (number - floor_val )< (ceil_val- number))
    {

        chosen_val= floor_val;

    }
    else
    {
        chosen_val= ceil_val;

    }

    return chosen_val;


}
int main()
{

    int t;
    cin>>t;
    for(int i = 1; i<=t; i++)
    {

        Point p1 , p2, p3;
        cin>>p1.x>>p1.y;
        cin>>p2.x>>p2.y;
        cin>>p3.x>>p3.y;
        double area = std::abs(0.5*((p1.x *( p2.y - p3.y)) - ( p2.x * ( p1.y - p3.y)) + (p3.x * ( p1.y - p2.y))));
        long int approx_area =  choose_three_nearest_multiple(area);
        double number = approx_area / 3.0;
        long int approx_number =  choose_three_nearest_multiple(number);
        cout<<"Case #"<<i<<": "<<approx_number<<endl;

    }
    return 0;
}

