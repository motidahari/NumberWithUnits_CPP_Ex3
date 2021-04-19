/**
  * Number With Units Header
  * Create a Number With Units
  * CPP course, Ariel University
  * Created by: Moti Dahari
  * https://github.com/motidahari
  */


#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
// #include "NumberWithUnits.cpp"


using namespace std;
namespace ariel {
  class NumberWithUnits{
    private:
      string unit;
      double unitAmount; 

    public:
      /**
       * empty constructor 
      */
      NumberWithUnits(){
          this->unit = "km";
          this->unitAmount = 1;
      }

      /**
       * constructor 
       * @param: unitAmount - Number representing unit Amount
       * @param: unit - String representing unit 
      */
      NumberWithUnits(double unitAmount,string unit){
          this->unit = unit;
          this->unitAmount = unitAmount;
      }

      /**
       * destructor - It is destructor used to cleanup the stuff when the object is about to die.
      */
      ~NumberWithUnits(){}

      /**
       * read_units - The function run on file and add the conversions into the map
       * @param: units_file - ifstream with path of the file
       * */ 
      static void read_units(ifstream& units_file);

      /**
       * compareForUnits - function for comparing 2 different object units, the function converts the second object to the first object unit measurement 
       * @param: nu1 - the first object of the unit
       * @param: nu2 - the second object of the unit
       * @return: 1 - if first object bigger then second object, -1 - if first object smaller then second object, Otherwise returns 0 
       * */ 
      friend int compareForUnits(const NumberWithUnits& nu1, const NumberWithUnits& nu2);

      /**
       * Overloading the operator IO 
       * cout << a;
       * cin >> a;
       * */ 
      friend ostream& operator<<(ostream& os , const NumberWithUnits& nu);
      friend istream& operator>>(istream& is , NumberWithUnits& nu);
    
      /**
       * Overloading  the operator -
       * a - b
       * a - 5
       * 5 - a
       * - a 
       * */ 
      friend NumberWithUnits operator-(const NumberWithUnits& nu1 , const NumberWithUnits& nu2);
      friend NumberWithUnits operator-(const NumberWithUnits& nu1 , const double num);
      friend NumberWithUnits operator-(const double num , const NumberWithUnits& nu1);
      friend NumberWithUnits operator-(const NumberWithUnits& nu1);

      /**
       * Overloading the operator +
       * a + b
       * a + 5
       * 5 + a
       * + a 
       * */ 
      friend NumberWithUnits operator+(const NumberWithUnits& nu1 , const NumberWithUnits& nu2);
      friend NumberWithUnits operator+(const NumberWithUnits& nu1 , const double num);
      friend NumberWithUnits operator+(const double num , const NumberWithUnits& nu1);
      friend NumberWithUnits operator+(const NumberWithUnits& nu1);

      /**
       * Overloading the operator *
       * a * b
       * a * 5
       * 5 * a
       * */ 
      friend NumberWithUnits operator*(const NumberWithUnits& nu1 , const NumberWithUnits& nu2);
      friend NumberWithUnits operator*(const NumberWithUnits& nu1 , const double num);
      friend NumberWithUnits operator*(const double num , const NumberWithUnits& nu1);

      /**
       * Overloading the operator /
       * a / b
       * a / 5
       * 5 / a
       * */ 
        friend NumberWithUnits operator/(const NumberWithUnits& nu1 , const NumberWithUnits& nu2);
        friend NumberWithUnits operator/(const NumberWithUnits& nu1 , const double num);
        friend NumberWithUnits operator/(const double num , const NumberWithUnits& nu1);

      /**
       * Overloading the operators with = that not check equals
       * a += b
       * a += 5
       * 5 += a
       * */ 
      friend NumberWithUnits operator+=(NumberWithUnits& nu1 , const NumberWithUnits& nu2);
      friend NumberWithUnits operator+=(NumberWithUnits& nu1 , const double num);
      friend NumberWithUnits operator+=(const double num , NumberWithUnits& nu1);
              
