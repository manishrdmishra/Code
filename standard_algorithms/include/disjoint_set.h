#ifndef ALGORITHMS_DISJOINT_SET_H
#define ALGORITHMS_DISJOINT_SET_H


template <typename T>
class disjoint_set
{
public:
    virtual T find_leader()const = 0;
    virtual void set_union(std::shared_ptr<disjoint_set> second_set) = 0;
    virtual ~disjoint_set()= 0;
};


template <typename T>
class disjoint_set_list : public disjoint_set<T>
{
public:
    disjoint_set_list();
    disjoint_set_list(T element);
    T find_leader () const;
    void set_union(std::shared_ptr<disjoint_set> second_set);

private:
    // leader of the set
    T leader_;
    // elements of the set
    std::list<T> elements_;
};


template <typename  T>
disjoint_set_list<T>::disjoint_set_list()
: leader_{}
{
}

template <typename T>
disjoint_set_list::disjoint_set_list(T element)
: leader_{element}, elements_{element}
{

}
template < typename T>
T disjoing_set_list<T>::find_leader()const
{
   return leader_ ;
}

template <typename T>
void disjoint_set_list::union_set(std::shared_ptr<disjoint_set> second_set)
{
 if( elements_.size() > second_set.elements_.size())
 {
     std::copy(second_set.begin(), second_set.end(), std::back_inserter(elements_));
 }
    else
 {
     std::copy(elements_.begin(), elements_.end(), std::back_inserter())
 }
    second_set = this;
}




#endif //ALGORITHMS_DISJOINT_SET_H
