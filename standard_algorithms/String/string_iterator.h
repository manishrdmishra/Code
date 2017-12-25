#include "String.h"
namespace library
{
class StringIterator
{
  public:
    StringIterator(const String &x, char *current_ptr);
    char operator*() const { return *pointer_; }
    StringIterator operator++();
    StringIterator operator++(int);
    bool operator==(const StringIterator& other) const;
    bool operator!=(const StringIterator& other) const;

  private:
    String string_;
    char *pointer_;
};
}