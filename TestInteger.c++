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
/* ADDITION */
TEST(IntegerTest, add_1){
	Integer<int> x = Integer<int>("12");
    const Integer<int> y = Integer<int>("4");
    const Integer<int> z = x + y;
    const Integer<int> w = Integer<int>(16);
    ASSERT_TRUE(z == w);
}

TEST(IntegerTest, add_2){
	Integer<int> x = Integer<int>("125353");
    Integer<int> y = Integer<int>("43453543");
    const Integer<int> z = x + y;
    const Integer<int> w = Integer<int>(43578896);
    ASSERT_TRUE(z == w);
}

TEST(IntegerTest, add_3){
	Integer<int> x = Integer<int>("12535");
    Integer<int> y = Integer<int>("43453543");
    const Integer<int> z = x + y;
    const Integer<int> w = Integer<int>(43466078);
    ASSERT_TRUE(z == w);
}

TEST(IntegerTest, add_4){
	Integer<int> x = Integer<int>("12343434");
    Integer<int> y = Integer<int>("12343434");
    const Integer<int> z = x + y;
    const Integer<int> w = Integer<int>(24686868);
    ASSERT_TRUE(z == w);
}

TEST(IntegerTest, add_5){
	Integer<int> x = Integer<int>("12343434");
    Integer<int> y = Integer<int>(0);
    const Integer<int> z = x + y;
    const Integer<int> w = Integer<int>("12343434");
    ASSERT_TRUE(z == w);
}

TEST(IntegerTest, add_negative_1){
	Integer<int> x = Integer<int>("-12343434");
    Integer<int> y = Integer<int>("-12343434");
    const Integer<int> z = x + y;
    const Integer<int> w = Integer<int>("-24686868");
    ASSERT_TRUE(z == w);
}

TEST(IntegerTest, add_negative_positive_1){
	Integer<int> x = Integer<int>("-12343434");
    const Integer<int> y = Integer<int>("34");
    const Integer<int> z = x + y;
    const Integer<int> w = Integer<int>("-12343400");
    ASSERT_TRUE(z == w);
}

TEST(IntegerTest, add_negative_positive_2){
	Integer<int> x = Integer<int>("-12343434");
    const Integer<int> y = Integer<int>("12343434");
    const Integer<int> z = x + y;
    const Integer<int> w = Integer<int>("0");
    ASSERT_TRUE(z == w);
}

TEST(IntegerTest, add_negative_positive_3){
	Integer<int> x = Integer<int>("12343434");
    const Integer<int> y = Integer<int>("-34");
    const Integer<int> z = x + y;
    const Integer<int> w = Integer<int>("12343400");
    ASSERT_TRUE(z == w);
}

TEST(IntegerTest, add_negative_positive_4){
	Integer<int> x = Integer<int>("12343434");
    const Integer<int> y = Integer<int>("-56565656");
    const Integer<int> z = x + y;
    const Integer<int> w = Integer<int>("-44222222");
    ASSERT_TRUE(z == w);
}

/* SUBTRACTION */
TEST(IntegerTest, subtract_1){
	Integer<int> x = Integer<int>("-12343434");
    Integer<int> y = Integer<int>(0);
    Integer<int> z = x - y;
    Integer<int> w = Integer<int>("-12343434");
    ASSERT_TRUE(z == w);
}

TEST(IntegerTest, subtract_2){
	Integer<int> x = Integer<int>("0");
    Integer<int> y = Integer<int>("12343434");
    Integer<int> z = x - y;
    Integer<int> w = Integer<int>("-12343434");
    ASSERT_TRUE(z == w);
}

TEST(IntegerTest, subtract_3){
	Integer<int> x = Integer<int>("0");
    Integer<int> y = Integer<int>("34");
    Integer<int> z = x - y;
    Integer<int> w = Integer<int>("-34");
    ASSERT_TRUE(z == w);
}

TEST(IntegerTest, subtract_4){
	Integer<int> x = Integer<int>("10022");
    Integer<int> y = Integer<int>(199);
    Integer<int> z = x - y;
    Integer<int> w = Integer<int>("9823");
    ASSERT_TRUE(z == w);
}

TEST(IntegerTest, subtract_5){
	Integer<int> x = Integer<int>("10000000000000000000000000000022");
    Integer<int> y = Integer<int>("999999999999");
    Integer<int> z = x - y;
    Integer<int> w = Integer<int>("9999999999999999999000000000023");
    ASSERT_TRUE(z == w);
}

TEST(IntegerTest, subtract_6){
	Integer<int> x = Integer<int>("1024");
    Integer<int> y = Integer<int>(67899);
    Integer<int> z = x - y;
    Integer<int> w = Integer<int>("-66875");
    ASSERT_TRUE(z == w);
}

TEST(IntegerTest, subtract_7){
	Integer<int> x = Integer<int>("10249");
    Integer<int> y = Integer<int>(67899);
    Integer<int> z = x - y;
    Integer<int> w = Integer<int>("-57650");
    ASSERT_TRUE(z == w);
}

