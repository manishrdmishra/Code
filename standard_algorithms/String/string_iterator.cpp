#include "string_iterator.h"

library::StringIterator::StringIterator(const String& x , char* current_ptr)
: string_{x}
, pointer_{current_ptr}
{}

library::StringIterator library::StringIterator::operator++()
{
    if (*pointer_ == '\0')
    {
        pointer_ = nullptr;
        return StringIterator(string_, nullptr);
    }
    return StringIterator(string_, ++pointer_);
}

library::StringIterator library::StringIterator::operator++(int)
{
    auto prev = pointer_;

    if (*pointer_ == '\0')
    {
        pointer_ = nullptr;
        return {string_, nullptr};
    }
    ++pointer_;

    return {string_, prev};
}

bool library::StringIterator::operator==(const StringIterator &other) const
{
    return (string_ == other.string_) && (pointer_ == other.pointer_);
}
bool library::StringIterator::operator!=(const StringIterator &other) const
{
    return !(*this == other);
}
