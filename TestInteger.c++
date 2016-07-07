#include <iostream> // cout, endl
#include <sstream>  // istringstream, ostringstream
#include <string>   // string
#include <deque>
#include <algorithm>
#include "gtest/gtest.h"
#include "Integer.h"

using namespace std;

/* LEFT SHIFT */
TEST(IntegerTest, left_shift_1){
	Integer<int> x = Integer<int>(1234);
    const Integer<int> y = x<<3;
    const Integer<int> result = Integer<int>(1234000);
    ASSERT_TRUE(y == result);
}

TEST(IntegerTest, left_shift_2){
	Integer<int> x = Integer<int>(5477895);
    const Integer<int> y = x<<6;
    const Integer<int> result = Integer<int>("5477895000000");
    ASSERT_TRUE(y == result);
}

TEST(IntegerTest, left_shift_3){
	Integer<int> x = Integer<int>("500005000");
    const Integer<int> y = (x>>8)<<9;

    const Integer<int> result = Integer<int>("5000000000");
    ASSERT_TRUE(y == result);
}

/* RIGHT SHIFT */
TEST(IntegerTest, right_shift_1){
	Integer<int> x = Integer<int>(1234);
    const Integer<int> y = x>>3;
    const Integer<int> result = Integer<int>(1);
    ASSERT_TRUE(y == result);
}

TEST(IntegerTest, right_shift_2){
	Integer<int> x = Integer<int>("35763847568375683745");
    const Integer<int> y = x>>16;
    const Integer<int> result = Integer<int>(3576);
    ASSERT_TRUE(y == result);
}

TEST(IntegerTest, right_shift_3){
	Integer<int> x = Integer<int>("357638475683756837454358734658736587368456387465837658376583475");
    const Integer<int> y = (x>>30)<<30;
    const Integer<int> result = Integer<int>("357638475683756837454358734658736000000000000000000000000000000");
    ASSERT_TRUE(y == result);
}
TEST(IntegerTest, right_shift_4){
	const Integer<int> x = Integer<int>("35763847568375683745");
    const Integer<int> y = (((x >> 19)<<30)>>31)<<1;
    const Integer<int> result = Integer<int>(0);
    ASSERT_TRUE(y == result);
}

/* NEGATE */
TEST(IntegerTest, negate_1){
	const Integer<int> x = Integer<int>("-35763847568375683745");
    const Integer<int> y = -x;
    const Integer<int> z = Integer<int>("35763847568375683745");
    ASSERT_TRUE(y == z);
}

TEST(IntegerTest, negate_2){
	const Integer<int> x = Integer<int>("-1");
    const Integer<int> y = -x;
    const Integer<int> z = Integer<int>("1");
    ASSERT_TRUE(y == z);
}

TEST(IntegerTest, negate_3){
	const Integer<int> x = Integer<int>("3246824628374628764287643287468276487268236655655565656565656565600000000");
    const Integer<int> y = -(x>>40);
    const Integer<int> z = Integer<int>("-324682462837462876428764328746827");
    ASSERT_TRUE(y == z);
}

/* ABSOLUTE VALUE */
TEST(IntegerTest, abs_1){
	Integer<int> x = Integer<int>("-35763847568375683745");
    x = x.abs();
    const Integer<int> z = Integer<int>("35763847568375683745");
    ASSERT_TRUE(x == z);
}

TEST(IntegerTest, abs_2){
	Integer<int> x = Integer<int>("35763847568375683745");
    x = x.abs();
    const Integer<int> z = Integer<int>("35763847568375683745");
    ASSERT_TRUE(x == z);
}

TEST(IntegerTest, abs_3){
	Integer<int> x = Integer<int>(0);
    x = x.abs();
    const Integer<int> z = Integer<int>(0);
    ASSERT_TRUE(x == z);
}

/* LESS THAN */
TEST(IntegerTest, less_than_1){
	Integer<int> x = Integer<int>("-35763847568375683745");
    const Integer<int> y = Integer<int>("35763847568375683745");
    ASSERT_TRUE(x < y);
}

