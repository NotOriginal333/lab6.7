#pragma once 
#include "IsPositive.h"
#include <iostream> 
#include <algorithm> 
#include <cmath>
using namespace std;

class Array
{
public:
    typedef unsigned int  UINT;
    typedef double        value_type;
    typedef double* iterator;
    typedef const double* const_iterator;
    typedef double& reference;
    typedef const double& const_reference;
    typedef std::size_t   size_type;

private:
    static const size_type minsize = 10;
    size_type Size;
    size_type Count;
    size_type First;
    value_type* elems;
public:
    Array(const size_type& n = minsize)
        throw(bad_alloc, invalid_argument);
    Array(const Array&) throw(bad_alloc);
    Array(const iterator first, const iterator last)
        throw(bad_alloc, invalid_argument);
    Array(const size_type first, const size_type last)
        throw(bad_alloc, invalid_argument);
    ~Array();
    Array& operator=(const Array&);


    iterator begin() { return elems; }
    const_iterator begin() const { return elems; }
    iterator end() { return elems + Count; }
    const_iterator end() const { return elems + Count; }


    size_type size() const;
    bool      empty() const;
    size_type capacity() const;
    void      resize(size_type newsize)
        throw(bad_alloc);

    reference operator[](size_type) throw(out_of_range);
    const_reference operator[](size_type) const throw(out_of_range);
    reference front() { return elems[0]; }
    const_reference front() const { return elems[0]; }
    reference back() { return elems[size() - 1]; }
    const_reference back() const { return elems[size() - 1]; }

    void sumAverage();
    void replace();
    void push_back(const value_type& v);
    void pop_back();
    void clear() { Count = 0; }
    void swap(Array& other);
    void assign(const value_type& v);

    friend ostream& operator <<(ostream& out, const Array& a);
    friend istream& operator >>(istream& in, Array& a);

    void unique_copy();
    template<class T>
    void unique_copy_if(T pred) {
        if (Count <= 1)
            return;
        size_type newIndex = 0;
        for (size_type i = 0; i < Count; ++i) {
            bool isUnique = true;
            if (pred(elems[i])) {
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
        }
        Count = newIndex;
    };
};
