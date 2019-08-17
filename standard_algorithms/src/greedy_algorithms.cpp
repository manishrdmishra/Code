//
// Created by manish on 01.12.16.
//

#include "../i nclude/greedy_algorithms.h"
#include <algorithm>


// GreedyAlgorithm is a class which specify how to select a
// job from given two jobs in greedy fashion
template<typename T>
void ScheduleJobs<T>::scheduleByGreedyAlgorithm()
{
    std::sort(jobs_.begin(), jobs_.end(), compareMethod_);
}

template<typename T>
long int ScheduleJobs<T>::calculateWeightedCompletionTime()
{
    long int total_time{0};
    long int weighted_sum{0};
    for ( auto it = jobs_.begin(); it != jobs_.end(); ++it)
    {
        total_time += it->second;
        weighted_sum += ( total_time ) * it->first;

    }
    return weighted_sum;
}
template<typename T>
void ScheduleJobs<T>:: setJobs(std::vector<std::pair<int, int>> jobs)
{
    jobs_ = jobs;
}
template<typename T>
std::vector<std::pair<int, int>> ScheduleJobs <T>:: getJobs()
{
    return  jobs_;
};
