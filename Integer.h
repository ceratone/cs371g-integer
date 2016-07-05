// ------------------------------
// projects/c++/integer/Integer.h
// Copyright (C) 2016
// Glenn P. Downing
// ------------------------------

#define DEBUG 

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
    // <your code>
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
    // <your code>
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
    // <your code>
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
    // <your code>
    return x;}

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
    // <your code>
    return x;}

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
    // <your code>
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
     * <your documentation>
     */
    friend bool operator == (const Integer& lhs, const Integer& rhs) {
        // <your code>
        return false;}

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
     * <your documentation>
     */
    friend bool operator < (const Integer& lhs, const Integer& rhs) {
        // <your code>
        return false;}

    // -----------
    // operator <=
    // -----------

    /**
     * <your documentation>
     */
    friend bool operator <= (const Integer& lhs, const Integer& rhs) {
        return !(rhs < lhs);}

    // ----------
    // operator >
    // ----------

    /**
     * <your documentation>
     */
    friend bool operator > (const Integer& lhs, const Integer& rhs) {
        return (rhs < lhs);}

    // -----------
    // operator >=
    // -----------

    /**
     * <your documentation>
     */
    friend bool operator >= (const Integer& lhs, const Integer& rhs) {
        return !(lhs < rhs);}

    // ----------
    // operator +
    // ----------

    /**
     * <your documentation>
     */
    friend Integer operator + (Integer lhs, const Integer& rhs) {
        return lhs += rhs;}

    // ----------
    // operator -
    // ----------

    /**
     * <your documentation>
     */
    friend Integer operator - (Integer lhs, const Integer& rhs) {
        return lhs -= rhs;}

    // ----------
    // operator *
    // ----------

    /**
     * <your documentation>
     */
    friend Integer operator * (Integer lhs, const Integer& rhs) {
        return lhs *= rhs;}

    // ----------
    // operator /
    // ----------

    /**
     * <your documentation>
     * @throws invalid_argument if (rhs == 0)
     */
    friend Integer operator / (Integer lhs, const Integer& rhs) {
        return lhs /= rhs;}

    // ----------
    // operator %
    // ----------

    /**
     * <your documentation>
     * @throws invalid_argument if (rhs <= 0)
     */
    friend Integer operator % (Integer lhs, const Integer& rhs) {
        return lhs %= rhs;}

    // -----------
    // operator <<
    // -----------

    /**
     * <your documentation>
     * @throws invalid_argument if (rhs < 0)
     */
    friend Integer operator << (Integer lhs, int rhs) {
        return lhs <<= rhs;}

    // -----------
    // operator >>
    // -----------

    /**
     * <your documentation>
     * @throws invalid_argument if (rhs < 0)
     */
    friend Integer operator >> (Integer lhs, int rhs) {
        return lhs >>= rhs;}

    // -----------
    // operator <<
    // -----------

    /**
     * <your documentation>
     */
    friend std::ostream& operator << (std::ostream& lhs, const Integer& rhs) {
        // <your code>
        return lhs << "0";}

    // ---
    // abs
    // ---

    /**
     * absolute value
     * <your documentation>
     */
    friend Integer abs (Integer x) {
        return x.abs();}

    // ---
    // pow
    // ---

    /**
     * power
     * <your documentation>
     * @throws invalid_argument if ((x == 0) && (e == 0)) || (e < 0)
     */
    friend Integer pow (Integer x, int e) {
        return x.pow(e);}
    
    /*public: 
        using container_type = C;*/

    private:
        // ----
        // data
        // ----
        int _myNum; //int value of int passed to integer class
        C _x; // the backing container
        bool neg;
        bool _vector;

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
            _myNum =  value;
            _x = C();
            while(value){
                _x.push_back(value%10);
                value/=10;
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
            _myNum = std::atoi ( value.c_str());
            std::stringstream ss(value);
            char d;
                while(ss >> d)
                {   

                    int i = d;
                    if(i > 57 || i < 48)
                        throw std::invalid_argument ("Not a valid representation of an integer: 0-9");
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
         * 
         */
        Integer operator - () const {
            Integer x = *this;
            for(typename C::iterator it = x._x.begin(); it != x._x.end(); ++it){
                //std::cout << "Result of negate("<<*it<<") is: ";
                *it = -(*it);
                //std::cout << *it << std::endl;
            }            
            //int tmp = -_myNum;
            return x;}//Integer(tmp);} // fix

        // -----------
        // operator ++
        // -----------

        /**
         * <your documentation>
         */
        Integer& operator ++ () {
        //not sure if this how you implement the overload of add
        //Needs a look over
            typename C::iterator it = this->_x.begin();
            bool carry = true;
            while(carry){
                ++*it;
                if(*it == 10){
                    *it = 0;
                    if(it == this->_x.end()){
                        this->_x.push_back(1);
                        carry = false;
                    }
                    else
                        it++;
                }
                else
                    carry = false;
            }
#ifdef DEBUG
            int count = 1;
            for(typename C::iterator its = _x.begin(); its != _x.end(); ++its){
                std::cout << "++: Current digit at position " << count << " is " << *its << std::endl;
                count++;
            }
            std::cout << std::endl;
#endif
            // if(this->_x < 9)
            // {
            //     int tmp = _x.pop_back();
            //         ++tmp;
            //         _x.push_back(tmp);
            // }
            // else
            // {
            //     //in this else I would check the container until
            //     //I reach a number less than 9. Set all previous
            //     //digits to zero, add 1 to the digit that was less
            //     //than 9 then push all digits back into container.
            // }
            //*this += 1;
            return *this;}

        /**
         * <your documentation>
         */
        Integer operator ++ (int) {
            Integer x = *this;
            ++(*this);
            return x;}

        // -----------
        // operator --
        // -----------

        /**
         * <your documentation>
         */
        Integer& operator -- () {
            *this -= 1;
            return *this;}

        /**
         * <your documentation>
         */
        Integer operator -- (int) {
            Integer x = *this;
            --(*this);
            return x;}

        // -----------
        // operator +=
        // -----------

        /**
         * <your documentation>
         */
        Integer& operator += (const Integer& rhs) {
            
            typename C::iterator it = this->_x.begin();
            typename C::const_iterator rhs_it = rhs._x.begin();
            typename C::iterator end_lhs = this->_x.end();
            
            bool carry = false;
            while(rhs_it!= rhs._x.end()){

                if(it != end_lhs){
                    *it = *it + *rhs_it;
                    if(carry){
                        ++*it;
                        carry = false;
                    }
                    if(*it >= 10){
                        *it %=10;
                        carry = true;
                    }
                    it++;
                }
                else{
                    if(carry){
                        int temp = *rhs_it+1;
                        if(temp>=10){
                            carry = true;
                            temp %= 10;
                        }
                        else
                            carry = false;

                        this->_x.push_back(temp);
                        
                    }
                    else{
                        this->_x.push_back(*rhs_it);
                    }
                }
                rhs_it++;
            }
            if(carry){
                if(it != this->_x.end())
                {
                    while(carry){
                        if(it == this->_x.end()){
                            this->_x.push_back(1);
                            carry = false;
                        }
                        else if(*it == 10){
                            *it = 0;
                            carry = true;
                            it++;
                        }
                        else{
                            carry = false;
                        }
                        ++*it;
                    }
                }
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
            // <your code>
            return *this;}

        // -----------
        // operator *=
        // -----------

        /**
         * <your documentation>
         */
        Integer& operator *= (const Integer& rhs) {
            // <your code>
            return *this;}

        // -----------
        // operator /=
        // -----------

        /**
         * <your documentation>
         * @throws invalid_argument if (rhs == 0)
         */
        Integer& operator /= (const Integer& rhs) {
            // <your code>
            return *this;}

        // -----------
        // operator %=
        // -----------

        /**
         * <your documentation>
         * @throws invalid_argument if (rhs <= 0)
         */
        Integer& operator %= (const Integer& rhs) {
            // <your code>
            return *this;}

        // ------------
        // operator <<=
        // ------------

        /**
         * <your documentation>
         */
        Integer& operator <<= (int n) {
            // <your code>
            return *this;}

        // ------------
        // operator >>=
        // ------------

        /**
         * <your documentation>
         */
        Integer& operator >>= (int n) {
            // <your code>
            return *this;}

        // ---
        // abs
        // ---

        /**
         * absolute value
         * <your documentation>
         */
        Integer& abs () {
            // <your code>
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
            // <your code>
            return *this;}
        };

#endif // Integer_h
