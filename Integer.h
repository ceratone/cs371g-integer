// ------------------------------
// projects/c++/integer/Integer.h
// Copyright (C) 2016
// Glenn P. Downing
// ------------------------------

//#define DEBUG 

#ifndef Integer_h
#define Integer_h

// --------
// includes
// --------
#include <iterator>  // std::istream_iterator
#include <algorithm>
#include <cassert>   // assert
#include <iostream>  // ostream
#include <stdexcept> // invalid_argument
#include <string>    // string
#include <vector>    // vector
#include <sstream>  // istringstream
#include <cstdlib> //needed for atoi


// ---------------
// is_canceled out
// ---------------
template <typename II>
bool is_canceled_out (II b, II e){
    ++e;
    while(b != e){
        if(*b!=0)
            return false;
        ++b;
    }
    return true;
}


// ----------------
// shift_left_digits
// -----------------

/**
 * @param b an iterator to the beginning of an input  sequence (inclusive)
 * @param e an iterator to the end       of an input  sequence (exclusive)
 * @param x an iterator to the beginning of an output sequence (inclusive)
 * @return  an iterator to the end       of an output sequence (exclusive)
 * the sequences are of decimal digits
 * output the shift left of the input sequence into the output sequence
 * ([b, e) << n) => x
 */
template <typename II, typename FI>
 FI shift_left_digits (II b, II e, int n, FI x) {
    assert(n >= 0);
    while(n != 0){

        *x = 0;
        n--;
        x++;
    }
    while(b != e){
        *x = *b;
        x++;
        b++;
    }
    return x;}

// ------------------
// shift_right_digits
// ------------------

/**
 * @param b an iterator to the beginning of an input  sequence (inclusive)
 * @param e an iterator to the end       of an input  sequence (exclusive)
 * @param x an iterator to the beginning of an output sequence (inclusive)
 * @return  an iterator to the end       of an output sequence (exclusive)
 * the sequences are of decimal digits
 * output the shift right of the input sequence into the output sequence
 * ([b, e) >> n) => x
 */
template <typename II, typename FI>
 FI shift_right_digits (II b, II e, int n, FI x) {
    assert(n>=0);
    while (n){
        b++;
        n--;
    }
    while(b != e){
        *x = *b;
        b++;
        x++;
    } 
    return x;}

// -----------
// plus_digits
// -----------

/**
 * @param b  an iterator to the beginning of an input  sequence (inclusive)
 * @param e  an iterator to the end       of an input  sequence (exclusive)
 * @param b2 an iterator to the beginning of an input  sequence (inclusive)
 * @param e2 an iterator to the end       of an input  sequence (exclusive)
 * @param x  an iterator to the beginning of an output sequence (inclusive)
 * @return   an iterator to the end       of an output sequence (exclusive)
 * the sequences are of decimal digits
 * output the sum of the two input sequences into the output sequence
 * ([b1, e1) + [b2, e2)) => x
 */
template <typename II1, typename II2, typename FI>
 FI plus_digits (II1 b1, II1 e1, II2 b2, II2 e2, FI x) {
    bool carry = false;
    while(b2!= e2){
        if(b1 != e1){
            *x = *b1 + *b2;
            if(carry){
                ++*x;
                carry = false;
            }
            if(*x >= 10){
                *x %=10;
                carry = true;                    
            }
            b1++;
            x++;

        }
        else{
            if(carry){
                short temp = *b2+1;
                if(temp>=10){
                    carry = true;
                    temp %= 10;
                }
                else
                    carry = false;
                *x = temp;
                ++x;
            }
            else{
                *x = *b2;
                ++x;
            }
        }
        b2++;
    }
    if(b1 != e1){
        if(carry){
            while(carry){
                if(b1 == e1){
                    *x = 1;
                    ++x;
                    carry = false;
                }
                else if(*x == 10){
                    *x = 0;
                    carry = true;
                    b1++;
                    x++;
                }
                else{
                    carry = false;
                }
                ++*x;
            }
        }
        else{
            while(b1 != e1){
                *x = *b1;
                ++x;
                ++b1;
            }
        }
    }
    return x;}

// ------------
// minus_digits
// ------------

