#include <iostream>
#include <type_traits>

template <typename T, typename... Args>
struct is_one_of;

template <typename T>
struct is_one_of<T> : std::false_type{};

template <typename T, typename... Args>
struct is_one_of<T, T, Args...> : std::true_type{};

template <typename T, typename U, typename... Args>
struct is_one_of<T, U, Args...> : is_one_of<T, Args...>{};


int main()
{
    auto val = is_one_of<bool, int, double, std::vector<int>>::value;
    
    if(val)
    std::cout << "true\n";
    else
        std::cout << "false\n";
    return 0;
}