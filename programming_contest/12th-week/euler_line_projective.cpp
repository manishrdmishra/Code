#include<iostream>
#include<vector> 
#include<math.h>

using namespace std;

struct Point
{
    double x;
    double y;
    double z;
    Point( double x_ , double y_ , double z_)
    {
        x = x_;
        y = y_;
        z = z_;

    }
    Point(){}
};
Point find_cross_product(Point p , Point  q)
{
    Point r ; 
    r.x = p.y * q.z - q.y * p.z;
    r.y = q.x * p.z - p.x * q.z;
    r.z = p.x * q.y - q.x * p.y;
    return r;

}
Point find_perpendicular(Point p)
{

    Point r;
    r.x = p.y;
    r.y = -p.x;
    r.z = p.z;
    return r;
}
Point normalize_point(Point p)
{
    Point r;
    r.x = p.x/p.z;
    r.y = p.y / p.z ;
    r.z = 1.0;
    return r;
}
Point find_oc(Point p1 , Point p2 , Point p3)
{
    Point d(0 , 0, 1);
    //line through p1 and p2
    Point l1 = find_cross_product(find_cross_product(p1, p2), d);
    Point m1 = find_cross_product(find_perpendicular(l1), p3);
    //line through p1 and p3
    Point l2 = find_cross_product(find_cross_product(p1, p3), d);
    Point m2 = find_cross_product(find_perpendicular(l2), p2);
    Point oc = normalize_point(find_cross_product(m1 , m2));
    return oc;
}
Point find_centriod( Point p1 , Point p2 , Point p3 )
{

    Point r ;
    r.x = (p1.x + p2.x +p3.x )/3;
    r.y = (p1.y + p2.y +p3.y )/3;
    r.z = (p1.z + p2.z +p3.z )/3;
    Point s = normalize_point(r);
    return s;

}

Point find_circumcenter( Point p1 , Point p2 , Point p3 )
{

    //mid point of p1 and p2 and 
    Point mid;
    mid.x = (p1.x + p2.x ) / 2;
    mid.y = (p1.y + p2.y ) / 2;
    mid.z = (p1.z + p2.z) / 2;
     Point d(0 , 0, 1);
    //line through p1 and p2
    Point l1 = find_cross_product(find_cross_product(p1, p2), d);
    Point m1 = find_cross_product(find_perpendicular(l1), mid);
    //mid point of p1 and p3 
    mid.x = (p1.x + p3.x ) / 2;
    mid.y = (p1.y + p3.y ) / 2;
    mid.z = (p1.z + p3.z) / 2;
    Point l2 = find_cross_product(find_cross_product(p1, p3), d);
    Point m2 = find_cross_product(find_perpendicular(l2), mid);
    Point r = find_cross_product(m1 , m2);
    Point s = normalize_point(r);
    return s;

}
int main()
{

    int t;
    cin>>t;
    for(int i = 1; i <= t; i++)
    {

        Point p1 , p2, p3;
        cin>>p1.x>>p1.y;
        cin>>p2.x>>p2.y;
        cin>>p3.x>>p3.y;
        p1.z = p2.z = p3.z = 1.0;
        cout.precision(10);
        Point o;
        o = find_centriod( p1 , p2 , p3 );
        cout<<"Case #"<<i<<":"<<endl;
        cout<<o.x<<" "<<o.y<<endl;
        o = find_oc(p1 , p2 , p3);
        cout<<o.x<<" "<<o.y<<endl;

o = find_circumcenter( p1 , p2 , p3 );

        cout<<o.x<<" "<<o.y<<endl;


    }

    return 0;
}
