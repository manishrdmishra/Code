//
// Created by manish on 02.12.16.
//


#include <limits>
#include <gtest/gtest.h>

#include <fstream>
#include "greedy_algorithms.h"
#include "greedy_algorithms.cpp"

TEST(ScheduleJobs,test1)
{

    std::vector<std::pair<int,int>> jobs;
    std::ifstream file_stream{"/home/manish/git/Documents/fifth_sem/coursera/algorithms-2/week-1/jobs.txt"};
    if(file_stream.is_open())
    {

        int number_jobs{0};
        int weight{0}, length{0};
        file_stream >> number_jobs;

        for(int i = 0; i<number_jobs ; ++i)
        {
            file_stream >>  weight >> length;
            jobs.push_back({weight, length});
        }

    }

    ScheduleJobs<GreedyAlgorithmsWeightLengthDiff> job_scheduler1{jobs};
    long int weighted_completion_time{0};
    GreedyAlgorithmsWeightLengthDiff weight_length_diff_greedy_algorithm; // = new GreedyAlgorithmsWeightLengthDiff;
    job_scheduler1.scheduleByGreedyAlgorithm();
    weighted_completion_time = job_scheduler1.calculateWeightedCompletionTime();

    std::cout<<"weighted compeltion time : "<<weighted_completion_time<<std::endl;

   // GreedyAlgorithmsWeightLengthRatio weight_length_ratio_greedy_algorithm;
    ScheduleJobs<GreedyAlgorithmsWeightLengthRatio> job_scheduler2{jobs};
    //job_scheduler.setJobs(jobs);
    job_scheduler2.scheduleByGreedyAlgorithm();
    weighted_completion_time = job_scheduler2.calculateWeightedCompletionTime();

    std::cout<<"weighted compeltion time : "<<weighted_completion_time<<std::endl;

}