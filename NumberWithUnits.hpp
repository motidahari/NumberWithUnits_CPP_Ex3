/**
  * Number With Units
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


using namespace std;
namespace ariel {
    class NumberWithUnits{
        private:
            string unit;
            double unitAmount;  
        public:
            NumberWithUnits(double unitAmount,string unit){
                this->unit = unit;
                this->unitAmount = unitAmount;
            }
            ~NumberWithUnits(){}
            static void read_units(ifstream& units_file);
            
            friend ostream& operator<<(ostream& os , const NumberWithUnits& nu);
            friend istream& operator>>(istream& is , NumberWithUnits& nu);

            // friend NumberWithUnits operator-(const NumberWithUnits& nu1 , const NumberWithUnits& nu2);
            // friend NumberWithUnits operator-(const NumberWithUnits& nu1 , const double num);
            // friend NumberWithUnits operator-(const double num , const NumberWithUnits& nu1);
            // friend NumberWithUnits operator-(const NumberWithUnits& nu1);

            // friend NumberWithUnits operator+(const NumberWithUnits& nu1 , const NumberWithUnits& nu2);
            // friend NumberWithUnits operator+(const NumberWithUnits& nu1 , const double num);
            // friend NumberWithUnits operator+(const double num , const NumberWithUnits& nu1);
            // friend NumberWithUnits operator+(const NumberWithUnits& nu1);






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
   * 
   * a -= b
   * a -= 5
   * 5 -= a
   * 
   * a *= b
   * a *= 5
   * 5 *= a
   * 
   * a /= b
   * a /= 5
   * 5 /= a
   * */ 
    friend NumberWithUnits operator+=(NumberWithUnits& nu1 , const NumberWithUnits& nu2);
    friend NumberWithUnits operator+=(NumberWithUnits& nu1 , const double num);
    friend NumberWithUnits operator+=(const double num , NumberWithUnits& nu1);

    friend NumberWithUnits operator-=(NumberWithUnits& nu1 , const NumberWithUnits& nu2);
    friend NumberWithUnits operator-=(NumberWithUnits& nu1 , const double num);
    friend NumberWithUnits operator-=(const double num , NumberWithUnits& nu1);

    friend NumberWithUnits operator*=(NumberWithUnits& nu1 , const NumberWithUnits& nu2);
    friend NumberWithUnits operator*=(const double num, NumberWithUnits& nu1);
    friend NumberWithUnits operator*=(NumberWithUnits& nu1 , const double num);

    friend NumberWithUnits operator/=(NumberWithUnits& nu1 , const NumberWithUnits& nu2);
    friend NumberWithUnits operator/=(NumberWithUnits& nu1 , const double num);
    friend NumberWithUnits operator/=(const double num, NumberWithUnits& nu1);


/**
   * Overloading the operators that check equals
   * a >= b
   * a >= 5
   * 5 >= a
   * 
   * a <= b
   * a <= 5
   * 5 <= a
   * 
   * a == b
   * a == 5
   * 5 == a
   * 
   * a < b
   * a < 5
   * 5 < a
   * 
   * a > b
   * a > 5
   * 5 > a
   * */ 
    friend NumberWithUnits operator>=(NumberWithUnits& nu1 , const NumberWithUnits& nu2);
    friend NumberWithUnits operator>=(NumberWithUnits& nu1 , const double num);
    friend NumberWithUnits operator>=(const double num , NumberWithUnits& nu1);

    friend NumberWithUnits operator<=(NumberWithUnits& nu1 , const NumberWithUnits& nu2);
    friend NumberWithUnits operator<=(NumberWithUnits& nu1 , const double num);
    friend NumberWithUnits operator<=(const double num , NumberWithUnits& nu1);

    friend NumberWithUnits operator==(NumberWithUnits& nu1 , const NumberWithUnits& nu2);
    friend NumberWithUnits operator==(const double num, NumberWithUnits& nu1);
    friend NumberWithUnits operator==(NumberWithUnits& nu1 , const double num);
    
    friend NumberWithUnits operator<(NumberWithUnits& nu1 , const NumberWithUnits& nu2);
    friend NumberWithUnits operator<(NumberWithUnits& nu1 , const double num);
    friend NumberWithUnits operator<(const double num, NumberWithUnits& nu1);

    friend NumberWithUnits operator>(NumberWithUnits& nu1 , const NumberWithUnits& nu2);
    friend NumberWithUnits operator>(NumberWithUnits& nu1 , const double num);
    friend NumberWithUnits operator>(const double num, NumberWithUnits& nu1);




    };
}