/**
 * @param b  an iterator to the beginning of an input  sequence (inclusive)
 * @param e  an iterator to the end       of an input  sequence (exclusive)
 * @param b2 an iterator to the beginning of an input  sequence (inclusive)
 * @param e2 an iterator to the end       of an input  sequence (exclusive)
 * @param x  an iterator to the beginning of an output sequence (inclusive)
 * @return   an iterator to the end       of an output sequence (exclusive)
 * the sequences are of decimal digits
 * output the difference of the two input sequences into the output sequence
 * ([b1, e1) - [b2, e2)) => x
 */
template <typename II1, typename II2, typename FI>
 FI minus_digits (II1 b1, II1 e1, II2 b2, II2 e2, FI x) {
    if((e1-b1 == 1) && *b1 == 0){
        II2 cb2 = b2;
        while(cb2 != e2){
            *x = *cb2;
            ++x;
            ++cb2;
        }
        *x = '-';
        ++x;
        return x;
    }
    if((e2-b2 == 1) && *b2 == 0){
        II1 cb1 = b1;
        while(cb1 != e1){
            *x = *cb1;
            ++x;
            ++cb1;
        }
        return x;
    }
    FI cx = x;
    bool borrow = false;
    while (b2 != e2){
        if(b1 != e1){
            *cx = *b1 - *b2;
            if(borrow){
                --*cx;
                borrow = false;
            }
            if(*cx < 0){
                *cx += 10;
                if((e2-b2 == 1)&&(e1-b1 == 1)){
                    ++cx;
                    *cx = 'N';
                    ++cx;
                    goto done;
                }
                borrow = true;
            }
            ++b1;
            ++cx;
        }
        else{
            if(borrow){
                *cx = 9 - *b2;
                if(e2-b2 == 1){
                    ++cx;
                    *cx = 'N';
                    ++cx;
                    break;
                }
                else
                    borrow = true;
                ++cx;
            }
            else{
                *cx = 10-*b2;
                ++cx;
            }
        }
        ++b2;
    }

    if(b1 != e1){
        if(borrow){
            while(borrow){
                if (e1-b1 == 1){
                    ++e1;
                    break;
                }
                else if(*b1 == 0){
                    borrow = true;
                    *cx = 9;
                } 
                else{
                    borrow = false;
                    if(*b1 - 1 != 0){
                        *cx = *b1 - 1;
                    }
                }
                ++cx;
                ++b1;
            }
        }
        else{
            while(b1 != e1){
                *cx = *b1;
                ++cx;
                ++b1;
            }
        }
    }
    done:
    return cx;
}

// -----------------
// multiplies_digits
// -----------------

/**
 * @param b  an iterator to the beginning of an input  sequence (inclusive)
 * @param e  an iterator to the end       of an input  sequence (exclusive)
 * @param b2 an iterator to the beginning of an input  sequence (inclusive)
 * @param e2 an iterator to the end       of an input  sequence (exclusive)
 * @param x  an iterator to the beginning of an output sequence (inclusive)
 * @return   an iterator to the end       of an output sequence (exclusive)
 * the sequences are of decimal digits
 * output the product of the two input sequences into the output sequence
 * ([b1, e1) * [b2, e2)) => x
 */
template <typename II1, typename II2, typename FI>
 FI multiplies_digits (II1 b1, II1 e1, II2 b2, II2 e2, FI x) {

    if((e1-b1 == 1 &&*b1 == 0)||(e2-b2 == 1 && *b2 == 0)){
        *x = 0;
        ++x;
        return x;
    }
    short larger = (e1-b1);
    if(e2-b2>larger)
        larger = e2-b2;
    short shift = 0;
    short productLength = larger * 2;
    std::vector<short> newContainer(productLength);
    std::vector<short>::iterator product = newContainer.begin();
    while(b2!=e2){
        II1 b1Copy = b1;
        if(*b2 == 0){
            ++shift;
            ++b2;
        }
        std::vector<short> thisSum(productLength);
        std::vector<short>::iterator thisSum_it_b = thisSum.begin();
        std::vector<short>::iterator thisSum_it_e = thisSum.end();
        short carry = 0;
        while(b1Copy!= e1){
            short temp = ((*b2) * (*b1Copy));
            if(*b1Copy != 0)
                temp+= carry;
            else{
                temp = carry;
            }
            carry = temp/10;
            *thisSum_it_b = temp%10;
            ++thisSum_it_b;
            ++b1Copy;
        }
        if(carry){
            *thisSum_it_b = carry;
            ++thisSum_it_b;
        }
        std::vector<short> shifted(productLength);
        std::vector<short>::iterator thisShift_it_b = shifted.begin();
        std::vector<short>::iterator shiftResult = shift_left_digits(thisSum.begin(), thisSum_it_b, shift, thisShift_it_b);
        product = plus_digits(newContainer.begin(), product, shifted.begin(), shiftResult, newContainer.begin());
        
        ++shift;
        ++b2;
    }
    //Unload
    for(std::vector<short>::iterator it = newContainer.begin(); it!= product; ++it){
        *x = *it;
        ++x;
    }
    return x;
}


