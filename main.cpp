#include <iostream>

#include "integerarray.h"

using namespace std;
using namespace myContainer;

void printException(const char* str);

int main()
{
    try
    {
        IntegerArray array(0);
    }
    catch(exception &e)
    {
        printException(e.what());
    }

    IntegerArray array(1);
    array.at(0) = 42;
    try
    {
        cout << array.at(1) << endl;
    }
    catch(exception &e)
    {
        printException(e.what());
    }

    IntegerArray zeroArray;
    IntegerArray otherArray;
    try
    {
        zeroArray.copyTo(otherArray);
    }
    catch(exception &e)
    {
        printException(e.what());
    }

    try
    {
        array.resize(0);
    }
    catch(exception &e)
    {
        printException(e.what());
    }

    IntegerArray test(5);
    for (int i = 0; i < 5; ++i) {
        test.at(i) = i;
        cout << test.at(i) << endl;
    }
    cout << endl;
    test.resize(2);
    cout << "array length: " << test.getLength() << endl;
    test.pushBack(42);
    test.pushFront(43);
    test.popBack();
    test.popFront();
    test.popBack();
    try
    {
        test.popFront();
    }
    catch(exception &e)
    {
        printException(e.what());
    }
    return 0;
}

void printException(const char* str)
{
    cout << "Exception: " << str << endl;
}
