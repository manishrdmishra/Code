/* Dynamic Programming implementation of Box Stacking problem */
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<limits>
#include<vector>
#include<algorithm>
//http://www.geeksforgeeks.org

/* Representation of a box */
const int MAX = 4000;
struct Box
{
    // h –> height, w –> width, d –> depth
    long  int h, w, d;  // for simplicity of solution, always keep w <= d
    Box(long int ih, long int iw, long int id);
    Box(){
        h =w = d=  0;

    }
};
Box::Box( long int ih, long int iw, long int id)
{
    h = ih;
    d = id;
    w = iw;

}
/* Returns the height of the tallest stack that can be formed with give type of boxes */
int maxStackHeight(std::vector< Box> arr, long long int n ,long long int h)
{
    std::vector<Box> rot;
    for (int i = 0; i < n; i++)
    {
        // Copy the original box
        Box b;
        b.h = arr[i].h;
        b.d = arr[i].d;
        b.w  = arr[i].w;
        rot.push_back(b);

        // First rotation of box
        b.h = arr[i].w;
        b.d = std::max(arr[i].h, arr[i].d);
        b.w = std::min(arr[i].h, arr[i].d);
        rot.push_back(b);
        // Second rotation of box
        b.h = arr[i].d;
        b.d = std::max(arr[i].h, arr[i].w);
        b.w = std::min(arr[i].h, arr[i].w);
        rot.push_back(b);
    }

    // Now the number of boxes is 3n
    int   m = 3*n;

        std::sort(rot.begin(),rot.end(),[](Box a, Box b){ return (b.w * b.d) < (a.w * a.d);});

    // Uncomment following two lines to print all rotations
      for (int i = 0; i < m; i++ )
        printf("%d x %d x %d\n", rot[i].h, rot[i].w, rot[i].d);
      
    /* Initialize msh values for all indexes
       msh[i] –> Maximum possible Stack Height with box i on top */
    long long  int msh[m + 1];
    for (int i = 0; i < rot.size(); i++ )
    {
        msh[i] = rot[i].h;
                std::cout<<"h="<<msh[i]<<std::endl; 
    }
    /* Compute optimized msh values in bottom up manner */
    for (int i = 1; i < rot.size(); i++ )
    {
        for (int j = 0; j < i; j++ )
        {
            if ( rot[i].w < rot[j].w &&
                    rot[i].d < rot[j].d &&
                    msh[i] < msh[j] + rot[i].h
               )
            {
                msh[i] = msh[j] + rot[i].h;
                std::cout<<"h="<<msh[i]<<std::endl; 
            }
            if(msh[i] >= h)
                {
                   // std::cout<<"max height: "<<msh[i]<<std::endl;
                    return 1;
                }
        }
    }

                    //std::cout<<"max height: "<<msh[m - 1]<<std::endl;
    return 0;
}
int main()
{
    int t;
    std:: cin>>t;
    for ( int i =1;i<=t ; i++)
    {
        long long int max_h,n;
        std::cin>>max_h>>n;
        std:: vector<Box> arr;
        for( int j = 0 ; j<n;j++)
        {
            long int h,w,d;
            std::cin>>h>>d>>w;
            Box b(h,d,w);
            arr.push_back(b);
        }
        int ret_val= maxStackHeight (arr, n,max_h);
        if(ret_val == 1)
        {
            std::cout<<"Case #"<<i<<": "<<"yes"<<std::endl;
        }
        else
        {

            std::cout<<"Case #"<<i<<": "<<"no"<<std::endl;

        }
    }
    return 0;
}
