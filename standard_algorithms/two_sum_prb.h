//
// Created by manish on 13.11.16.
//
#ifndef ALGORITHMS_TWO_S_UM_PRB_H
#define ALGORITHMS_TWO_S_UM_PRB_H

#include <unordered_set>
#include <string>
#include <fstream>
#include <omp.h>
#include <vector>
#include <sstream>

class TwoSumProblem
{

public:
    void initializeHashMapFromFile(std::string file_name);
    void initializeTargetList(long low, long high);
    long getNumberOfTargets();
private:
    std::unordered_multiset<long> hashed_data_;
    std::vector<long> target_;

};

void TwoSumProblem::initializeHashMapFromFile(std::string file_name)
{
    std::ifstream input_file(file_name);
    std::string line;
    long num = 0;
    if(input_file.is_open())
    {
        while(getline(input_file,line))
        {
            std::istringstream number_iss(line);
            number_iss>>num;
            //std::cout<<"inserted : "<< num << std::endl;
            hashed_data_.emplace(num);
        }
    }
    std::cout<<"initialization of hash map is done\n";
}
void TwoSumProblem::initializeTargetList(long low, long high)
{
    for (long i = low ; i<=high; i++)
    {
        target_.push_back(i);
    }

    std::cout<<"initialization of target list is done\n";
}
long TwoSumProblem::getNumberOfTargets()
{
    long count = 0;
    int increment[] = {0, 1};
        #pragma omp parallel for num_threads(4)
        for ( int i = 0; i < target_.size(); i++)
        {

           // std::cout<<"processing : "<< target_[i] << std::endl;
            bool unique_element_found = false;
            for (auto data_it= hashed_data_.begin(); ( data_it != hashed_data_.end() ); )
            {
                auto repeated_keys = hashed_data_.count(*data_it);
                // search for t - x
                auto second_element_it = hashed_data_.find( target_[i]  -  ( *data_it ) );
                bool second_element_found =  ( second_element_it != hashed_data_.end());
                bool check_uniqueness = (  second_element_it != data_it);
                bool unique_element_found = ( second_element_found && check_uniqueness);
                if( unique_element_found)
                {
#pragma omp atomic
                    count = count + increment[unique_element_found == true];
                    //        std::cout<<"count : "<< count << " found "<<std::endl;
                    break;
                }
                // std::cout<<"count : "<< count << std::endl;
                std::advance(data_it,repeated_keys);
            }
            //std::cout<<"count : "<< count << std::endl;
        }
    std::cout<<"count : "<< count << std::endl;
    return  count;
}
#endif //ALGORITHMS_TWO_S_UM_PRB_H