/* MULTIPLICATION */
TEST(IntegerTest, multiply_1){
	Integer<int> x = Integer<int>("10");
    const Integer<int> y = Integer<int>(20);
    Integer<int> z = x * y;
    Integer<int> w = Integer<int>("200");
    ASSERT_TRUE(z == w);
}

TEST(IntegerTest, multiply_2){
	Integer<int> x = Integer<int>("3987539487279293984755");
    const Integer<int> y = Integer<int>("3867847357757684");
    Integer<int> z = x * y;
    Integer<int> w = Integer<int>("15423194069827647228640349626080107420");
    ASSERT_TRUE(z == w);
}

TEST(IntegerTest, multiply_3){
	Integer<int> x = Integer<int>("0");
    const Integer<int> y = Integer<int>("387563876284632874682764824872643");
    Integer<int> z = x * y;
    Integer<int> w = Integer<int>(0);
    ASSERT_TRUE(z == w);
}

TEST(IntegerTest, multiply_4){
	Integer<int> x = Integer<int>("10");
    const Integer<int> y = Integer<int>(-20);
    Integer<int> z = x * y;
    Integer<int> w = Integer<int>("-200");
    ASSERT_TRUE(z == w);
}

TEST(IntegerTest, multiply_5){
	Integer<int> x = Integer<int>("-10");
    const Integer<int> y = Integer<int>(20);
    Integer<int> z = x * y;
    Integer<int> w = Integer<int>("-200");
    ASSERT_TRUE(z == w);
}

TEST(IntegerTest, multiply_6){
	Integer<int> x = Integer<int>("23");
    const Integer<int> y = Integer<int>(676858);
    Integer<int> z = x * y;
    Integer<int> w = Integer<int>("15567734");
    ASSERT_TRUE(z == w);
}

TEST(IntegerTest, multiply_7){
	Integer<int> x = Integer<int>("46573727");
    const Integer<int> y = Integer<int>(676858);
    Integer<int> z = x * y;
    Integer<int> w = Integer<int>("31523799709766");
    ASSERT_TRUE(z == w);
}

TEST(IntegerTest, multiply_8){
	Integer<int> x = Integer<int>("10000");
    const Integer<int> y = Integer<int>(67899);
    Integer<int> z = x * y;
    Integer<int> w = Integer<int>("678990000");
    ASSERT_TRUE(z == w);
}

TEST(IntegerTest, multiply_9){
	Integer<int> x = Integer<int>("60908");
    const Integer<int> y = Integer<int>(67899);
    Integer<int> z = x * y;
    Integer<int> w = Integer<int>("4135592292");
    ASSERT_TRUE(z == w);
}

TEST(IntegerTest, divide_1){
	Integer<int> x = Integer<int>("20");
    const Integer<int> y = Integer<int>("5");
    Integer<int> z = x / y;
    Integer<int> w = Integer<int>("4");
    ASSERT_TRUE(z == w);
}

TEST(IntegerTest, divide_3){
	Integer<int> x = Integer<int>("5");
    const Integer<int> y = Integer<int>("10");
    Integer<int> z = x / y;
    Integer<int> w = Integer<int>("0");
    ASSERT_TRUE(z == w);
}

TEST(IntegerTest, divide_5){
	Integer<int> x = Integer<int>("-20");
    const Integer<int> y = Integer<int>("20");
    Integer<int> z = x / y;
    Integer<int> w = Integer<int>("-1");
    ASSERT_TRUE(z == w);
}

TEST(IntegerTest, divide_6){
	Integer<int> x = Integer<int>("34");
    const Integer<int> y = Integer<int>("-26");
    Integer<int> z = x / y;
    Integer<int> w = Integer<int>("-1");
    ASSERT_TRUE(z == w);
}

TEST(IntegerTest, modulus_1){
	Integer<int> x = Integer<int>("34");
    const Integer<int> y = Integer<int>("26");
    Integer<int> z = x % y;
    Integer<int> w = Integer<int>("8");
    ASSERT_TRUE(z == w);
}

TEST(IntegerTest, modulus_2){
	Integer<int> x = Integer<int>("40");
    const Integer<int> y = Integer<int>("40");
    Integer<int> z = x % y;
    Integer<int> w = Integer<int>("0");
    ASSERT_TRUE(z == w);
}

TEST(IntegerTest, modulus_3){
	Integer<int> x = Integer<int>("40");
    const Integer<int> y = Integer<int>("40");
    Integer<int> z = x % y;
    Integer<int> w = Integer<int>("0");
    ASSERT_TRUE(z == w);
}

TEST(IntegerTest, modulus_4){
	Integer<int> x = Integer<int>("40");
    const Integer<int> y = Integer<int>("66");
    Integer<int> z = x % y;
    Integer<int> w = Integer<int>("40");
    ASSERT_TRUE(z == w);
}

TEST(IntegerTest, modulus_5){
	Integer<int> x = Integer<int>("40");
    const Integer<int> y = Integer<int>("66");
    Integer<int> z = x % y;
    Integer<int> w = Integer<int>("40");
    ASSERT_TRUE(z == w);
}

