#pragma once

#include <iostream>
#include <cstring>
#include <algorithm>
#include <memory>

namespace library
{

class StringIterator;   
class String
{
  public:
    using Iterator = library::StringIterator;
    //! constructors
    String(const char *x = nullptr);
    String(const String &x);
    String &operator=(const String &x);
    String(String &&x);
    String &operator=(String &&x);
    ~String();

    //! accesser functions
    char &operator[](int n) { return string_[n]; }
    char operator[](int n) const { return string_[n]; }
    char &at(int n);
    char at(int n) const;
    Iterator begin();
    Iterator end();

    //! modifier functions
    String& operator+=(char c);
    String& operator+=(const String& x); 
    String& operator+=(const char* x);

//! comparison functions
    bool operator==(const String&) const;
    bool operator!=(const String&) const;

    //! search functions
    Iterator find(char* x) const;
    Iterator find(const String& x) const;
    //! convert to c string
    char *c_str() { return string_; }
    const char *c_str() const { return string_; }

    size_t length() const {return length_;}

  private:
    void increase_capacity_to(int n);
    bool is_index_valid(int n) const;
    int length_{0};
    int capacity_{0};
    char *string_{nullptr};
};

char* clone_string(const char *source_str);
std::ostream &operator<<(std::ostream &os, const String &str);
}