      /**
       * Overloading the operators with = that not check equals
       * a -= b
       * a -= 5
       * 5 -= a
       * */ 
      friend NumberWithUnits operator-=(NumberWithUnits& nu1 , const NumberWithUnits& nu2);
      friend NumberWithUnits operator-=(NumberWithUnits& nu1 , const double num);
      friend NumberWithUnits operator-=(const double num , NumberWithUnits& nu1);
          
      /**
       * Overloading the operators with = that not check equals
       * a *= b
       * a *= 5
       * 5 *= a
       * */ 
      friend NumberWithUnits operator*=(NumberWithUnits& nu1 , const NumberWithUnits& nu2);
      friend NumberWithUnits operator*=(const double num, NumberWithUnits& nu1);
      friend NumberWithUnits operator*=(NumberWithUnits& nu1 , const double num);

      /**
       * Overloading the operators with = that not check equals
       * a /= b
       * a /= 5
       * 5 /= a
       * */ 
      friend NumberWithUnits operator/=(NumberWithUnits& nu1 , const NumberWithUnits& nu2);
      friend NumberWithUnits operator/=(NumberWithUnits& nu1 , const double num);
      friend NumberWithUnits operator/=(const double num, NumberWithUnits& nu1);

      /**
       * Overloading the operators that check equals
       * a == b
       * a == 5
       * 5 == a
       * */ 
      friend bool operator==(const NumberWithUnits& nu1 , const NumberWithUnits& nu2);
      friend bool operator==(const double num, const NumberWithUnits& nu1);
      friend bool operator==(const NumberWithUnits& nu1 , const double num);

      /**
       * Overloading the operators that check equals
       * a <= b
       * a <= 5
       * 5 <= a
       * */ 
      friend bool operator!=(const NumberWithUnits& nu1 , const NumberWithUnits& nu2);
      friend bool operator!=(const NumberWithUnits& nu1 , const double num);
      friend bool operator!=(const double num , const NumberWithUnits& nu1);

      /**
       * Overloading the operators that check equals
       * a > b
       * a > 5
       * 5 > a
       * */ 
      friend bool operator<(const NumberWithUnits& nu1 , const NumberWithUnits& nu2);
      friend bool operator<(const NumberWithUnits& nu1 , const double num);
      friend bool operator<(const double num, const NumberWithUnits& nu1);

      /**
       * Overloading the operators that check equals
       * a > b
       * a > 5
       * 5 > a
       * */ 
      friend bool operator>(const NumberWithUnits& nu1 , const NumberWithUnits& nu2);
      friend bool operator>(const NumberWithUnits& nu1 , const double num);
      friend bool operator>(const double num, const NumberWithUnits& nu1);

      /**
       * Overloading the operators that check equals
       * a >= b
       * a >= 5
       * 5 >= a
       * */ 
      friend bool operator>=(const NumberWithUnits& nu1 , const NumberWithUnits& nu2);
      friend bool operator>=(const NumberWithUnits& nu1 , const double num);
      friend bool operator>=(const double num , const NumberWithUnits& nu1);
      
      /**
       * Overloading the operators that check equals
       * a <= b
       * a <= 5
       * 5 <= a
       * */ 
      friend bool operator<=(const NumberWithUnits& nu1 , const NumberWithUnits& nu2);
      friend bool operator<=(const NumberWithUnits& nu1 , const double num);
      friend bool operator<=(const double num , const NumberWithUnits& nu1);
      
      /**
       * Overloading the operators that check equals
       * a++
       * ++a
       * */ 
      friend NumberWithUnits operator++(NumberWithUnits& nu1, int);
      friend NumberWithUnits operator++(NumberWithUnits& nu1);
        
      /**
       * Overloading the operators that check equals
       * a--
       * --a
       * */ 
      friend NumberWithUnits operator--(NumberWithUnits& nu1, int);
      friend NumberWithUnits operator--(NumberWithUnits& nu1);
  };
}
