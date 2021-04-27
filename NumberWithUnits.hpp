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
     NumberWithUnits(const double& ,const string& );

      /**
       * destructor - It is destructor used to cleanup the stuff when the object is about to die.
      */
      ~NumberWithUnits(){}

      /**
       * read_units - The function run on file and add the conversions into the map
       * @param: units_file - ifstream with path of the file
       * */ 
      static void read_units(ifstream&);

      /**
       * compareForUnits - function for comparing 2 different object units, the function converts the second object to the first object unit measurement 
       * @param:  - the first object of the unit
       * @param: nu2 - the second object of the unit
       * @return: 1 - if first object bigger then second object, -1 - if first object smaller then second object, Otherwise returns 0 
       * */ 
      friend int compareForUnits(const NumberWithUnits& ,const NumberWithUnits&);

      /**
       * Overloading the operator IO 
       * cout << a;
       * cin >> a;
       * */ 
      friend ostream& operator<<(ostream&  ,const NumberWithUnits&);
      friend istream& operator>>(istream&  , NumberWithUnits&);
    
      /**
       * Overloading  the operator -
       * a - b
       * a - 5
       * 5 - a
       * - a 
       * */ 
      friend NumberWithUnits operator-(const NumberWithUnits& ,const NumberWithUnits&);
      friend NumberWithUnits operator-(const NumberWithUnits& , const double);
      friend NumberWithUnits operator-(const double  ,const NumberWithUnits&);
      friend NumberWithUnits operator-(const NumberWithUnits&);

      /**
       * Overloading the operator +
       * a + b
       * a + 5
       * 5 + a
       * + a 
       * */ 
      friend NumberWithUnits operator+(const NumberWithUnits& ,const NumberWithUnits&);
      friend NumberWithUnits operator+(const NumberWithUnits& , const double);
      friend NumberWithUnits operator+(const double ,const NumberWithUnits&);
      friend NumberWithUnits operator+(const NumberWithUnits&);

      /**
       * Overloading the operator *
       * a * b
       * a * 5
       * 5 * a
       * */ 
      friend NumberWithUnits operator*(const NumberWithUnits& ,const NumberWithUnits&);
      friend NumberWithUnits operator*(const NumberWithUnits& , const double);
      friend NumberWithUnits operator*(const double ,const NumberWithUnits&);

      /**
       * Overloading the operator /
       * a / b
       * a / 5
       * 5 / a
       * */ 
        friend NumberWithUnits operator/(const NumberWithUnits& ,const NumberWithUnits&);
        friend NumberWithUnits operator/(const NumberWithUnits& , const double);
        friend NumberWithUnits operator/(const double ,const NumberWithUnits&);

      /**
       * Overloading the operators with = that not check equals
       * a += b
       * a += 5
       * 5 += a
       * */ 


      NumberWithUnits &operator+=(const NumberWithUnits &num);
      NumberWithUnits &operator+=(const double &num);
      friend NumberWithUnits operator+=(const double , NumberWithUnits&);
              
      /**
       * Overloading the operators with = that not check equals
       * a -= b
       * a -= 5
       * 5 -= a
       * */ 
      // friend NumberWithUnits operator-=(NumberWithUnits&  ,const NumberWithUnits&);
      // friend NumberWithUnits operator-=(NumberWithUnits&  , const double);
      friend NumberWithUnits operator-=(const double , NumberWithUnits&);
      NumberWithUnits &operator-=(const NumberWithUnits &num);
      NumberWithUnits &operator-=(const double &num);
      /**
       * Overloading the operators with = that not check equals
       * a *= b
       * a *= 5
       * 5 *= a
       * */ 
      NumberWithUnits &operator*=(const NumberWithUnits &num);
      NumberWithUnits &operator*=(const double &num);
      // friend NumberWithUnits operator*=(NumberWithUnits&  ,const NumberWithUnits&);
      friend NumberWithUnits operator*=(const double, NumberWithUnits&);
      // friend NumberWithUnits operator*=(NumberWithUnits&  , const double);

      /**
       * Overloading the operators with = that not check equals
       * a /= b
       * a /= 5
       * 5 /= a
       * */ 
      NumberWithUnits &operator/=(const NumberWithUnits &num);
      NumberWithUnits &operator/=(const double &num);
      // friend NumberWithUnits operator/=(NumberWithUnits&  ,const NumberWithUnits&);
      // friend NumberWithUnits operator/=(NumberWithUnits&  , const double);
      friend NumberWithUnits operator/=(const double, NumberWithUnits&);

      /**
       * Overloading the operators that check equals
       * a == b
       * a == 5
       * 5 == a
       * */ 
      friend bool operator==(const NumberWithUnits& ,const NumberWithUnits&);
      friend bool operator==(const double,const NumberWithUnits&);
      friend bool operator==(const NumberWithUnits& , const double);

      /**
       * Overloading the operators that check equals
       * a <= b
       * a <= 5
       * 5 <= a
       * */ 
      friend bool operator!=(const NumberWithUnits& ,const NumberWithUnits&);
      friend bool operator!=(const NumberWithUnits& , const double);
      friend bool operator!=(const double ,const NumberWithUnits&);

      /**
       * Overloading the operators that check equals
       * a > b
       * a > 5
       * 5 > a
       * */ 
      friend bool operator<(const NumberWithUnits& ,const NumberWithUnits&);
      friend bool operator<(const NumberWithUnits& , const double);
      friend bool operator<(const double,const NumberWithUnits&);

      /**
       * Overloading the operators that check equals
       * a > b
       * a > 5
       * 5 > a
       * */ 
      friend bool operator>(const NumberWithUnits& ,const NumberWithUnits&);
      friend bool operator>(const NumberWithUnits& , const double);
      friend bool operator>(const double,const NumberWithUnits&);

      /**
       * Overloading the operators that check equals
       * a >= b
       * a >= 5
       * 5 >= a
       * */ 
      friend bool operator>=(const NumberWithUnits& ,const NumberWithUnits&);
      friend bool operator>=(const NumberWithUnits& , const double);
      friend bool operator>=(const double ,const NumberWithUnits&);
      
      /**
       * Overloading the operators that check equals
       * a <= b
       * a <= 5
       * 5 <= a
       * */ 
      friend bool operator<=(const NumberWithUnits& ,const NumberWithUnits&);
      friend bool operator<=(const NumberWithUnits& , const double);
      friend bool operator<=(const double ,const NumberWithUnits&);
      
      /**
       * Overloading the operators that check equals
       * a++
       * ++a
       * */ 
      NumberWithUnits& operator++();
      NumberWithUnits operator++(int);
        
      /**
       * Overloading the operators that check equals
       * a--
       * --a
       * */ 
      NumberWithUnits& operator--();
      NumberWithUnits operator--(int);
      
      
  };
}
