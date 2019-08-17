#include <map>

template<typename index_type,typname distance_type>
class Dijkstra {
    Dijkstra(std::map<std::map<index_type, distance_type>> graph);
    distance_type shortest_distance(index_type start, index_type end);
    void add_node(index_type index, std::map<index_type, distance_type>);
    void remove_node(index_type index);
private:
  std::map<std::map<index_type, distance_type>> graph_;
  std::map<std::map<index_type, distance_type>> shortest_distances_;
}