TEST(IntegerTest, less_than_2){
	Integer<int> x = Integer<int>("35763847568375683745");
    const Integer<int> y = Integer<int>("-35763847568375683745");
    ASSERT_FALSE(x < y);
}

TEST(IntegerTest, less_than_3){
	Integer<int> x = Integer<int>("35");
    const Integer<int> y = Integer<int>("35");
    ASSERT_FALSE(x < y);
}

/* LESS THAN EQUAL */
TEST(IntegerTest, less_than_equal_1){
	Integer<int> x = Integer<int>("-35763847568375683745");
    const Integer<int> y = Integer<int>("35763847568375683745");
    ASSERT_TRUE(x <= y);
}

TEST(IntegerTest, less_than_equal_2){
	Integer<int> x = Integer<int>("35763847568375683745");
    const Integer<int> y = Integer<int>("-35763847568375683745");
    ASSERT_FALSE(x <= y);
}

TEST(IntegerTest, less_than_equal_3){
	Integer<int> x = Integer<int>("35");
    const Integer<int> y = Integer<int>("35");
    ASSERT_TRUE(x <= y);
}

/* GREATER THAN */
TEST(IntegerTest, greater_than_1){
	Integer<int> x = Integer<int>("-35763847568375683745");
    const Integer<int> y = Integer<int>("35763847568375683745");
    ASSERT_FALSE(x > y);
}

TEST(IntegerTest, greater_than_2){
	Integer<int> x = Integer<int>("35763847568375683745");
    const Integer<int> y = Integer<int>("-35763847568375683745");
    ASSERT_TRUE(x > y);
}

TEST(IntegerTest, greater_than_3){
	Integer<int> x = Integer<int>("35");
    const Integer<int> y = Integer<int>("35");
    ASSERT_FALSE(x > y);
}

/* GREATER THAN EQUAL */
TEST(IntegerTest, greater_than_equal_1){
	Integer<int> x = Integer<int>("-35763847568375683745");
    const Integer<int> y = Integer<int>("35763847568375683745");
    ASSERT_FALSE(x >= y);
}

TEST(IntegerTest, greater_than_equal_2){
	Integer<int> x = Integer<int>("35763847568375683745");
    const Integer<int> y = Integer<int>("-35763847568375683745");
    ASSERT_TRUE(x >= y);
}

TEST(IntegerTest, greater_than_equal_3){
	Integer<int> x = Integer<int>("35");
    const Integer<int> y = Integer<int>("35");
    ASSERT_TRUE(x >= y);
}

/* EQUAL */
TEST(IntegerTest, equal_1){
	Integer<int> x = Integer<int>("35763847568375683745");
    const Integer<int> y = Integer<int>("35763847568375683745");
    ASSERT_TRUE(x == y);
}

TEST(IntegerTest, equal_2){
	Integer<int> x = Integer<int>("35763847568375683745");
    const Integer<int> y = Integer<int>("-35763847568375683745");
    ASSERT_FALSE(x == y);
}

TEST(IntegerTest, equal_3){
	Integer<int> x = Integer<int>("35");
	x = x >> 2;
	x = x << 1;
    const Integer<int> y = Integer<int>(0);
    ASSERT_TRUE(x == y);
}

/* NOT EQUAL */
TEST(IntegerTest, not_equal_1){
	Integer<int> x = Integer<int>("-35763847568375683745");
    const Integer<int> y = Integer<int>("35763847568375683745");
    ASSERT_TRUE(x != y);
}

TEST(IntegerTest, not_equal_2){
	Integer<int> x = Integer<int>("35763847568375683745");
    const Integer<int> y = Integer<int>("-35763847568375683745");
    ASSERT_TRUE(x != y);
}

TEST(IntegerTest, not_equal_3){
	Integer<int> x = Integer<int>("35");
	x = x >> 2;
	x = x << 1;
    const Integer<int> y = Integer<int>(0);
    ASSERT_FALSE(x != y);
}