#include "String.h"
#include "string_iterator.h"

#include <utility>

//! constructor with char pointer
library::String::String(const char* x)
{
    if (x != nullptr)
    {
        length_ = strlen(x);
        capacity_ = length_;
        string_ = clone_string(x);
    }
}

//! copy constructor
library::String::String(const String& x)
{
    length_ = x.length_;
    capacity_ = length_;
    string_ = clone_string(x.c_str());
}

//! assignment operator 
library::String& library::String::operator=(const String& x)
{
    String temp;
    temp.length_ = x.length_;
    temp.capacity_ = x.capacity_;
    temp.string_ = clone_string(x.c_str());
    std::swap(temp, *this);
}

//! move constructor 
library::String::String(String&& x)
{
    length_ = x.length_;
    capacity_ = length_;
    string_ = x.string_;
    x.length_ = 0;
    x.string_ = nullptr;
}

//! move assignment
library::String &library::String::operator=(String &&x)
{
    length_ = x.length_;
    capacity_ = length_;
    string_ = x.string_;
    x.length_ = 0;
    x.string_ = nullptr;
}

library::String::~String()
{
    delete[] string_;
}

bool library::String::is_index_valid(int n) const
{
    if (n > length_)
        return false;
    
    return true;
}
char library::String::at(int n) const
{
    if (!is_index_valid(n))
        throw std::runtime_error("out of bound");
    return string_[n - 1];
}

char& library::String::at(int n)
{
    return this->at(n);
}

library::String& library::String::operator+=(char c)
{
    char temp[] = {c, '\0'};
    *this += temp;
}

library::String& library::String::operator+=(const String& x)
{
    *this += x.string_;
}

library::String& library::String::operator+=(const char* x)
{
    auto length = strlen(x);
    if (length_ + length >= capacity_)
    {
        increase_capacity_to(2 * capacity_);
    }
    strcat(string_, x);
    length_ += length;
}

void library::String::increase_capacity_to(int n)
{
    auto new_str = new char[n];
    strcpy(new_str, string_);
    std::swap(new_str, string_);
    capacity_ = n;
    delete new_str;
}

bool library::String::operator==(const String& other) const 
{
    return (strcmp(string_, other.string_) == 0);
}

bool library::String::operator!=(const String& other) const 
{
    return !(*this == other);
}

library::String::Iterator library::String::begin()
{
    Iterator it(*this, string_);
    return it;
}

library::String::Iterator library::String::end()
{
    Iterator it(*this, nullptr);
    return it;
}

//! free functions
char* library::clone_string(const char* source_str)
{
    auto length = strlen(source_str);
    auto string = new char[length + 1];

    if(string == nullptr)
        throw std::runtime_error("failed to allocate memory");

    strcpy(string, source_str);
    string[length + 1] = '\0';
    return string;
}
std::ostream &library::operator<<(std::ostream &os, const String &x)
{
    return os<<x.c_str();
}