// --------------
// divides_digits
// --------------

/**
 * @param b  an iterator to the beginning of an input  sequence (inclusive)
 * @param e  an iterator to the end       of an input  sequence (exclusive)
 * @param b2 an iterator to the beginning of an input  sequence (inclusive)
 * @param e2 an iterator to the end       of an input  sequence (exclusive)
 * @param x  an iterator to the beginning of an output sequence (inclusive)
 * @return   an iterator to the end       of an output sequence (exclusive)
 * the sequences are of decimal digits
 * output the division of the two input sequences into the output sequence
 * ([b1, e1) / [b2, e2)) => x
 */
template <typename II1, typename II2, typename FI>
 FI divides_digits (II1 b1, II1 e1, II2 b2, II2 e2, FI x) {
    if(e1-b1<e2-b2){
        *x = 0;
        ++x;
        return x;
    }
    std::vector<short> last_num(0);
    std::vector<short> num(1, 0);
    std::vector<short> add_one(1, 1);
    bool hit_Neg = false;
    while(!hit_Neg){
        bool tack_on = *num.begin() == 9;
        if(tack_on)
            std::vector<short> num(last_num.end()-last_num.begin()+1);
        else
            std::vector<short> num(last_num.end()-last_num.begin());
        std::vector<short>::iterator endOf_num = plus_digits(num.begin(), num.end(), add_one.begin(), add_one.end(), num.begin());
        II2 b2Copy = b2;
        std::vector<short> product(e1 - b1);
        std::vector<short>::iterator next_Multiple = multiplies_digits(b2Copy, e2, num.begin(), endOf_num, product.begin());
        std::vector<short> diff(e1-b1+1);
        II1 b1Copy = b1;
        std::vector<short>::iterator diff_End = minus_digits(b1Copy, e1, product.begin(), next_Multiple, diff.begin());
        if(*(--diff_End) == 'N'){
            hit_Neg = true;
            std::vector<short> neg_one(1, 1);
            std::vector<short> out(e1-b1);
            std::vector<short>::iterator last = minus_digits(num.begin(), endOf_num, neg_one.begin(), neg_one.end(), out.begin());
            std::vector<short>::iterator it = out.begin();
            while(it!=last){
                *x = *it;
                ++x;
                ++it;
            }
        }
        else{
            last_num = num;
        }
    }
    return x;}

// -------
// Integer
// -------

