#include <iostream>

class A{
  public:
    int getA() const{
      return a_;
    }
    void setA(int a)
    {
      a_ = a;
      std::cout << "a is executed\n";
    }
  private:
    int a_;
};

void func(const A* a_ptr)
{
  a_ptr->setA(5);
}

int main()
{
  A* a = new A();
  func(a);
  return 0;
}
