/**
  * Number With Units Tests
  * Create a Number With Units
  * CPP course, Ariel University
  * Created by: Moti Dahari
  * https://github.com/motidahari
  */

#include <string>
#include "doctest.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "NumberWithUnits.hpp"
#include <ctime>
#include <stdexcept>

using namespace ariel;
using namespace std;


ifstream units_file{"units.txt"};
NumberWithUnits a{2, "km"};
NumberWithUnits b{500, "m"};
NumberWithUnits c;
NumberWithUnits d{500, "ILS"};
NumberWithUnits e{500, "sec"};


/**
 * Test for the operator -
 */
TEST_CASE("test for the operator -"){
    NumberWithUnits::read_units(units_file);

    c = a - b;
    CHECK_EQ(c , NumberWithUnits{1.5, "km"});
    double result = 1.5; 
    for(int i = 0; i < 100; i++){
      double r = (rand()+1) * 100;
      result = result - r;
      CHECK_EQ((c = c - r) , NumberWithUnits{result, "km"});
       result -= r;
      CHECK_EQ((c = c - r) , NumberWithUnits{result, "km"});
      result = r - (-result) ;
      CHECK_EQ((c = r-(-c)) , NumberWithUnits{result, "km"});
      result *= -1;
      CHECK_EQ((c = -c) , NumberWithUnits{result, "km"});
    }
}

/**
 * Test for the operator +
 */
TEST_CASE("test for the operator +"){
    NumberWithUnits::read_units(units_file);

    c = a - b;
    CHECK_EQ(c , NumberWithUnits{1.5, "km"});
    double result = 1.5; 
    for(int i = 0; i < 100; i++){
      double r = (rand()+1) * 100;
      result = result + r;
      CHECK_EQ((c = c + r) , NumberWithUnits{result, "km"});
       result += r;
      CHECK_EQ((c = c + r) , NumberWithUnits{result, "km"});
      result = r + (-result) ;
      CHECK_EQ((c = r+(-c)) , NumberWithUnits{result, "km"});
      result += -1;
      CHECK_EQ((c += -1) , NumberWithUnits{result, "km"});
    }
}

/**
 * Test for the operator *
 */
TEST_CASE("test for the operator *"){
    NumberWithUnits::read_units(units_file);

    c = a * b;
    CHECK_EQ(c , NumberWithUnits{1, "km"});
    double result = 1; 
    for(int i = 0; i < 100; i++){
      double r = (rand()+1) * 100;
      result = result * r;
      CHECK_EQ((c = c * r) , NumberWithUnits{result, "km"});
       result *= r;
      CHECK_EQ((c = c * r) , NumberWithUnits{result, "km"});
      result = r * (-result) ;
      CHECK_EQ((c = r*(-c)) , NumberWithUnits{result, "km"});
      result *= -1;
      CHECK_EQ((c *= -1) , NumberWithUnits{result, "km"});
    }
}

/**
 * Test for the operator /
 */
TEST_CASE("test for the operator /"){
    NumberWithUnits::read_units(units_file);

    c = a / b;
    CHECK_EQ(c , NumberWithUnits{4, "km"});
    double result = 4; 
    for(int i = 0; i < 100; i++){
      double r = (rand()+1) * 100;
      result = result / r;
      CHECK_EQ((c = c / r) , NumberWithUnits{result, "km"});
       result /= r;
      CHECK_EQ((c = c / r) , NumberWithUnits{result, "km"});
      result = r / (-result) ;
      CHECK_EQ((c = r/(-c)) , NumberWithUnits{result, "km"});
      result /= -1;
      CHECK_EQ((c /= -1) , NumberWithUnits{result, "km"});
    }
}

/**
 * Test for the operator +=
 */
TEST_CASE("test for the operator +="){
    NumberWithUnits::read_units(units_file);
    c = a - b;
    CHECK_EQ(c , NumberWithUnits{1.5, "km"});
    double result = 1.5; 
    for(int i = 0; i < 100; i++){
      double r = (rand()+1) * 100;
      result += r;
      CHECK_EQ((r += c) , NumberWithUnits{result, "km"});
      result += 0.5;
      CHECK_EQ((c += b) , NumberWithUnits{result, "km"});
      result += 0.5;
      CHECK_EQ((0.5 += c) , NumberWithUnits{result, "km"});
    }
}

/**
 * Test for the operator -=
 */
TEST_CASE("test for the operator -="){
    NumberWithUnits::read_units(units_file);
    c = a - b;
    CHECK_EQ(c , NumberWithUnits{1.5, "km"});
    double result = 1.5; 
    for(int i = 0; i < 100; i++){
      double r = (rand()+1) * 100;
      result = -( result - r);
      CHECK_EQ((r -= c) , NumberWithUnits{result, "km"});
      result -= 0.5;
      CHECK_EQ((c -= b) , NumberWithUnits{result, "km"});
      result = -( result - 0.5);
      CHECK_EQ((0.5 -= c) , NumberWithUnits{result, "km"});
    }
}

/**
 * Test for the operator *=
 */
