#include <iostream>

namespace experiment {

template<typename T>
class complex {
public:
// constructor's
explicit complex();
explicit complex(T a, T b);
complex(const complex& other); //copy
complex(complex&& other); // move

~complex() = default;
// assignment operators
complex& operator=(const complex& other); //copy 
complex& operator=(complex&& other); // move

// arithmatic operators
complex& operator+=(const complex& other);
complex& operator-=(const complex& other);

//equality operators
bool operator==(const complex& other) const;
bool operator!=(const complex& other) const;

friend std::ostream& operator<<(std::ostream& stream, const complex& c)
{
    stream << c.m_real << ", " << c.m_imag;
    return stream;
}

// accessor functions
T real() const;
T imag() const;

private:
T m_real;
T m_imag;
};

template <typename T>
complex<T>::complex()
: m_real{}, m_imag{}
{
    std::cout << "default ctor" << std::endl;
}

template<typename T>
complex<T>::complex(T a, T b)
: m_real{a}, m_imag{b}
{
    std::cout << "argument ctor" << std::endl;
}

template <typename T>
complex<T>::complex(const complex& other)
: m_real{other.m_real}, m_imag{other.m_imag}
{
    std::cout << "copy ctor" << std::endl;
}

template <typename T>
complex<T>::complex(complex&& other)
:m_real{0}, m_imag{0}
{
m_real = other.m_real;
m_imag = other.m_imag;
// default values for moved object
other.m_real = T{};
other.m_imag = T{};
std::cout << "move ctor" << std::endl;
}

template <typename T>
experiment::complex<T>& 
complex<T>::operator=(const complex& other)
{
m_real = other.m_real;
m_imag = other.m_imag;
std::cout << "copy assignment " << std::endl;
return *this;
}

template <typename T>
experiment::complex<T>&
complex<T>::operator=(complex&& other)
{
    if(this != &other)
    {
        m_real = other.m_real;
        m_imag = other.m_imag;

        other.m_real = T{};
        other.m_imag = T{};

        std::cout << "move assignment" << std::endl;
        
        
    }
    return *this;
}

template<typename T>
experiment::complex<T>&
complex<T>::operator+=(const complex& other)
{
 m_real += other.m_real;
 m_imag += other.m_imag;
 
 return *this;
}

template <typename T>
experiment::complex<T>&
complex<T>::operator-=(const complex& other)
{
    m_real -= other.m_real;
    m_imag -= other.m_imag;

    return *this;
}

template <typename T>
bool complex<T>::operator==(const complex& other) const
{
    return m_real == other.m_real && m_imag == other.m_imag;
}

template <typename T>
bool complex<T>::operator!=(const complex& other) const
{
    return !( *this == other );
}

// template<typename T>
// std::ostream& complex<T>::operator<<(std::ostream& stream, 
// const experiment::complex<T>& c)
// {
//     stream << c.m_real << ", " << c.m_imag;
//     return stream;
// }

template <typename T>
T complex<T>::real() const
{
    return m_real;
}

template <typename T>
T complex<T>::imag() const
{
    return m_imag;
}

}