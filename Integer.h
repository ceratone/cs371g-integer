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
    // if(b==e){
    //     *x = *b;
    // }
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
                int temp = *b2+1;
                if(temp>=10){
                    carry = true;
                    temp %= 10;
                }
                else
                    carry = false;
                
                *x = temp;
                x++;
            }
            else{
                
                *x = *b2;
                x++;
            }
        }
        b2++;
    }
    if(carry){
        if(b1 != e1)
        {
            while(carry){
                if(b1 == e1){
                    *x = 1;
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
<<<<<<< HEAD
    
=======
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
                
		
                std::cout << "MD: Value of diff after if/else diff: " << diff << std::endl;
		*x = diff;
                ++x;
                ++b1;
                ++b2;
                count++;
        }

        std::cout << "MD: Count should equal len1: " << count << std::endl;

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
    else if(len2 == len1){
	    
	    
	    while(e1 != b1){
            	dig_1 = *b1;
            	dig_2 = *b2;

            std::cout << "MD: Value of dig_1: " << dig_1 << std::endl;
            std::cout << "MD: Value of dig_2: " << dig_2 << std::endl << std::endl;
            	diff = dig_1 - dig_2;
		int chk_diff = diff;
            	if(diff < 0){
                	carry = true;
                	dig_1+=10;
                	diff = dig_1 - dig_2;
		
                std::cout << "MD: Value of dig_1 after addition: "  << dig_1 << std::endl;
                std::cout << "MD: Value of diff after subtracting dig_2: " << diff << std::endl << std::endl;
               
           	 }
	    	else{
			if(carry && diff != 0){
			   int tmp = diff;	
			   diff = 9 - tmp;
			}					

			carry = false;
		}	 
               	 std::cout << "MD: Value of diff after if/else diff: " << diff << std::endl;

		if(carry){
			int tmp = diff;
			diff = 10 - tmp;
		}
		
		
			*x = diff;
                	++x;
                	++b1;
                	++b2;
                	count++;
		if(carry && e1 != b1)
		{
			int chk_1 = *b1;
			int chk_2 = *b2;
			
			if(chk_1 == 0)
				*b1 = 9;
			if(chk_1 > 0 && chk_1 > chk_2)
				--*b1;
				
		}

		if(carry && e1 == b1){
		    --x;

		    if(chk_diff == 0 || chk_diff == 1)
			++x;

		    if(chk_diff > 0 ){
			--diff;
			*x = diff;
			++x;	
		    }
		    ++x;
		    
			
		}
	     }
		
	
	
    }
    else{
	bool nxt_carry;	 
	while(e2 != b2){
            	dig_1 = *b1;
            	dig_2 = *b2;

            
            	diff = dig_1 - dig_2;
	    std::cout << "MD: Value of dig_1: " << dig_1 << std::endl;
            std::cout << "MD: Value of dig_2: " << dig_2 << std::endl;
	    std::cout << "MD: Value of chkdiff: " << diff << std::endl << std::endl; 
		int chk_diff = diff;
            	if(diff < 0){
                	carry = true;
                	dig_1+=10;
                	diff = dig_1 - dig_2;
		
                std::cout << "MD: Value of dig_1 after addition: "  << dig_1 << std::endl;
                std::cout << "MD: Value of diff after subtracting dig_2: " << diff << std::endl << std::endl;
               
           	 }
	    	else{
			if(carry)    				   				   nxt_carry = true;
									
			carry = false;
		}	 
               	 std::cout << "MD: Value of diff after if/else diff: " << diff << std::endl;

		
		
			*x = diff;
                	++x;
                	++b1;
                	++b2;
                
			count++;
		if(carry)
		{
			int chk_1 = *b1;
			//int chk_2 = *b2;
			
			if(chk_1 == 0)
				*b1 = 9;
			if(chk_1 > 0)
				--*b1;
				
		}
		
		if(!carry && nxt_carry)
			--*b1;
	    }
		
		

		while(e1 != b1){
		    dig_1 = *b1;
            	    dig_2 = 0;
            	    diff = dig_1 - dig_2;
	    	    std::cout << "MD: Value of diff after first While loop: " << diff << std::endl;
            	    *x = diff;
            	    ++x;
            	    ++b1;
            	    count++;

		}
    }

	//delete this after testing
	
        int out_len = len1;
	--x;
	
        for(int i = 1; i < out_len + 1; i++){

            std::cout << "Value of * x: " <<  *x << "  Pos in x: " << i << std::endl;
            --x; 
        }
	std::cout << std::endl;
        std::cout << "MD: Value of output_len: "  << out_len << std::endl;
        std::cout << "Minus_digits; Checking len of input iterator 1: " << len1 << std::endl;
        std::cout << "Minus_digits; Checking len of input iterator 2: " << len2 << std::endl;

>>>>>>> 8d5b9cffcdc49a38193eb0571228987aa930180c
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
     * Compare the contents of the rhs and lhs class instances and return 
     * true if the contents are exact, false if not exactly the same.
     */
     friend bool operator == (const Integer& lhs, const Integer& rhs) {
        //assert(lhs && rhs);
        if(lhs._neg != rhs._neg){
            // std::cout<< "------------Signs do not match" <<std::endl;
            return false;
        }
        if(lhs._len != rhs._len){
            // std::cout << "--------------Lengths do not match" <<std::endl;
            // std::cout << "-----------Length of lhs: "<<lhs._len<<" vs. length of rhs: "<<rhs._len<< std::endl;
            return false;
        }

        typename C::const_iterator lhs_it = lhs._x.begin();
        typename C::const_iterator rhs_it = rhs._x.begin();


        while(lhs_it != lhs._x.end() && rhs_it != rhs._x.end()){
            if(*lhs_it != *rhs_it){
                // std::cout<< "-----------Contents do not match" <<std::endl;
                return false;
            }
            // std::cout<< "Contents of lhs: "<<*lhs_it<< " vs. contents of rhs: "<<*(rhs_it) <<std::endl;
            lhs_it++;
            rhs_it++;
        }
        if(lhs_it != lhs._x.end() || rhs_it != rhs._x.end()){
            // std::cout<< "-------------Inequal ends" <<std::endl;
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
            //std::cout<< "previous sign of this int: "<<x._neg<< std::endl;
            // for(typename C::iterator it = x._x.begin(); it != x._x.end(); ++it){
            //     //std::cout << "Result of negate("<<*it<<") is: ";
            //     *it = -(*it);
            //     //std::cout << *it << std::endl;
            // } 
            x._neg = !(x._neg);
            //std::cout<< "result sign of this int: "<<x._neg<< std::endl;
            return x;}

        // -----------
        // operator ++
        // -----------

        /**
         * Pre-increment an Integer
         */
         Integer& operator ++ () {
            typename C::iterator it = this->_x.begin();
            //typename C::iterator e1 = this->_x.begin();
            // 
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
                //std::cout << "newSize: " << this->_len <<std::endl;
                this->_x = newContainer;
                this->_x.resize(this->_len);
            }

            else{
                typename C::iterator newSize = minus_digits(b1, e1, b2, e2, newContainer.begin());
                this->_len = newSize - newContainer.begin();
                //std::cout << "newSize: " << this->_len <<std::endl;
                this->_x = newContainer;
                this->_x.resize(this->_len);
            }
            //std::cout << "End of newContainer: " << *(--newContainer.end()) <<std::endl;
            // if(*(newContainer.end()--) == 0){
            //     this->_len = newContainer.size() - 1;
            //     std::cout << "newSize smaller: " << this->_len <<std::endl;
            // }
            // else
                
     
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
<<<<<<< HEAD
         Integer& operator -= (const Integer& rhs) {
            typename C::iterator it = this->_x.begin();
            typename C::const_iterator rhs_it = rhs._x.begin();

            
=======
        Integer& operator -= (const Integer& rhs) {
            // <your code>
            typename C::iterator it = this->_x.begin();
            typename C::const_iterator rhs_it = rhs._x.begin();
            typename C::iterator end_lhs = this->_x.end();

            bool carry = false;
>>>>>>> 8d5b9cffcdc49a38193eb0571228987aa930180c
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
            // <your code>
            return *this;}
        };

#endif // Integer_h
