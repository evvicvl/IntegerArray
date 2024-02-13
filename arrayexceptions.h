#ifndef ARRAYEXCEPTIONS_H
#define ARRAYEXCEPTIONS_H

#include <exception>

using namespace std;

namespace myException
{
    class badLength : public exception
    {
    public:
        const char* what() const noexcept override
        {
            return "bad array length";
        }
    };

    class badIndex : public exception
    {
    public:
        const char* what() const noexcept override
        {
            return "bad array index";
        }
    };

    class emptyArray : public exception
    {
    public:
        const char* what() const noexcept override
        {
            return "empty array";
        }
    };
}

#endif // ARRAYEXCEPTIONS_H
