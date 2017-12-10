//
// Created by manish on 01.12.16.
//

#ifndef ALGORITHMS_GREEDY_ALGORITHMS_H
#define ALGORITHMS_GREEDY_ALGORITHMS_H

#include <vector>

/* first - weight
 * second - length
 */

/*class GreedyAlgorithms
{
public:
    virtual bool operator()(std::pair<int,int> job1, std::pair<int,int> job2)  = 0;
};

 */
class GreedyAlgorithmsWeightLengthDiff
{
public:
    bool  operator()(std::pair<int , int> job1 , std::pair<int, int> job2)
    {
        int weight_length_diff_job1 =  job1.first - job1.second;
        int weight_length_diff_job2 = job2.first -  job2.second;
        if( weight_length_diff_job1 > weight_length_diff_job2 )
        {
            return true;
        }
        if( ( weight_length_diff_job1 == weight_length_diff_job2 )  &&  ( job1.first > job2.first ) )
        {
            return true;
        }

        return false;
    }
};


class GreedyAlgorithmsWeightLengthRatio
{
public:
    bool operator()( std::pair<int , int> jobs1 , std::pair<int, int> job2)
    {
        double weight_length_ratio_job1 = static_cast<double> (jobs1.first ) / jobs1.second;
        double weight_length_ratio_job2 = static_cast<double> (job2.first) / job2.second;
        if ( weight_length_ratio_job1 > weight_length_ratio_job2)
        {
            return true;
        }

        if ( ( weight_length_ratio_job1 == weight_length_ratio_job2 ) && ( jobs1.first > job2.first ))
        {
            return true;
        }
        return false;
    }



};


template<typename T>
class ScheduleJobs
{
public:
    ScheduleJobs(std::vector<std::pair<int,int>> jobs)
            : jobs_(jobs)
    {

    }

    void scheduleByGreedyAlgorithm();
    void setJobs(std::vector<std::pair<int, int>> jobs);
    std::vector<std::pair<int, int>> getJobs();
    long int calculateWeightedCompletionTime();

private:
    // first value is weight of the job
    // second value is length of the job
    std::vector<std::pair<int, int>> jobs_;
    T compareMethod_;
};
#endif //ALGORITHMS_GREEDY_ALGORITHMS_H
