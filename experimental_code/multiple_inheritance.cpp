#include <iostream>
#include <memory>

class base1 { };
class base2 { };
struct derived1 : public base1, public base2
{
  derived1() { std::cout << "derived 1 const \n"; }
};

struct derived2 : public base1
{
  derived2() { std::cout << "derived 2 const\n"; }
};

struct A{}; 
struct B: public A {};
struct C: public B{};

struct L: public A{};

struct S: public C, public L
{};

class hello {
  public:
    hello() = default;
    void  print(){ std::cout << "hello\n";}
};

class DerivedHello : public hello
{
  public:
    DerivedHello() = default;
    void print() { std::cout << "DeriveHello\n";}
};

int main()
{

  //base1* b1 = static_cast<base1*> (new derived1());
  //base1* b2 = static_cast<base1*> (new derived2());
//  S* super = new S();
//  L* interface = static_cast<L*>(super);
  auto dh = std::make_unique<DerivedHello>();
  dh->print();
  return 0;

}
