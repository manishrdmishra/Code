#include <iostream>

class A 
{
  public:
  virtual void print() { std::cout <<  "A\n"; }
};

class B : public A 
{
  public:
  virtual void print() override { std::cout <<  "B\n"; }
};

class C : public B 
{
  public:
  virtual void print() override { std::cout <<  "C\n"; }
};


int main()
{
  C c;
  c.print();
  return 0;
}
