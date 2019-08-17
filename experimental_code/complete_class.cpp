#include <iostream>

class Count
{
  public:
    Count()
    {
      x = new int;
      *x = 0;
    }

    Count(int num)
    {
      x = new int;
      *x = num;
    }

    Count(const Count& c)
    {
      x = new int;
      *x = *(c.x);
      std::cout << "copy constructor" << std::endl;
    }

    Count& operator=(const Count& c)
    {
      *x = *(c.x);
      std::cout << "assignment operator" << std::endl;
      return *this;
    }

    ~Count()
    {
      delete x;
    }

    int count() const
    { 
      return *x;
    }
    
  private:
    int* x;
};

int main()
{
  Count c;
  std::cout << "c value is : "<< c.count() << std::endl;
  Count d(3);
  std::cout << "d value is : "<< d.count() << std::endl;
  c = d;
  std::cout << "c value is : "<< c.count() << std::endl;
  std::cout << "d value is : "<< d.count() << std::endl;
  return 0;
}

