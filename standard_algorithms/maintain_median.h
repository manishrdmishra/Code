//
// Created by manish on 14.11.16.
//

#ifndef ALGORITHMS_MAINTAIN_MEDIAN_H
#define ALGORITHMS_MAINTAIN_MEDIAN_H

#include <vector>
#include <deque>
#include <fstream>
#include <sstream>
#include <queue>
#include <string>

class MaintainMedian
{
public:
   void  readAllNumbersFromFile(std::string file_name);
    long calculateTheSumOfAllMedian();

private:
    std::vector<long > numbers_;
    std::priority_queue<long, std::deque<long> , std::less<long> >  priority_queue_low_;
    std::priority_queue<long, std::deque<long>, std::greater<long> > priority_queue_high_;
};


void MaintainMedian::readAllNumbersFromFile(std::string file_name)
{
    std::ifstream file(file_name);

    std::string line;

    long number;
    if(file.is_open())
    {

        while (getline(file, line))
        {
            std::istringstream number_iss(line);

            number_iss>>number;
            //std::cout<<"read number : "<< number<<std::endl;
            numbers_.push_back(number);

        }
    }

    std::cout<<"reading input is completed\n";

}

template<typename T> void print_queue(T& q)
{
    long count = 0;
    while(count < q.size())
    {
        std::cout << q.top() << " ";
        //q.pop();
        count++;
        if ( count > 100)
        {

            std::cout << '\n';
        }
    }
    std::cout << '\n';
}

long MaintainMedian::calculateTheSumOfAllMedian()
{
    long long total_sum = 0;
    long median_index = 0;
    long median = 0;

   // auto priority_queues[] = {priority_queue_low_, priority_queue_high_};
    for (int i = 1 ; i<= numbers_.size(); i++)
    {

        long current_number = numbers_[i - 1];

        std::cout<<"current number : "<< current_number<<std::endl;
        if(current_number <= priority_queue_low_.top())
        {
            priority_queue_low_.push(current_number);
        }
        else
        {
            priority_queue_high_.push(current_number);
        }


       // priority_queues[current_number > priority_queue_low_.top()].push(current_number);
        if(priority_queue_low_.size() > priority_queue_high_.size() + 1)
        {
            long top_element = priority_queue_low_.top();
            priority_queue_high_.push(top_element);
            priority_queue_low_.pop();
        }
       if(priority_queue_high_.size() > priority_queue_low_.size() + 1)
        {

            long top_element = priority_queue_high_.top();
            priority_queue_low_.push(top_element);
            priority_queue_high_.pop();
        }

        //std::sort(numbers_.begin(), numbers_.begin() + ( i - 1) );
        if( ( i%2)  == 0)
        {

            median_index  = i/2;
        }
        else
        {
            median_index = (i / 2) + 1;

        }
        //median = numbers_[median_index - 1];
        //std::cout<<"median : "<<median;

        if ( priority_queue_low_.size() >= median_index)
        {

            median = priority_queue_low_.top();
        }
        else
        {
            median = priority_queue_high_.top();
        }
        /*std::cout<<"priority queue low \n";
print_queue(priority_queue_low_);

        std::cout<<"priority queue high\n";
        print_queue(priority_queue_high_);
         */
        /*std::cout<<"current median index : "<< median_index<<std::endl;
        std::cout<<"current median : "<< median<<std::endl;
         */
        total_sum = total_sum + median;

    }
    std::cout<<"total sum : "<<total_sum<<std::endl;
    return total_sum;
}
#endif //ALGORITHMS_MAINTAIN_MEDIAN_H
