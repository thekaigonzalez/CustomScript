#include <cstdio>
#include <string>


#define CustomSsize_t unsigned long

#define CustomSInt int

#define CustomSLong long

#define CustomSLongLong long long

enum Custom {
    CUSTOM_IN,
    CUSTOM_OUT
};

struct object {
    const char* name{};
    virtual void flush(const std::string& tp) {
        printf("%s\n", tp.c_str());
    }
};

#if !defined(parse)

#define arrayof(type, array, values, size) type array[size]


#endif


class Parser {
public:

};