//
// Created by manish on 02.12.16.
//

#include <limits>
#include <gtest/gtest.h>

#include <fstream>
#include "../include/MinimumSpanningTree.h"
// Minimum spanning trees test methods
TEST(ScheduleJobs,test1) {

    std::ifstream file_stream{"/home/manish/git/Documents/fifth_sem/coursera/algorithms-2/week-1/mst_test_two.txt"};
    if (file_stream.is_open())
    {

        unsigned long number_vertex{0};
        int number_edges{0};

        int  start_vertex{0}, end_vertex{0}, weight{0};


        file_stream >> number_vertex >> number_edges;

        std::vector<std::vector<std::pair<int, long >>> graph(number_vertex);

        for (int i = 0; i < number_edges; ++i)
        {
            file_stream >> start_vertex>> end_vertex >> weight;
            // to maintain zero indexing througout the code
            // one is subtracted from the start and end vertex
            --start_vertex;
            --end_vertex;
            graph[start_vertex ].push_back({end_vertex, weight});
            graph[end_vertex ].push_back({start_vertex, weight});
        }

        MinimumSpanningTree<long, PrimsMinimumSpanningTree<long>> minimum_spanning_tree(graph);
     //   minimum_spanning_tree.printGraph();
        long int mst_cost = minimum_spanning_tree.calculateMST();
        std::cout<<"\n minimum spanning tree cost : " << mst_cost << std::endl;

        ASSERT_EQ(mst_cost, -5);
    }


}
TEST(ScheduleJobs,test2)
{

    std::ifstream file_stream{"/home/manish/git/Documents/fifth_sem/coursera/algorithms-2/week-1/mst_test_one.txt"};
    if (file_stream.is_open())
    {

        unsigned int number_vertex{0};
        unsigned int number_edges{0};

        int  start_vertex{0}, end_vertex{0}, weight{0};


        file_stream >> number_vertex >> number_edges;

        std::vector<std::vector<std::pair<int, long >>> graph(number_vertex);

        for (int i = 0; i < number_edges; ++i)
        {
            file_stream >> start_vertex>> end_vertex >> weight;
            // to maintain zero indexing througout the code
            // one is subtracted from the start and end vertex
            --start_vertex;
            --end_vertex;
            graph[start_vertex ].push_back({end_vertex, weight});
            graph[end_vertex ].push_back({start_vertex, weight});
        }

        MinimumSpanningTree<long, PrimsMinimumSpanningTree<long>> minimum_spanning_tree(graph);
    //    minimum_spanning_tree.printGraph();
        long int mst_cost = minimum_spanning_tree.calculateMST();
        std::cout<<"\n minimum spanning tree cost : " << mst_cost << std::endl;
        ASSERT_EQ(mst_cost, 9);

    }

}
TEST(ScheduleJobs,test3)
{

    std::ifstream file_stream{"/home/manish/git/Documents/fifth_sem/coursera/algorithms-2/week-1/edges.txt"};
    if (file_stream.is_open())
    {

        unsigned int number_vertex{0};
        unsigned int number_edges{0};

        int  start_vertex{0}, end_vertex{0}, weight{0};


        file_stream >> number_vertex >> number_edges;

        std::vector<std::vector<std::pair<int, long >>> graph(number_vertex);

        for (int i = 0; i < number_edges; ++i)
        {
            file_stream >> start_vertex>> end_vertex >> weight;
            // to maintain zero indexing througout the code
            // one is subtracted from the start and end vertex
            --start_vertex;
            --end_vertex;
            graph[start_vertex ].push_back({end_vertex, weight});
            graph[end_vertex ].push_back({start_vertex, weight});
        }

        MinimumSpanningTree<long, PrimsMinimumSpanningTree<long>> minimum_spanning_tree(graph);
       // minimum_spanning_tree.printGraph();
        long int mst_cost = minimum_spanning_tree.calculateMST();
        std::cout<<"\n minimum spanning tree cost : " << mst_cost << std::endl;

    }


}
