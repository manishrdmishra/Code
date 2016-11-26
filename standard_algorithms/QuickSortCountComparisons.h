//
// Created by manish on 16.10.16.
//

#ifndef ALGORITHMS_MERGESORT_H
#define ALGORITHMS_MERGESORT_H

#include <functional>

class QuickSortCountComparisons
{
public :
    long int partition (int *a ,int  left , int right, int pivot_index);

    long int quickSortComparison(int *a , int left, int right,  std::function < int ( int* , int , int )> chosePivot);

private:
    void swap ( int *a, int *b);
    int   chosePivotByMedian (int *a , int left,int right);

};
int  QuickSortCountComparisons::chosePivotByMedian(int* a , int left ,int right)
{


}
void QuickSortCountComparisons::swap (int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp ;
}

long int QuickSortCountComparisons::partition(int *a, int left,int  right, int pivot_index)
{
    // choose the left most element as pivot
    //int pivot = a[left];

    int pivot = a[pivot_index];
    swap(&a[left], &a[pivot_index]);

    int i = left + 1;
    for (int j = left + 1  ; j <= right ; j++)
    {
        if ( a [j ] < pivot )
        {
            swap(&a[j], &a[i]);
            i = i + 1;
        }
    }
    swap(&a[left], &a[i - 1]);
    return ( i -1 );
}

long int QuickSortCountComparisons::quickSortComparison(int *a, int left,int right,std::function < int ( int* , int , int )> chosePivot)
{

    long int count = 0;
    if ( right - left < 1)
    {
        return 0;
    }



    int initial_pivot_index = chosePivot(a,left,right);
    int pivot = partition(a, left, right,initial_pivot_index) ;

    // std::cout<<" pivot : " << pivot << std::endl;
    long int comparision_in_left_part = quickSortComparison(a , left, pivot - 1,chosePivot ) ;
    long int  comparision_in_right_part =  quickSortComparison(a, pivot + 1, right,chosePivot);
    //return ( comparision_in_left_part  + comparision_in_right_part + (right - left ) );
    return ( comparision_in_left_part  + comparision_in_right_part + (right - left ));

}
#endif //ALGORITHMS_MERGESORT_H
