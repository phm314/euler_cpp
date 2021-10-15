#ifndef LARGE_H_INCLUDED
#define LARGE_H_INCLUDED

#include <vector>
#include <iostream>

class Large {
    std::vector<int> elem;
public:
    Large(int i);                   // default  constructor
    Large(std::vector<int> vect);
    Large();                        // ordinary constructor
    /*
    Large(const Large&);            // copy     constructor person b(a)
    Large(Large&&);                 // move     constructor
    */
    Large& operator=(const Large& that); // copy     assignment b = a
    /*
    Large& operator=(Large&&);      // move     assignment
    */

    Large operator+(Large b);
    Large operator+(int i);
    Large operator*(Large b);

    const bool operator==(Large b);
    const bool operator<(Large b);
    const bool operator>(Large b);

    int operator[](int i);
    int count();

    friend std::ostream& operator<<(std::ostream&, const Large& large);
};

#endif // LARGE_H_INCLUDED