TEST_CASE("test for the operator *="){
    NumberWithUnits::read_units(units_file);
    c = a - b;
    CHECK_EQ(c , NumberWithUnits{1.5, "km"});
    double result = 1.5; 
    for(int i = 0; i < 100; i++){
      double r = (rand()+1) * 100;
      result *= r;
      CHECK_EQ((r *= c) , NumberWithUnits{result, "km"});
      result *= 0.5;
      CHECK_EQ((c *= b) , NumberWithUnits{result, "km"});
      result *= 0.5;
      CHECK_EQ((0.5 *= c) , NumberWithUnits{result, "km"});
    }
}

/**
 * Test for the operator /=
 */
TEST_CASE("test for the operator /="){
    NumberWithUnits::read_units(units_file);
    c = a - b;
    CHECK_EQ(c , NumberWithUnits{1.5, "km"});
    double result = 1.5; 
    for(int i = 0; i < 100; i++){
      double r = (rand()+1) * 100;
      result /= r;
      CHECK_EQ((r /= c) , NumberWithUnits{result, "km"});
      result /= 0.5;
      CHECK_EQ((c /= b) , NumberWithUnits{result, "km"});
      result /= 0.5;
      CHECK_EQ((0.5 /= c) , NumberWithUnits{result, "km"});
    }
}

/**
 * Test for the operator ==
 */
TEST_CASE("test for the operator =="){
    NumberWithUnits::read_units(units_file);
    CHECK((a == b) == 0);
    CHECK((b == a) == 0);
    CHECK((b == b) == 1);
    CHECK((a == a) == 1);
    CHECK((a == 2) == 1);
    CHECK((2 == a) == 1);
}

/**
 * Test for the operator !=
 */
TEST_CASE("test for the operator !="){
    NumberWithUnits::read_units(units_file);
    CHECK((a != b) == 1);
    CHECK((b != a) == 1);
    CHECK((b != b) == 0);
    CHECK((a != a) == 0);
    CHECK((a != 2) == 0);
    CHECK((2 != a) == 0);
}

/**
 * Test for the operator <
 */
TEST_CASE("test for the operator <"){
    NumberWithUnits::read_units(units_file);
    CHECK((a < b) == 0);
    CHECK((b < a) == 1);
    CHECK((b < b) == 0);
    CHECK((a < a) == 0);
    CHECK((a < 2) == 0);
    CHECK((2 < a) == 0);
    CHECK((1 < a) == 1);
    CHECK((a < 4) == 1);   
}

/**
 * Test for the operator >
 */
TEST_CASE("test for the operator >"){
    NumberWithUnits::read_units(units_file);
    CHECK((a > b) == 1);
    CHECK((b > a) == 0);
    CHECK((b > b) == 0);
    CHECK((a > a) == 0);
    CHECK((a > 2) == 0);
    CHECK((2 > a) == 0);
    CHECK((1 > a) == 0);
    CHECK((a > 4) == 0);
}

/**
 * Test for the operator >=
 */
TEST_CASE("test for the operator >="){
    NumberWithUnits::read_units(units_file);
    CHECK((a >= b) == 1);
    CHECK((b >= a) == 0);
    CHECK((b >= b) == 1);
    CHECK((a >= a) == 1);
    CHECK((a >= 2) == 1);
    CHECK((2 >= a) == 1);
    CHECK((1 >= a) == 0);
    CHECK((a >= 4) == 0);
}

/**
 * Test for the operator <=
 */
TEST_CASE("test for the operator <="){
    NumberWithUnits::read_units(units_file);
    CHECK((a <= b) == 0);
    CHECK((b <= a) == 1);
    CHECK((b <= b) == 1);
    CHECK((a <= a) == 1);
    CHECK((a <= 2) == 1);
    CHECK((2 <= a) == 1);
    CHECK((1 <= a) == 1);
    CHECK((a <= 4) == 1);  
}

/**
 * Test for the operator ++
 */
TEST_CASE("test for the operator ++"){
    NumberWithUnits::read_units(units_file);
    CHECK_EQ( a++ , NumberWithUnits{2, "km"});
    CHECK_EQ( a , NumberWithUnits{3, "km"});
    CHECK_EQ( ++a , NumberWithUnits{4, "km"});
    CHECK_EQ( a , NumberWithUnits{4, "km"});
}

/**
 * Test for the operator --
 */
TEST_CASE("test for the operator --"){
    NumberWithUnits::read_units(units_file);
    CHECK_EQ( a-- , NumberWithUnits{4, "km"});
    CHECK_EQ( a , NumberWithUnits{3, "km"});
    CHECK_EQ( --a , NumberWithUnits{2, "km"});
    CHECK_EQ( a , NumberWithUnits{2, "km"});
}


/**
 * Test for the input/output
 */
TEST_CASE("Test for the input/output"){
  NumberWithUnits::read_units(units_file);

  //cin
  istringstream input1 {"7000 [ kg ]"};
  istringstream input2 {"10000 [ kg ]"};
  input1 >> a;
  input2 >> b;
  CHECK_EQ(a , NumberWithUnits{7000, "kg"});
  CHECK_EQ(b , NumberWithUnits{10000, "kg"});
  CHECK_EQ(a += b , NumberWithUnits{17000, "kg"});
  
  //cout
  ostringstream d;
  ostringstream e;
  d << a;
  e << b;
  CHECK_EQ(d.str() , "17000[kg]");
  CHECK_EQ(e.str() , "10000[kg]");
}