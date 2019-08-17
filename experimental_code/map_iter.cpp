#include <iostream>
#include <map>
#include <string>

int main()
{
  std::map<std::string, int> a;
  a["hello"] =  0;

  auto it = a.find("hello");
  it->second = 2;
  std::cout << a["hello"] << std::endl;
  return 0;
}

