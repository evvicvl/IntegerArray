#include "integerarray.h"
#include "arrayexceptions.h"

namespace myContainer
{
    void IntegerArray::_resize(int length, int begin, int end)
    {
        int bufLength = _length;
        int* buf = new int[bufLength]{};
        for (int i = 0; i < bufLength; ++i) {
            buf[i] = _data[i];
        }
        if (_data != nullptr)
            delete[] _data;
        _length = length + begin + end;
        _data = new int[length + begin + end]{};
        for (int i = 0; i < (length > bufLength ? bufLength : length); ++i) {
            if (i + begin >= 0) {
                _data[i + begin] = buf[i];
            }
        }
        delete[] buf;
    }

    IntegerArray::IntegerArray() : _length(0)
    {

    }

    IntegerArray::~IntegerArray()
    {
        if (_data != nullptr)
            delete[] _data;
    }

    void IntegerArray::copyTo(IntegerArray &other)
    {
        if (_length == 0) {
            throw myException::emptyArray();
        }
        if (_length != other._length) {
            throw myException::badLength();
        }
        other._length = _length;
        delete[] other._data;
        other._data = new int[_length]{};
        for (int i = 0; i < _length; ++i) {
            other._data[i] = _data[i];
        }
    }

    void IntegerArray::forceCopyTo(IntegerArray &other)
    {
        if (_length == 0) {
            throw myException::emptyArray();
        }
        other._length = _length;
        delete[] other._data;
        other._data = new int[_length]{};
        for (int i = 0; i < _length; ++i) {
            other._data[i] = _data[i];
        }
    }

    IntegerArray::IntegerArray(int length)
    {
        if (length <= 0) {
            throw myException::badLength();
        }
        _length = length;
        _data = new int[length]{};
    }

    int &IntegerArray::at(int index)
    {
        if (index < 0 || index >= _length) {
            throw myException::badIndex();
        }
        return _data[index];
    }

    int IntegerArray::getLength() const
    {
        return _length;
    }

    int IntegerArray::find(int val)
    {
        if (_length <= 0) {
            throw myException::badLength();
        }
        for (int i = 0; i < _length; ++i) {
            if (_data[i] == val) {
                return i;
            }
        }
        return -1;
    }

    void IntegerArray::resize(int length)
    {
        if (length <= 0 || length == _length) {
            throw myException::badLength();
        }
        if (_length <= 0) {
            throw myException::emptyArray();
        }
        _resize(length, 0, 0);
    }

    void IntegerArray::pushFront(int value)
    {
        _resize(_length, 1, 0);
        _data[0] = value;
    }

    void IntegerArray::pushBack(int value)
    {
        _resize(_length, 0, 1);
        _data[_length - 1] = value;
    }

    void IntegerArray::popFront()
    {
        if (_length < 2) {
            throw myException::badLength();
        }
        _resize(_length, -1, 0);
    }

    void IntegerArray::popBack()
    {
        if (_length < 2) {
            throw myException::badLength();
        }
        _resize(_length - 1, 0, 0);
    }

    void IntegerArray::erase()
    {
        _length = 0;
        if (_data != nullptr) {
            delete[] _data;
            _data = nullptr;
        }
    }
}
