#include<iostream>
#include<math.h>
#include<vector>
using namespace std;

std::pair<double, double> cal_centroid( vector< std::pair< double, double> > points)
{
    std::pair<double, double> point;
    point.first = (points[0].first + points[1].first +points[2].first) / 3;
    point.second = (points[0].second + points[1].second +points[2].second) / 3;
    return point;
}
std::pair<double, double>  cal_circumcenter( vector< std::pair< double, double> > points)
{

    std::pair<double, double> mid_point1;
    std::pair<double, double> mid_point2;
    //intersection of point 0 and 1
    mid_point1.first = (points[0].first + points[1].first) / 2;
    mid_point1.second = (points[0].second + points[1].second) / 2;

    double a1 = mid_point1.second - points[2].second;
    double b1 = points[2].first - mid_point1.first;
    double c1 = mid_point1.first * points[2].second - mid_point1.second * points[2].first;

    //intersection of point 0 and 2
    mid_point2.first = (points[0].first + points[2].first) / 2;
    mid_point2.second = (points[0].second + points[2].second) / 2;

    double a2 = mid_point2.second - points[1].second;
    double b2 = points[1].first - mid_point1.first;
    double c2 = mid_point1.first * points[1].second - mid_point1.second * points[1].first;
     
    double x = (-c1 * b2 + c2 * b1 ) / ( a1 * b2 - a2 * b1 );
    double y = (- c1 * a2 + c2 * a1 ) / ( b1 * a2 - b2 * a1 );
    return std::pair<double , double >(x, y);

}


std::pair<double, double>  cal_orthocenter( vector< std::pair< double, double> > points)
{

    double m1 ;
    double a1 , b1, c1;
    if( points[0].first == points[1].first)
    {
        m1 = 0;
        a1 = 0 ;
        b1 = 1;
        c1 = -points[2].second;

    }
    else
    {
        m1 = (points[0].second -points[1].second) / ( points[0].first-points[1].first);
        if( m1 == 0 )
        {
            a1 = 1;
            b1 = 0;
            c1 = - points[2].first; 
        }
        
        c1 = points[2].second - m1 * points[2].first; 
    }
    double m2 ;
    double c2;
    if( points[0].first == points[2].first)
    {
        m2 = 0;
        c2 = points[1].second;
    }
    else
    {
        m2 = (points[0].second -points[2].second) / ( points[0].first-points[2].first);
        c1 = points[1].second - m1 * points[1].first; 
    }
    double x = ( c2 - c1 ) / ( m1 - m2 );
    double y = m1*points[2].first + c1;
    return std::pair<double , double > (x , y);

}

int main()
{
    int t;
    cin>>t;
    for(int i = 1 ; i <=t ; i++)
    {
        vector<std::pair<double, double> > points;
        for(int j = 0; j<3 ; j++)
        {
            double x, y;
            cin>>x>>y;
            points.push_back({x, y});
        }
        std::pair<double , double> cnt = cal_centroid( points);
        cout<<cnt.first<<" "<<cnt.second<<"\n";
        cnt = cal_orthocenter( points);
        cout<<cnt.first<<" "<<cnt.second<<"\n";
        cnt = cal_circumcenter( points);
        cout<<cnt.first<<" "<<cnt.second<<"\n";

    }
    return 0;
}
