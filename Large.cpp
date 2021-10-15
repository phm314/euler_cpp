#include <iostream>
#include <algorithm>
#include <vector>

#include "Large.h"

Large::Large(int i) :elem{}{
    int digit;
    while (i>=10) {
        digit = i % 10;
        i /= 10;
        elem.push_back(digit);
    }
    elem.push_back(i);

}

Large::Large(std::vector<int> vect) :elem{vect} {
    // TODO value check
}

Large::Large() :elem{}{
}

Large& Large::operator=(const Large& that) {
    elem = that.elem;
    return *this;
}

int Large::operator[] (int i) {
    if (i >= elem.size())
        return 0;
    return elem[i];
}

Large Large::operator+ (Large b) {
    Large result;

    int msz = std::max(elem.size(), b.elem.size());
    int carry = 0;
    int nxt = 0;

    for (int i=0; i < msz; ++i) {
        nxt = 0;
        if (i < elem.size())
            nxt += elem[i];
        if (i < b.elem.size())
            nxt += b[i];
        nxt += carry;
        carry = 0;
        if (nxt >= 10) {
            carry = nxt / 10;
            nxt %= 10;
        }
        result.elem.push_back(nxt);
    }
    if (carry)
        result.elem.push_back(carry);

    return result;
}

Large Large::operator+ (int i) {
    Large b(i);
    Large result = this->operator+(b);
    return result;
}

int Large::count () {
    return elem.size();
}

Large Large::operator* (Large b) {
    std::vector<Large> sums;
    Large small;
    Large big;
    if (elem.size() >= b.elem.size()) {
        small = *this;
        big = b;
    } else {
        small = b;
        big = *this;
    }

    int carry;
    int nxt;

    int indent = 0;
    for (auto i: small.elem) {
        Large result {};
        for (int i=0; i<indent; ++i) {
            result.elem.push_back(0);
        }
        int carry = 0;
        int nxt = 0;
        ++indent;
        for (auto x: big.elem) {
            nxt = i * x + carry;
            carry = 0;

            if (nxt >= 10) {
                carry = nxt / 10;
                nxt %= 10;
            }
            result.elem.push_back(nxt);
        }
        if (carry) 
            result.elem.push_back(carry);
        sums.push_back(result);
    }

    Large result;

    for (auto i: sums) {
        result = result + i;
    }

    return result;
}

const bool Large::operator== (Large b) {
    for (int i=0; i<elem.size(); ++i) {
        if (elem[i] != b[i])
            return false;
    }
    return true;
}

const bool Large::operator<(Large b) {
    if (count() < b.count())
        return true;
    else if (count() > b.count()) 
        return false;
    else {
        for (int i = elem.size(); i >= 0; --i) {
            if (elem[i] > b[i])
                return false;
        }
    }
    return true;
}

const bool Large::operator>(Large b) {
    return (!(*this > b && *this == b));
}
std::ostream& operator<< (std::ostream& out, const Large& large) {
    for (auto it = large.elem.rbegin(); it != large.elem.rend(); ++it)
        std::cout << *it << "";
    return out;
}
