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
    int len1 = 0;
    int len2 = 0;
    int rangeDiff;
    int dig_1;
    int dig_2;
    int diff;
    bool carry = false;
    II1 e1_copy = e1;
    II2 e2_copy = e2;
    FI x_begin = x;
    //++b1;

    while(e1_copy != b1){
        ++len1;
        --e1_copy;
    }
    //++b2;
    while(e2_copy != b2){
        ++len2;
        --e2_copy;
    }

    int count = 0;

    if(len2 > len1){
        rangeDiff = len2 - len1;
        std::cout << "MD: Value of RangeDiff: " << rangeDiff << std::endl;
        while(e1 != b1){
            dig_1 = *b1;
            dig_2 = *b2;

            std::cout << "MD: Value of dig_1: " << dig_1 << std::endl;
            std::cout << "MD: Value of dig_2: " << dig_2 << std::endl << std::endl;
            diff = dig_1 - dig_2;
            if(diff < 0){
                carry = true;
                dig_1+=10;
                diff = dig_1 - dig_2;
                std::cout << "MD: Value of dig_1 after addition: "  << dig_1 << std::endl;
                std::cout << "MD: Value of diff after subtracting dig_2: " << diff << std::endl << std::endl;
               
            }
	    else
		carry = false;
                
		
                std::cout << "MD: Value of diff after not subtracting dig_2: " << diff << std::endl;
		*x = diff;
                ++x;
                ++b1;
                ++b2;
                count++;
        }

        std::cout << "MD: This value should equal len1: " << count << std::endl;

        while(e2 != b2){
            
            dig_1 = 10;
            dig_2 = *b2;
            diff = dig_1 - dig_2;
	    std::cout << "MD: Value of diff after first While loop: " << diff << std::endl;
            *x = diff;
            ++x;
            ++b2;
            count++;
        }

        std::cout << "MD: Len1 + rangeDiff: " << count << std::endl << std::endl << std::endl;
		
		int output_len = rangeDiff + len1;
        if(carry){
            
	    --x;
            for(int i = 0; i < output_len; i++){
                diff = 10 - *x;
                *x = diff;
		std::cout << "This is the value of *x: " << *x << std::endl;
                --x;
            }

        //std::cout << "This is the value of *x: " << *x << std::endl;

            //diff = 9 - *x;
        }
	else{
		
		--x;
		std::cout << "Starting value of *x: " << *x << std::endl;
		int loopRange = rangeDiff + len1;
		int tmpRange = rangeDiff ;
		int k = 0;
		
		//std::cout << "This is the value of *x: " << *x << std::endl;
	    for(int i = 0; i < loopRange; i++){
		
		diff = 10 - *x;
		if(diff == 10)
			diff = 0;
		if(k == tmpRange - 1)
			--diff;

		*x = diff;
		k++;
		std::cout << "This is the value of *x: " << *x << std::endl;
		--x;
	    }
			
	}

    }

	//delete this after testing
        int out_len = rangeDiff + len1;
	++x;
        for(int i = 0; i < out_len; i++){

            std::cout << "Value of * x: " <<  *x << "  Pos in x: " << i << std::endl;
            ++x; 
        }
	std::cout << std::endl;
        std::cout << "MD: Value of output_len: "  << out_len << std::endl;
        std::cout << "Minus_digits; Checking len of input iterator 1: " << len1 << std::endl;
        std::cout << "Minus_digits; Checking len of input iterator 2: " << len2 << std::endl;

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
            typename C::iterator it = this->_x.begin();
            typename C::const_iterator rhs_it = rhs._x.begin();
            typename C::iterator end_lhs = this->_x.end();

            bool carry = false;
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
