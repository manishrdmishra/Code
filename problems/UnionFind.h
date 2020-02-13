#include <algorithm>
#include <numeric>
#include <vector>

class UnionFind
{
    public:

    UnionFind(int size)
    : m_size(size)
    , m_components(m_size)
    , m_set(m_size)
    {
        std::iota(m_set.begin(), m_set.end(), 0);
    }

    int find_set(int index)
    {
        while(index != m_set[index])
        {
            index = m_set[index];
        }

        return index;
    }

    void union_set(int index1, int index2)
    {
        int parent1 = find_set(index1);
        int parent2 = find_set(index2);
        if(parent1 ==  parent2)
            return ;

        m_set[parent2] = parent1;
        --m_components;
    }

    int num_components() const
    {
        return m_components;
    }

    private:

    int m_size;
    int m_components;
    std::vector<int> m_set;
};