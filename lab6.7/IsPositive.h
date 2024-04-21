#pragma once
template<class T>
class IsPositive {
public:
    bool operator()(T x) const {
        return x > 0;
    }
};