template <typename T, typename C = std::vector<T> >
    class Integer {
    // -----------
    // operator ==
    // -----------

    /**
     * Compare the contents of the rhs and lhs class instances and return 
     * true if the contents are exact, false if not exactly the same.
     */
     friend bool operator == (const Integer& lhs, const Integer& rhs) {
        //assert(lhs && rhs);
        if(lhs._neg != rhs._neg){
            return false;
        }
        if(lhs._len != rhs._len){
            return false;
        }

        typename C::const_iterator lhs_it = lhs._x.begin();
        typename C::const_iterator rhs_it = rhs._x.begin();

        bool contents_equal = true;
        while(lhs_it != lhs._x.end() && rhs_it != rhs._x.end()){
            if(*lhs_it != *rhs_it){
                contents_equal =  false;
            }
            lhs_it++;
            rhs_it++;
        }
        if(!contents_equal){
            return false;
        }
        if(lhs_it != lhs._x.end() || rhs_it != rhs._x.end()){
            return false;
        }
        return true;}

    // -----------
    // operator !=
    // -----------

    /**
     * <your documentation>
     */
     friend bool operator != (const Integer& lhs, const Integer& rhs) {
        return !(lhs == rhs);}

    // ----------
    // operator <
    // ----------

    /**
     * Input: Two Integer classes
     * Output: If LHS < RHS
     */
     friend bool operator < (const Integer& lhs, const Integer& rhs) {
        if(lhs._neg != rhs._neg){
            if(lhs._neg)
                return true;
            else
                return false;
        }
        if(lhs._len != rhs._len){
            if(lhs._len < rhs._len)
                return true;
            else
                return false;
        }
        typename C::const_reverse_iterator lhs_it = lhs._x.rbegin();
        typename C::const_reverse_iterator rhs_it = rhs._x.rbegin();
        while(lhs_it != lhs._x.rend() && rhs_it != rhs._x.rend()){
            if(*lhs_it < *rhs_it)
                return true;
            else if (*lhs_it > *rhs_it)
                return false;
            ++lhs_it;
            ++rhs_it;
        }
        return false;}

    // -----------
    // operator <=
    // -----------

    /**
     * Input: Two Integer classes
     * Output: If LHS >= RHS
     */
     friend bool operator <= (const Integer& lhs, const Integer& rhs) {
        return !(rhs < lhs);}

    // ----------
    // operator >
    // ----------

    /**
     * Input: Two Integer classes
     * Output: If LHS >= RHS
     */
     friend bool operator > (const Integer& lhs, const Integer& rhs) {
        return (rhs < lhs);}

    // -----------
    // operator >=
    // -----------

    /**
     * Input: Two Integer classes
     * Output: If LHS >= RHS
     */
     friend bool operator >= (const Integer& lhs, const Integer& rhs) {
        return !(lhs < rhs);}

    // ----------
    // operator +
    // ----------

    /**
     * Input: Two Integer classes
     * Output: Sum created by adding LHS and RHS
     */
     friend Integer operator + (Integer lhs, const Integer& rhs) {
        return lhs += rhs;}

    // ----------
    // operator -
    // ----------

    /**
     * Input: Two Integer classes
     * Output: Difference created by subtracting RHS from LHS
     */
     friend Integer operator - (Integer lhs, const Integer& rhs) {
        return lhs -= rhs;}

    // ----------
    // operator *
    // ----------

    /**
     * Input: Two Integer classes
     * Output: Product created by multiplying LHS and RHS
     */
     friend Integer operator * (Integer lhs, const Integer& rhs) {
        return lhs *= rhs;}

    // ----------
    // operator /
    // ----------

    /**
     * Input: Two Integer Classes
     * Output: Integer quotient created by dividing LHS by RHS
     * @throws invalid_argument if (rhs == 0)
     */
     friend Integer operator / (Integer lhs, const Integer& rhs) {
        if(rhs == 0)
            throw std::invalid_argument("Cannot divide by 0.");
        return lhs /= rhs;}

    // ----------
    // operator %
    // ----------

    /**
     * Input: Two Integer class instances
     * Output: Integer created by compund operations of divide and minus
     * @throws invalid_argument if (rhs <= 0)
     */
     friend Integer operator % (Integer lhs, const Integer& rhs) {
        if(rhs <= 0)
            throw std::invalid_argument("Cannot perform modulus operator with a negative number or 0.");
        return lhs %= rhs;}

    // -----------
    // operator <<
    // -----------

    /**
     * Input: Integer class instance, an int stating how many spaces to shift
     * Output: Integer created by shifting left n spaces
     * @throws invalid_argument if (rhs < 0)
     */
     friend Integer operator << (Integer lhs, int rhs) {
        if(rhs < 0)
            throw std::invalid_argument("Cannot shift negative spaces.");
        return lhs <<= rhs;}

    // -----------
    // operator >>
    // -----------

    /**
     * Input: Integer class instance, an int stating how many spaces to shift
     * Output: Integer created by shifting right n spaces
     * @throws invalid_argument if (rhs < 0)
     */
     friend Integer operator >> (Integer lhs, int rhs) {
        if(rhs < 0)
            throw std::invalid_argument("Cannot shift negative spaces.");
        else if (rhs > lhs._len)
            throw std::invalid_argument("Cannot shift a number right further than its size.");
        return lhs >>= rhs;}

    // -----------
    // operator <<
    // -----------

    /**
     * Output operator for an ostream; outputs sign first if _neg = true
     */
     friend std::ostream& operator << (std::ostream& lhs, const Integer& rhs) {
        //assert(lhs && rhs);
        if(rhs._neg)
            lhs << "-";
        for(typename C::const_reverse_iterator it = rhs._x.rbegin(); it!=rhs._x.rend(); ++it){
            lhs << *it;
        }
        return lhs;}

    // ---
    // abs
    // ---

    /**
     * absolute value
     * Input: Integer instance
     * Output: absolute value of x
     */
     friend Integer abs (Integer x) {
        return x.abs();}

    // ---
    // pow
    // ---

    /**
     * Input: Integer class instance, and an int
     * Output: Product created by compounded operations
     * @throws invalid_argument if ((x == 0) && (e == 0)) || (e < 0)
     */
     friend Integer pow (Integer x, int e) {
        if (((x == 0) && (e == 0)) || (e < 0))
            throw std::invalid_argument("Invalid arguments to pow(): Either Integer to exponentiate is not valid, or exponent is <= 0");
        return x.pow(e);}

    /*public: 
        using container_type = C;*/

    private:
        // ----
        // data
        // ----
        int _myNum; //int value of int passed to integer class
        C _x; // the backing container
        bool _neg = false;
        bool _vector;
        short _len;

    private:
        // -----
        // valid
        // -----

        bool valid () const { // class invariant
            //
            return true;}

        public:
        // ------------
        // constructors
        // ------------

        /**
         * Iteratively extract the least significant digits place and push to the back of the 
         * container. 
         */
         Integer (int value) {
            _x = C();
            _len = 0;
            if (value == 0){
                _x.push_back(0);
                _len++;
            }
            if(value<0){ 
                _neg = true;
                value = -value;
            }

            while(value){
                _x.push_back(value%10);
                value/=10;
                ++_len;
            }

#ifdef DEBUG
            int count = 1;
            for(typename C::iterator it = _x.begin(); it != _x.end(); ++it){
                std::cout << "int const: Current digit at position " << count << " is " << *it << std::endl;
                count++;
            }
            std::cout << std::endl;
#endif
            assert(valid());

        }

        /**
         * 
         * @throws invalid_argument if value is not a valid representation of an Integer
         */
         explicit Integer (const std::string& value) {
            _x = C();
            std::stringstream ss(value);
            _len = 0;
            char d;
            short sign = 1;
            while(ss >> d)
            {   
                int i = d;
                if((i > 57 || i < 48)&&i!=45)
                    throw std::invalid_argument ("Not a valid representation of an integer: 0-9, or - ");
                if(i=='-'){
                    if(sign == 1){
                        _neg = true;
                        --_len;
                    }
                    else
                        throw std::invalid_argument ("Not a valid representation of an integer: miscellaneous char present");
                }
                ++_len;
                if(i != '-')
                    _x.push_back(i-'0');

            }
            std::reverse(_x.begin(), _x.end());
#ifdef DEBUG
            int count = 1;
            for(typename C::iterator it = _x.begin(); it != _x.end(); ++it){
                std::cout << "explicit const: Current digit at position " << count << " is " << *it << std::endl;
                count++;
            }
#endif
        }

                 Integer    (const Integer&) = default;		//copy constructor
                 ~Integer   ()               = default;		//destructor
        Integer& operator = (const Integer&) = default;		//copy assignment constructor

        // ----------
        // operator -
        // ----------

        /**
         * negate an integer
         */
         Integer operator - () const {
            Integer x = *this;
            x._neg = !(x._neg);
            return x;}

        // -----------
        // operator ++
        // -----------

        /**
         * Pre-increment an Integer
         */
         Integer& operator ++ () {
            typename C::iterator it = this->_x.begin();
            *this += 1;
#ifdef DEBUG
            int count = 1;
            for(typename C::iterator its = _x.begin(); its != _x.end(); ++its){
                std::cout << "++: Current digit at position " << count << " is " << *its << std::endl;
                count++;
            }
            std::cout << std::endl;
#endif
            return *this;}

        /**
         * Post-increment and Integer
         */
         Integer operator ++ (int) {
            Integer x = *this;
            ++(*this);
            return x;}

        // -----------
        // operator --
        // -----------

        /**
         * Pre-decrement an Integer
         */
         Integer& operator -- () {
            *this -= 1;
            return *this;}

        /**
         * Post-decrement an Integer
         */
         Integer operator -- (int) {
            Integer x = *this;
            --(*this);
            return x;}

        // -----------
        // operator +=
        // -----------

        /**
         * Iterate through the rhs values and if you finish iterating through rhs before
         * finishing lhs, you then push the values of rhs onto the lhs container; otherwise,
         * if you hit the end of rhs before you finish lhs then you just carry any values from
         * previous loop iterations of rhs onto the values of lhs.
         */
         Integer& operator += (const Integer& rhs) {

            typename C::iterator b1 = this->_x.begin();
            typename C::iterator e1 = this->_x.end();
            typename C::const_iterator b2 = rhs._x.begin();
            typename C::const_iterator e2 = rhs._x.end();

            int larger = this->_len;
            if(rhs._len > larger)
                larger = rhs._len;
            C newContainer(larger + 1);
            if(this->_neg == rhs._neg){
                typename C::iterator newSize = plus_digits(b1, e1, b2, e2, newContainer.begin());
                this->_len = newSize - newContainer.begin();
                this->_x = newContainer;
                this->_x.resize(this->_len);
            }

            else{
                typename C::iterator newSize = minus_digits(b1, e1, b2, e2, newContainer.begin());
                if(*(--newSize) == '-'){
                    this->_neg = !this->_neg;
                    this->_len = newSize - newContainer.begin();
                }
                else if(is_canceled_out(newContainer.begin(), newContainer.end())){
                    this->_neg = false;
                    this->_len = 1;
                }
                else if(*newSize == 'N'){           //LHS smaller than RHS
                    C fromHigherContainer(newSize - newContainer.begin() + 1);
                    C diffContainer(fromHigherContainer.size());
                    typename C::iterator b1 = fromHigherContainer.begin();
                    typename C::iterator e1 = fromHigherContainer.end();
                    typename C::const_iterator b2 = newContainer.begin();
                    typename C::const_iterator e2 = newSize;
                    *(--e1) = 3;
                    ++e1;
                    typename C::iterator fromHigher = minus_digits(b1, e1, b2, e2, diffContainer.begin());
                    this->_len = fromHigher - diffContainer.begin();
                    newContainer = diffContainer;
                    this->_neg = !this->_neg;
                }
                else{
                    typename C::iterator b3 = newContainer.begin();
                    typename C::iterator e3 = newContainer.end();
                    --e3;
                    while(b3!=e3){
                        if(*e3!= 0){
                            ++e3;
                            newSize = e3;
                            break;
                        }
                        --e3;
                    }
                    if(b3 == e3){
                        newSize = (++e3);
                    }
                    this->_len = newSize - newContainer.begin();
                }
                this->_x = newContainer;
                this->_x.resize(this->_len);
            }

#ifdef DEBUG                                                                    
            int count = 1;                                                      
            for(typename C::iterator its = this->_x.begin(); its != this->_x.end(); ++its){    
                std::cout << "+=: Current digit at position " << count << " is " << *its << std::endl;
                count++;                                                        
            }                                                                   
#endif 
            return *this;}

        // -----------
        // operator -=
        // -----------

        /**
         * <your documentation>
         */
         Integer& operator -= (const Integer& rhs) {
            typename C::iterator b1 = this->_x.begin();
            typename C::iterator e1 = this->_x.end();
            typename C::const_iterator b2 = rhs._x.begin();
            typename C::const_iterator e2 = rhs._x.end();
            int larger = this->_len;
            if(rhs._len > larger)
                larger = rhs._len;
            C newContainer(larger + 2);
            if(this->_neg == rhs._neg){
                typename C::iterator newSize = minus_digits(b1, e1, b2, e2, newContainer.begin());
                if(*(--newSize) == '-'){
                    this->_neg = !this->_neg;
                    this->_len = newSize - newContainer.begin();
                }
                else if(is_canceled_out(newContainer.begin(), newContainer.end())){
                    this->_neg = false;
                    this->_len = 1;
                }
                else if(*newSize == 'N'){           //LHS smaller than RHS
                    C fromHigherContainer(newSize - newContainer.begin() + 1);
                    C diffContainer(fromHigherContainer.size());
                    typename C::iterator b1 = fromHigherContainer.begin();
                    typename C::iterator e1 = fromHigherContainer.end();
                    typename C::const_iterator b2 = newContainer.begin();
                    typename C::const_iterator e2 = newSize;
                    *(--e1) = 3;
                    ++e1;
                    typename C::iterator fromHigher = minus_digits(b1, e1, b2, e2, diffContainer.begin());
                    this->_len = fromHigher - diffContainer.begin();
                    newContainer = diffContainer;
                    this->_neg = !this->_neg;
                }
                else{
                    typename C::iterator b3 = newContainer.begin();
                    typename C::iterator e3 = newContainer.end();
                    --e3;
                    while(b3!=e3){
                        if(*e3!= 0){
                            ++e3;
                            newSize = e3;
                            break;
                        }
                        --e3;
                    }
                    if(b3 == e3){
                        newSize = (++e3);
                    }
                    this->_len = newSize - newContainer.begin();
                }
                
                this->_x = newContainer;
                this->_x.resize(this->_len);
            }

            else{
                typename C::iterator newSize = plus_digits(b1, e1, b2, e2, newContainer.begin());
                this->_len = newSize - newContainer.begin();
                this->_x = newContainer;
                this->_x.resize(this->_len);
            }

#ifdef DEBUG                                                                    
            int count = 1;                                                      
            for(typename C::iterator its = this->_x.begin(); its != this->_x.end(); ++its){    
                std::cout << "-=: Current digit at position " << count << " is " << *its << std::endl;
                count++;                                                        
            }                                                                   
#endif 
            return *this;}

        // -----------
        // operator *=
        // -----------

        /**
         * <your documentation>
         */
         Integer& operator *= (const Integer& rhs) {
            if(this->_neg == rhs._neg){
                this->_neg = false;
            }
            else
                this->_neg = true;
            
            typename C::iterator b1 = this->_x.begin();
            typename C::iterator e1 = this->_x.end();
            typename C::const_iterator b2 = rhs._x.begin();
            typename C::const_iterator e2 = rhs._x.end();

            int larger = this->_len;
            if(rhs._len > larger)
                larger = rhs._len;
            short productLength = 2*larger;
            C newContainer(productLength);
            typename C::iterator newSize = multiplies_digits(b1, e1, b2, e2, newContainer.begin());

            this->_len = newSize - newContainer.begin();
            this->_x = newContainer;
            this->_x.resize(this->_len);
            if(this->_len == 1 && *newContainer.begin() == 0)
                this->_neg = false;
            //assert(1==0);
            return *this;
        }


        // -----------
        // operator /=
        // -----------

        /**
         * <your documentation>
         * @throws invalid_argument if (rhs == 0)
         */
         Integer& operator /= (const Integer& rhs) {

            if(this->_neg == rhs._neg){
                this->_neg = false;
            }
            else
                this->_neg = true;
            typename C::iterator b1 = this->_x.begin();
            typename C::iterator e1 = this->_x.end();
            typename C::const_iterator b2 = rhs._x.begin();
            typename C::const_iterator e2 = rhs._x.end();
            int larger = this->_len;
            if(rhs._len > larger)
                larger = rhs._len;
            C newContainer(larger);
            typename C::iterator newSize = divides_digits(b1, e1, b2, e2, newContainer.begin());
            this->_len = newSize - newContainer.begin();
            this->_x = newContainer;
            this->_x.resize(this->_len);
            if(this->_len == 1 && *newContainer.begin() == 0)
                this->_neg = false;
            //assert(1==0);
            return *this;
        }

        // -----------
        // operator %=
        // -----------

        /**
         * <your documentation>
         * @throws invalid_argument if (rhs <= 0)
         */
         Integer& operator %= (const Integer& rhs) {
            if(this->_neg)
                this->_neg=!this->_neg;

            typename C::iterator b1 = this->_x.begin();
            typename C::iterator e1 = this->_x.end();
            typename C::const_iterator b2 = rhs._x.begin();
            typename C::const_iterator e2 = rhs._x.end();

            C divides(this->_len);
            typename C::iterator floor_Divide = divides_digits(b1, e1, b2, e2, divides.begin());
            divides.resize(floor_Divide - divides.begin());

            C newContainer(this->_len);
            typename C::iterator cb1 = divides.begin();
            typename C::iterator ce1 = divides.end();
            typename C::const_iterator cb2 = rhs._x.begin();
            typename C::const_iterator ce2 = rhs._x.end();
            typename C::iterator mult_Diff = multiplies_digits(cb1, ce1, cb2, ce2, newContainer.begin());

            C newRem(this->_len+1);
            typename C::iterator c1b1 = this->_x.begin();
            typename C::iterator c1e1 = this->_x.end();
            typename C::iterator c2b2 = newContainer.begin();
            typename C::iterator c2e2 = newContainer.end();
            typename C::iterator get_Remainder = minus_digits(c1b1, c1e1, c2b2, c2e2, newRem.begin());

            if(is_canceled_out(newRem.begin(), get_Remainder)){
                std::cout<<"zeroed out\n";
                this->_len = 1;
            }
            else{
                typename C::reverse_iterator last_index = newRem.rbegin();
                typename C::reverse_iterator end = newRem.rend();
                while(last_index!=end){
                    if(*last_index != 0)
                        this->_len = end - last_index;
                    ++last_index;
                }
            }
            this->_x = newRem;
            this->_x.resize(this->_len);
            return *this;
        }

        // ------------
        // operator <<=
        // ------------

        /**
         * <your documentation>
         */
         Integer& operator <<= (int n) {
            typename C::iterator b = this->_x.begin(); 
            typename C::iterator e = this->_x.end();
            C newContainer(this->_len + n + 1);
            typename C::iterator newSize = shift_left_digits(b, e, n, newContainer.begin());
            this->_x = newContainer;
            this->_len += n;//newSize - newContainer.begin();
            this->_x.resize(this->_len);

#ifdef DEBUG                                                                    
            int count = 1;                                                      
            for(typename C::iterator its = this->_x.begin(); its != this->_x.end(); ++its){    
                std::cout << "<<=: Current digit at position " << count << " is " << *its << std::endl;
                count++;                                                        
            } 
#endif 
            return *this;}

        // ------------
        // operator >>=
        // ------------

        /**
         * 
         */
         Integer& operator >>= (int n) {
            typename C::iterator b = this->_x.begin(); 
            typename C::iterator e = this->_x.end();                              
            C newContainer(this->_len);
            typename C::iterator newSize = shift_right_digits(b, e, n, newContainer.begin());
            this->_x = newContainer;
            this->_len -= n;//newSize - newContainer.begin();
            this->_x.resize(this->_len);
#ifdef DEBUG                                                                    
            int count = 1;                                                      
            for(typename C::iterator its = this->_x.begin(); its != this->_x.end(); ++its){    
                std::cout << ">>=: Current digit at position " << count << " is " << *its << std::endl;
                count++;                                                        
            } 
#endif 
            return *this;}

        // ---
        // abs
        // ---

        /**
         * absolute value
         * Sets this instance's _neg to false
         */
         Integer& abs () {
            this->_neg = false;
            return *this;}

        // ---
        // pow
        // ---

        /**
         * power
         * <your documentation>
         * @throws invalid_argument if ((this == 0) && (e == 0)) or (e < 0)
         */
         Integer& pow (int e) {
            Integer start = *this;
            Integer result = 1;
            if(e == 0){
                *this = result;
            }
            if(e > 1)
                result = start.pow(e/2);  
            if(!(e % 2)) 
                result *= result;
            else{      
                result *= result;
                result *= *this;
            } 
            *this = result;
            return *this;
        }
    };

#endif // Integer_h
