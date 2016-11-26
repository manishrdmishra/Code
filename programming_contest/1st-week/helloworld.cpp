#include <iostream>

int main ()
{
int t;
std::string name;
std::cin>>t;

for(int i = 1; i<=t; i++)
{
    std::cin>>name;
    std::cout<<"Case #"<<i<<": "<<"Hello "<<name<<"!"<<std::endl;

}
    return 0;
}
