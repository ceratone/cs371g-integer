// -----------------------------------
// projects/c++/integer/RunInteger.c++
// Copyright (C) 2016
// Glenn P. Downing
// -----------------------------------

// --------
// includes
// --------

#include <iostream> // cout, endl
#include <deque>    // deque

#include "Integer.h"

// ----
// main
// ----

int main () {
    using namespace std;
    cout << "RunInteger.c++" << endl << endl;
    
    //Tests for Integer class methods
    cout << " Test Integer for Integer class methods" << endl;
    {
    }
    // less than 500 ms
    cout << "*** 20th Mersenne prime: 1,332 digits ***" << endl << endl;
    {
    const Integer<int> q = Integer<int>("12");
    //++q;
    Integer<int> p = Integer<int>("4");
    p+=q;
    //q++;
    //const Integer<int> n = Integer<int>("2678786");//.pow(4423) - 1;
    //cout << "2^4423 - 1 = " << n << endl << endl;
    }

    {
    const Integer<int, std::deque<int> > n = Integer<int, std::deque<int> >(2).pow(4423) - 1;
    cout << "2^4423 - 1 = " << n << endl << endl;
    }

    // --------------------------
    // extra credit (5 bonus pts)
    // --------------------------

    // less than 4 min
    cout << "*** 30th Mersenne prime: 39,751 digits ***" << endl << endl;

    {
    const Integer<int> n = Integer<int>(2).pow(132049) - 1;
    cout << "2^132049 - 1 = " << n << endl << endl;
    }

    cout << "Done." << endl;

    return 0;}
