#ifndef STRINGVIEW_H
#define STRINGVIEW_H

#include <utility>
#include <string>

class StringView {
public:
    static const size_t npos = -1;

    StringView();
    StringView(const char *s);
    StringView(const char *s, size_t size);
    StringView(const std::string &s);

    const char *data() const;
    size_t size() const;

    const char *begin() const;
    const char *end() const;

    StringView substr(size_t pos = 0, size_t count = npos) const;

private:
    std::pair<const char *, size_t> view;
};

bool operator==(const StringView &lhs, const StringView &rhs);
bool operator!=(const StringView &lhs, const StringView &rhs);

#endif
