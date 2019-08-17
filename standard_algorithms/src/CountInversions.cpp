//
// Created by manish on 14.10.16.
//

#include "CountInversions.h"
long long int  CountInversions::sortAndCount(int* list, int low , int high)
{
    if ( high - low < 1)
    {
        return 0;
    }
    int mid = ( low + high ) / 2;
    long long int inversions_in_left_part =  sortAndCount(list,low, mid);
    long long int inversions_in_right_part =  sortAndCount(list,mid + 1, high);
    long long int inversion_in_cross_left_right = mergeAndCount(list, low ,mid, mid + 1, high );
    return ( inversions_in_left_part + inversions_in_right_part + inversion_in_cross_left_right);
}
long long int CountInversions::mergeAndCount(int *list, int left_low, int left_high, int right_low, int right_high)
{
    long long int count = 0;
    bool copyRightArray = false;
    bool copyLeftArray = false;
    int i  = left_low;
    int j = right_low;
    int* temp;
    temp = new int[right_high - left_low + 1] ;
    //temp = {0};
    int total_elements_to_merge = ( right_high - left_low  + 1 );
    int k = 0;
    for ( k = 0 ; k < total_elements_to_merge ; k++)
    {
        if (list[i] <= list[j] )
        {
            temp[k] = list[i];
            i++;
        }
        else
        {
            temp[k] = list[j];
            j++;
            // add the total number of elements remaining in left array
            count = count + (left_high - i + 1);
        }
        if( i > left_high )
        {
            copyRightArray = true;
            break;
        }
        if ( j > right_high)
        {
            copyLeftArray = true;
            break;
        }
    }



    // copy left array
    if ( copyLeftArray == true)
    {
        for (int l = i; l <= left_high; l++) {
            temp[++k] = list[l];
        }
    }

    if ( copyRightArray == true)
    {
        // copy right array
        for ( int r = j; r <= right_high; r++)
        {
            temp[++k] = list[r];
        }

    }
    // copy the content of the temporary array in to original array
    int c = 0;
    //std::cout<<"\n copying array \n";
    for ( int k = left_low ; k <= right_high ; k++)
    {
        list[k] = temp[c];
        // std::cout<<list[k]<<" "<<temp[c]<<"   "<<k << "  "<<c<<std::endl;
        c = c + 1;
    }
    delete[] temp;
    // std::cout<<" count : " << count<< std::endl;
    return count;
}
