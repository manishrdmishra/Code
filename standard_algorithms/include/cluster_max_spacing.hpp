#ifndef ALGORITHMS_KRUSHKAL_HPP
#define ALGORITHMS_KRUSHKAL_HPP

#include <algorithm>
#include <boost/pending/disjoint_sets.hpp>
#include <boost/property_map/property_map.hpp>

/* This functor computes the max spacing
* when the number of clusters are K.
* This functor expects set of vertex
* and set of edge. It also assumes that
* the set of edge are sorted by the cost.
* Vertices are assumed to be integers.
* Edge {pair<node1, node2>, cost}
*
*/

template<typename Container>
void copy_to_console(Container const& c)
{
    std::copy(c.begin(), c.end(), std::ostream_iterator<int>(std::cout," "));
}

std::vector<int> flip_bit_at(std::vector<int> seq, int index)
{
    if(seq[index] == 0)
    {
        seq[index] = 1;
    }
    else
    {
        seq[index] = 0;
    }

    auto new_seq(seq);
    return new_seq;
}
int hamming_distance(const std::vector<int>& first, const std::vector<int>& second)
{
    int count = 0;
    // copy_to_console(first);
    // std::cout << " :  ";
    // copy_to_console(second);
    // std::cout << std::endl;

    for(int i = 0; i< first.size(); ++i)
    {
        if(first[i] != second[i])
        {
            ++count;
        }
    }

    return count;
}

std::vector<std::vector<int>> hamming_distance_one(const std::vector<int>& seq, int start)
{
    std::vector<std::vector<int>> generated_seq;
    generated_seq.reserve(seq.size());

    for(int i = start; i<seq.size(); ++i)
    {
        auto new_seq = flip_bit_at(seq, i);
        generated_seq.push_back(new_seq);
    }

    return generated_seq;
}

std::vector<std::vector<int>> hamming_distance_two(const std::vector<int>& seq)
{
    auto n = ((seq.size() * (seq.size() - 1 )) / 2);
    std::vector<std::vector<int>> generated_seq;
    generated_seq.reserve(n);

    for(int i = 0; i< seq.size() -1; ++i)
    {
        auto seq_with_dist_one = flip_bit_at(seq, i);
        auto seqs = hamming_distance_one(seq_with_dist_one, i+1);
        std::copy(seqs.begin(), seqs.end(), std::back_inserter(generated_seq));
    }

    return generated_seq;
}

class KClusterMaxSpacing
{
public:
    size_t  operator()(const auto& vertices,const auto& edges,size_t k)
    {
        LOG(INFO) << "executing clustering ";
        typedef std::map<int ,std::size_t> rank_t; // => order on Element
        typedef std::map<int ,int> parent_t;
        rank_t rank_map;
        parent_t parent_map;

        boost::associative_property_map<rank_t>   rank_pmap(rank_map);
        boost::associative_property_map<parent_t> parent_pmap(parent_map);

        boost::disjoint_sets<boost::associative_property_map<rank_t>,
        boost::associative_property_map<parent_t> >  dsets(rank_pmap, parent_pmap);

        std::for_each(vertices.begin(),vertices.end(),
        [&](const auto& vertex)
        {
            //std::cout << "vertex : " << vertex << std::endl;
            dsets.make_set(vertex);
        });

        size_t num_of_clusters = vertices.size();
        std::cout << " number of clusters : " << num_of_clusters<< std::endl;
        for(const auto& edge: edges)
        {
            LOG(INFO)<<"processing edge : "<< edge.first.first;
            // std::cout <<"processing edge : "<< edge.first.first << " " << edge.first.second; //<< std::endl;
            // std::cout << " cost : " << edge.second << std::endl;
            size_t u = dsets.find_set(edge.first.first);
            size_t v = dsets.find_set(edge.first.second);
            //std::cout << "u , v : " << u <<"  " << v << std::endl;
            if(num_of_clusters == k - 1)
            {
                std::cout << " number of clusters : " << num_of_clusters << std::endl;
                std::cout << " cost returned : " << edge.second << std::endl;
                return edge.second;
            }
            if(u != v)
            {
                --num_of_clusters;
                dsets.link(u, v);
                std::cout << " merge " << u << " " << v <<  " " << edge.second << std::endl;
            }

        }

    }

    size_t num_of_clusters(const std::vector<int>& vertex_index, const std::vector<std::vector<int>>& vertex, int cluster_max_spacing)
    {
        auto num_of_clusters = vertex_index.size();

        typedef std::map<int ,std::size_t> rank_t; // => order on Element
        typedef std::map<int ,int> parent_t;
        rank_t rank_map;
        parent_t parent_map;

        boost::associative_property_map<rank_t>   rank_pmap(rank_map);
        boost::associative_property_map<parent_t> parent_pmap(parent_map);

        boost::disjoint_sets<boost::associative_property_map<rank_t>,
        boost::associative_property_map<parent_t> >  dsets(rank_pmap, parent_pmap);

        std::for_each(vertex_index.begin(),vertex_index.end(),
        [&](const auto& vertex)
        {
            //std::cout << "vertex : " << vertex << std::endl;
            dsets.make_set(vertex);
        });


        for(int i = 0; i< vertex_index.size(); ++i)
        {
            for(int j = i+1; j< vertex_index.size(); ++j)
            {
                int d = hamming_distance(vertex[i], vertex[j]);
                //std::cout << " size " << vertex[i].size() << "  ";
                //std::cout << vertex_index[i] << " " << vertex_index[j] <<  " distance : " << d << std::endl;
                if(d < 3)
                {
                    size_t u = dsets.find_set(i);
                    size_t v = dsets.find_set(j);
                    if(u != v)
                    {
                        --num_of_clusters;
                        dsets.link(u, v);
                        //std::cout << " merge " << u << " " << v << std::endl;
                        //std::cout << num_of_clusters << std::endl;
                    }
                }
            }
        }

        return num_of_clusters;

    }
};

#endif //ALGORITHMS_KRUSHKAL_HPP
