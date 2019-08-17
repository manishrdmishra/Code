#include <algorithm>
#include <vector>
#include <iostream>

int main()
{
  std::vector<int> numbers{1, 2, 3, 4};
  std::vector<int> multiples;

  std::transform(numbers.begin(), numbers.end(), std::back_inserter(multiples), [](int num){ return 2*num; });

  std::copy(multiples.begin(), multiples.end(), std::ostream_iterator<int>(std::cout , "  "));
  return 0;
}
