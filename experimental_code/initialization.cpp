#include <iostream>


struct A 
{
  int a;
  int b;
};

int main()
{
  A a = {1,2};

  std::cout << a.a << std::endl;
  std::cout << a.b << std::endl;

  return 0;
}

