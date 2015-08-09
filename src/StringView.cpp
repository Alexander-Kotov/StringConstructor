#include "StringView.h"
#include <string.h>

StringView::StringView() :
    view("", 0)
{
}

StringView::StringView(const char *s) :
    view(s, strlen(s))
{
}

StringView::StringView(const char *s, size_t size) :
    view(s, size)
{
}

StringView::StringView(const std::string &s) :
    view(s.data(), s.size())
{
}

const char *StringView::data() const
{
    return view.first;
}

size_t StringView::size() const
{
    return view.second;
}

const char *StringView::begin() const
{
    return data();
}

const char *StringView::end() const
{
    return begin() + size();
}

StringView StringView::substr(size_t pos, size_t size) const
{
    const char *p = begin() + pos;
    if (p >= end()) {
        return StringView();
    }
    const char *q = p + size;
    if (q < end()) {
        return StringView(p, size);
    }
    return StringView(p, end() - p);
}

bool operator==(const StringView &lhs, const StringView &rhs)
{
    if (lhs.begin() == rhs.begin() && lhs.size() == rhs.size()) {
        return true;
    }
    if (lhs.size() != rhs.size()) {
        return false;
    }
    return !memcmp(lhs.data(), rhs.data(), lhs.size());
}

bool operator!=(const StringView &lhs, const StringView &rhs)
{
    return !(lhs == rhs);
}
