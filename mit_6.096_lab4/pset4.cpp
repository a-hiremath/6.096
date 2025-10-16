//
// Created by Adi Hiremath on 10/14/25.
//

#include <iostream>
#include "pset4.h"
#include <vector>


class Triangle;
using namespace std;


/*
 *
 * Section 2
 *
 */

// 2.1

template <typename t>
t minNum(t num1, t num2) {
    if (num1 < num2) {
        return num1;
    } else {
        return num2;
    }
}

// 2.2

#define minNumMacro(a, b) (a > b) ? cout << endl << a : cout << endl << b;


/*
 *
 * Section 3
 *
 */

// 3.1

    // static_cast<Triangle *>(p);

// 3.2

    // dynamic_cast<Triangle *>(p);

/*
 *
 * Section 4
 *
 */

template <typename t>
class Stack {
    vector<t> arr;
public:

    bool empty() const {
        return arr.empty();
    }

    void push(const t& val) {
        arr.push_back(val);
    }

    t top() const {
        return arr.back();
    }

    void pop() {
        arr.pop_back();
    }

};


int main() {

    cout << minNumMacro(4, 5);

    return 0;
}