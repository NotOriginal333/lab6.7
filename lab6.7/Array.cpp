#include "Array.h" 
#include <iostream> 
#include <stdexcept> 
#include <exception> 
using namespace std;

Array::Array(const Array::size_type& n)
throw(bad_alloc, invalid_argument)
{
    First = 0;
    Count = Size = n;
    elems = new value_type[Size];
    for (UINT i = 0; i < Size; i++)
        elems[i] = 0;
}

Array::Array(const iterator first, const iterator last)
throw(bad_alloc, invalid_argument)
{
    First = 0;
    if (first <= last) {
        Count = Size = (last - first) + 1;
        elems = new value_type[Size];
        for (UINT i = 0; i < Size; ++i)
            elems[i] = 0;
    }
    else
        throw invalid_argument("!!!");
}

Array::Array(const size_type first, const size_type last)
throw(bad_alloc, invalid_argument)
{
    if (first <= last) {
        First = first;
        Count = Size = (last - first) + 1;
        elems = new value_type[Size];
        for (UINT i = 0; i < Size; ++i)
            elems[i] = 0;
    }
    else
        throw invalid_argument("!!!");
}

Array::Array(const Array& t) throw(bad_alloc)
    : Size(t.Size), Count(t.Count), First(t.First), elems(new value_type[Size])
{
    for (UINT i = 0; i < Size; ++i)
        elems[i] = t.elems[i];
}

Array& Array::operator =(const Array& t)
{
    Array tmp(t);
    swap(tmp);
    return *this;
}

Array::~Array()
{
    delete[]elems;
    elems = 0;
}

void Array::push_back(const value_type& v)
{
    if (Count == Size)
        resize(Size * 2);
    elems[Count++] = v;
}

Array::reference Array::operator [](size_type index) throw(out_of_range)
{
    if ((First <= index) && (index < First + Size))
        return elems[index - First];
    else
        throw out_of_range("Index out of range!");
}

Array::const_reference Array::operator [](size_type index) const
throw(out_of_range)
{
    if ((First <= index) && (index < First + Size))
        return elems[index - First];
    else
        throw out_of_range("Index out of range!");
}

void Array::resize(size_type newsize) throw(bad_alloc)
{
    if (newsize > capacity())
    {
        value_type* data = new value_type[newsize];
        for (size_type i = 0; i < Count; ++i)
            data[i] = elems[i];

        delete[] elems;
        elems = data;
        Size = newsize;
    }
}

void Array::swap(Array& other)
{
    std::swap(elems, other.elems);
    std::swap(Size, other.Size);
}

Array::size_type Array::capacity() const
{
    return Size;
}

Array::size_type Array::size() const
{
    return Count;
}

bool Array::empty() const
{
    return Count == 0;
}

ostream& operator <<(ostream& out, const Array& tmp)
{
    for (size_t j = 0; j < tmp.Count; j++)
        out << tmp[j] << "  ";
    out << endl;
    return out;
}

istream& operator >>(istream& in, Array& tmp)
{
    for (Array::size_type i = 0; i < tmp.Count; ++i) {
        cout << "Enter element " << i << ": ";
        in >> tmp[i];
    }
    return in;
}

void Array::replace() {
    value_type max_val = 0;
    value_type min_val = 0;
    bool found_max = false;
    bool found_min = false;

    if (elems[Count] > 50 || elems[Count] < -50 || elems[Count - 1] > 50 || elems[Count - 1] < -50) {
        for (Array::size_type i = 0; i < Count - 2; ++i) {
            if (!found_max || fabs(elems[i]) > max_val) {
                max_val = fabs(elems[i]);
                found_max = true;
            }
            if (!found_min || fabs(elems[i]) < min_val) {
                min_val = fabs(elems[i]);
                found_min = true;
            }
        }

        for (Array::size_type i = 0; i < Count - 2; ++i) {
            if (fmod(fabs(elems[i]), 2) == 0) {
                elems[i] = max_val - min_val;
            }
        }
    }
    else {
        for (Array::size_type i = 0; i < Count; ++i) {
            if (!found_max || fabs(elems[i]) > max_val) {
                max_val = fabs(elems[i]);
                found_max = true;
            }
            if (!found_min || fabs(elems[i]) < min_val) {
                min_val = fabs(elems[i]);
                found_min = true;
            }
        }

        for (Array::size_type i = 0; i < Count; ++i) {
            if (fmod(fabs(elems[i]), 2) == 0) {
                elems[i] = max_val - min_val;
            }
        }
    }
}

void Array::sumAverage() {
    double sum = 0;
    for (Array::size_type i = 0; i < Count; ++i) {
        sum += fabs(elems[i]);
    }
    double average = sum / Count;

    push_back(sum);
    push_back(average);
}

void Array::unique_copy() {
    if (Count <= 1) 
        return; 
    size_type newIndex = 0; 

    for (size_type i = 0; i < Count; ++i) {
        bool isUnique = true; 
        for (size_type j = 0; j < i; ++j) {
            if (elems[i] == elems[j]) {
                isUnique = false;
                break;
            }
        }

        if (isUnique) {
            elems[newIndex] = elems[i];
            newIndex++;
        }
    }

    Count = newIndex;
}
