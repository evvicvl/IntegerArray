#ifndef INTEGERARRAY_H
#define INTEGERARRAY_H

namespace myContainer
{
    class IntegerArray
    {
    private:
        int _length;
        int* _data;

        void _resize(int length, int begin, int end);
    public:
        IntegerArray();
        ~IntegerArray();
        void copyTo(IntegerArray &other);
        void forceCopyTo(IntegerArray &other);
        IntegerArray(int length);
        int& at(int index);
        int getLength() const;
        int find(int val);
        void resize(int length);
        void pushFront(int value);
        void pushBack(int value);
        void popFront();
        void popBack();
        void erase();
    };
}

#endif // INTEGERARRAY_H
