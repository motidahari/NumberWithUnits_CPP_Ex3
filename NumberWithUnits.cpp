/**
  * Number With Units
  * Create a Number With Units
  * CPP course, Ariel University
  * Created by: Moti Dahari
  * https://github.com/motidahari
  */


/*
טוב ראיתי עכשיו את התרגול של חירות שוב לגבי הfriend והיא אמרה שם ככה:
אם זה פונקציות שלא משנות את האובייקט/ים - זה נתון לבחירה שלנו אם לעשות friend או לא.
אם זה פעולות של השמה - זה חייב להיות מתודה רגילה ולא friend
פונקציות של קלט ופלט - חייבות להיות friend
אם מישהו רוצה היא מדברת על זה בתרדול של רביעי ב9 בדקה 17 בערך
*/
#include <map>
#include <string>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <exception>
#include <fstream>
#include "NumberWithUnits.hpp"

using namespace std;
// string readFileIntoString2(const ifstream& units_file) {
//     auto ss = ostringstream{};
//     if (!units_file.is_open()) {
//         cerr << "Could not open the file - '" << "'" << endl;
//         exit(EXIT_FAILURE);
//     }
//     ss << units_file.rdbuf();
//     return ss.str();
// }

namespace ariel {
    static map<string, map<string, double>> mat;

    void prinMap(){
        for (const auto &i : mat) {
          for (const auto &j : mat[i.first]) {
            std::cout <<"mat["<< i.first << "][" << j.first << "] => " << j.second << endl;
          }
        }
    }
    void prinInMap(const string nameUnit){
          for (const auto &j : mat[nameUnit]) {
            std::cout <<"mat["<< nameUnit <<"][" << j.first << "] => " << j.second << endl;
        }
    }    

    double convertUnit1ToUnit2(const string unit1, const string unit2, const double val){
      if(unit1 == unit2) return val;
      try{
        return mat.at(unit1).at(unit2) * val;
      }catch(const std::exception& e){
        throw invalid_argument{"Error: Conversion Error - Unable to convert from "+ unit1 +" to "+ unit2};
      }
    }
    void addMoreUnits(const string nameUnit1, const string nameUnit2){
      for (const auto &x : mat[nameUnit1]) {
        if(x.first != nameUnit2){
          // cout << "[" << x.first << "] -> " << x.second << endl;
          // cout << "mat[" << nameUnit2 << "]" << "[" << nameUnit1 << "]" << " -> " << mat[nameUnit1][nameUnit2] << endl;
          double val = x.second * mat[nameUnit2][nameUnit1];
          mat[x.first][nameUnit2] = 1/val;
          mat[nameUnit2][x.first] = val;
        }
      }
    }  
    static void read_units(ifstream& units_file){
      string nameUnit1,nameUnit2,operEqual;
      double num1, num2;
      while (units_file >> num1 >> nameUnit1 >> operEqual >> num2 >> nameUnit2){
        if(num1 == 1 && operEqual == "=" && num2 > 0){
          // cout << num1 << " " << nameUnit1 << " " << operEqual << " " << num2 << " " << nameUnit2 << endl;
          mat[nameUnit2][nameUnit1] = 1/num2;
          mat[nameUnit1][nameUnit2] = num2;
          addMoreUnits(nameUnit1,nameUnit2);
          addMoreUnits(nameUnit2,nameUnit1);
        }else{
          throw invalid_argument{"Error: Unit conversion file is invalid\n"};
        }
      }
      // cout << "\n";
      prinMap(); 
    }
    ostream& operator<< (ostream& os , const NumberWithUnits& nu){
        os << nu.unitAmount << "[" << nu.unit << "]";
        return os;
    }
    istream& operator>>(istream& is , NumberWithUnits& nu){
      string str;
      is >> nu.unitAmount >> str >> nu.unit;
      return is;
    }
    
  /**
   * Overloading  the operator -
   * a - b
   * a - 5
   * 5 - a
   * - a 
   * */ 
    NumberWithUnits operator-(const NumberWithUnits& nu1 , const NumberWithUnits& nu2){
      return NumberWithUnits(nu1.unitAmount - convertUnit1ToUnit2(nu2.unit,nu1.unit, nu2.unitAmount),nu1.unit);
    }
    NumberWithUnits operator-(const NumberWithUnits& nu1 , const double num){
      return NumberWithUnits(nu1.unitAmount - num, nu1.unit);
    }
    NumberWithUnits operator-(const double num , const NumberWithUnits& nu1){
      return NumberWithUnits(num - nu1.unitAmount, nu1.unit);
    }
    NumberWithUnits operator-(const NumberWithUnits& nu1){
      return NumberWithUnits(-nu1.unitAmount, nu1.unit);
    }
  /**
   * Overloading the operator +
   * a + b
   * a + 5
   * 5 + a
   * + a 
   * */ 
    NumberWithUnits operator+(const NumberWithUnits& nu1 , const NumberWithUnits& nu2){
      return NumberWithUnits(nu1.unitAmount + convertUnit1ToUnit2(nu2.unit,nu1.unit, nu2.unitAmount),nu1.unit);
    }
    NumberWithUnits operator+(const NumberWithUnits& nu1 , const double num){
      return NumberWithUnits(nu1.unitAmount + num, nu1.unit);
    }
    NumberWithUnits operator+(const double num , const NumberWithUnits& nu1){
      return NumberWithUnits(num + nu1.unitAmount, nu1.unit);
    }
    NumberWithUnits operator+(const NumberWithUnits& nu1){
      return NumberWithUnits(+nu1.unitAmount, nu1.unit);
    }


  /**
   * Overloading the operator *
   * a * b
   * a * 5
   * 5 * a
   * */ 

    NumberWithUnits operator*(const NumberWithUnits& nu1 , const NumberWithUnits& nu2){
      return NumberWithUnits(nu1.unitAmount * convertUnit1ToUnit2(nu2.unit,nu1.unit, nu2.unitAmount),nu1.unit);
    }
    NumberWithUnits operator*(const NumberWithUnits& nu1 , const double num){
      return NumberWithUnits(nu1.unitAmount * num, nu1.unit);
    }
    NumberWithUnits operator*(const double num , const NumberWithUnits& nu1){
      return NumberWithUnits(num * nu1.unitAmount, nu1.unit);
    }


  /**
   * Overloading the operator /
   * a / b
   * a / 5
   * 5 / a
   * */ 

    NumberWithUnits operator/(const NumberWithUnits& nu1 , const NumberWithUnits& nu2){
      return NumberWithUnits(nu1.unitAmount / convertUnit1ToUnit2(nu2.unit,nu1.unit, nu2.unitAmount),nu1.unit);
    }
    NumberWithUnits operator/(const NumberWithUnits& nu1 , const double num){
      return NumberWithUnits(nu1.unitAmount / num, nu1.unit);
    }
    NumberWithUnits operator/(const double num , const NumberWithUnits& nu1){
      return NumberWithUnits(num / nu1.unitAmount, nu1.unit);
    }

  /**
   * Overloading the operators with = that not check equals
   * a += b
   * a += 5
   * 5 += a
   * a -= b
   * a -= 5
   * 5 -= a
   * a *= b
   * a *= 5
   * 5 *= a
   * a /= b
   * a /= 5
   * 5 /= a
   * */ 


  

    NumberWithUnits operator+=(NumberWithUnits& nu1 , const NumberWithUnits& nu2){
      nu1.unitAmount +=  convertUnit1ToUnit2(nu2.unit,nu1.unit, nu2.unitAmount);
      return nu1;
    }
    NumberWithUnits operator+=(NumberWithUnits& nu1 , const double num){
      nu1.unitAmount += num;
      return nu1;
    }
    NumberWithUnits operator+=(const double num , NumberWithUnits& nu1){
      nu1.unitAmount -= num;
      return nu1;
    }




    NumberWithUnits operator-=(NumberWithUnits& nu1 , const NumberWithUnits& nu2){
      nu1.unitAmount -= convertUnit1ToUnit2(nu2.unit,nu1.unit, nu2.unitAmount);
      return nu1;
    }
    NumberWithUnits operator-=(NumberWithUnits& nu1 , const double num){
      nu1.unitAmount -= num;
      return nu1;
    }
    NumberWithUnits operator-=(const double num , NumberWithUnits& nu1){
      nu1.unitAmount -= num;
      return nu1;
    }




    NumberWithUnits operator*=(NumberWithUnits& nu1 , const NumberWithUnits& nu2){
      nu1.unitAmount *= convertUnit1ToUnit2(nu2.unit,nu1.unit, nu2.unitAmount);
      return nu1;
    }
    NumberWithUnits operator*=(NumberWithUnits& nu1 , const double num){
      nu1.unitAmount *= num;
      return nu1;
    }
    NumberWithUnits operator*=(const double num , NumberWithUnits& nu1){
      nu1.unitAmount *= num;
      return nu1;
    }




    NumberWithUnits operator/=(NumberWithUnits& nu1 , const NumberWithUnits& nu2){
      nu1.unitAmount /= convertUnit1ToUnit2(nu2.unit,nu1.unit, nu2.unitAmount);
      return nu1;
    }
    NumberWithUnits operator/=(NumberWithUnits& nu1 , const double num){
      nu1.unitAmount /= num;
      return nu1;
    }
    NumberWithUnits operator/=(const double num , NumberWithUnits& nu1){
      nu1.unitAmount /= num;
      return nu1;
    }
 
};

int main(){
  ifstream units_file{"units.txt"};
  ariel::read_units(units_file);

  ariel::NumberWithUnits a{2, "km"};
  ariel::NumberWithUnits b{500, "m"};
  cout << "a = " << a << "\n";
  cout << "b = " << b << "\n\n";
/*
  check to the operator -

  The output should be{
    1.5[km]
    -0.5[km]
    2.5[km]
    -2.5[km]
  }  
  */
  ariel::NumberWithUnits c = a - b;
  cout << "check to the operator -" << "\n";
  cout << c << "\n";
  c = c-2;
  cout << c << "\n";
  c = 2 - c;
  cout << c << "\n";
  cout << -c << "\n\n";
  
/*
  check to the operator +

  The output should be{
    2.5[km]
    4.5[km]
    6.5[km]
    6.5[km] 
  }  
  */
  cout << "check to the operator +" << "\n";
  c = a + b;
  cout << c << "\n";
  c = c + 2;
  cout << c << "\n";
  c = 2 + c;
  cout << c << "\n";
  cout << + c << "\n\n";

/*
  check to the operator *

  The output should be{
    1[km]
    2[km]
    4[km]
  }  
  */
  cout << "check to the operator *" << "\n";
  c = a * b;
  cout << c << "\n";
  c = c * 2;
  cout << c << "\n";
  c = 2 * c;
  cout << c << "\n\n";

/*
  check to the operator /

  The output should be{
    4[km]
    2[km]
    1[km]
  }  
  */
  cout << "check to the operator /" << "\n";
  c = a / b;
  cout << c << "\n";
  c = c / 2;
  cout << c << "\n";
  c = 2 / c;
  cout << c << "\n\n";

/*
  check to the operator +=

  The output should be{
    2[km]
    4[km]
    6[km]
    4[km]
  }
  */
  cout << "check to the operator +=" << "\n";
  c = a ;
  cout << c << "\n";
  c += c;
  cout << c << "\n";
  c += 2;
  cout << c << "\n";
  2 += c;
  cout << c << "\n\n";

/*
  check to the operator -=

  The output should be{
    2[km]
    0[km]
    -2[km]
    -4[km]
  }
  */
  cout << "check to the operator -=" << "\n";
  c = a ;
  cout << c << "\n";
  c -= c;
  cout << c << "\n";
  c -= 2;
  cout << c << "\n";
  2 -= c;
  cout << c << "\n\n";

/*
  check to the operator *=

  The output should be{
    2[km]
    4[km]
    8[km]
    16[km]
  }
 */
  cout << "check to the operator *=" << "\n";
  c = a ;
  cout << c << "\n";
  c *= c;
  cout << c << "\n";
  c *= 2;
  cout << c << "\n";
  2 *= c;
  cout << c << "\n\n";

/*
  check to the operator /=

  The output should be{
    2[km]
    1[km]
    0.5[km]
    0.25[km]
  }
*/
  cout << "check to the operator /=" << "\n";
  c = a ;
  cout << c << "\n";
  c /= c;
  cout << c << "\n";
  c /= 2;
  cout << c << "\n";
  2 /= c;
  cout << c << "\n\n";


  //check cout
  /*
  cout << a << endl;
  cout << b << endl;
  cout << (ariel::mat["km"]["cm"] * 5) << endl;
  cout << (ariel::mat["cm"]["km"] ) * 500000 << endl;
  */


  //check convert
   /*
  cout << ariel::convertUnit1ToUnit2("km", "cm", 5) << "\n";
  cout << ariel::convertUnit1ToUnit2("km", "m", 5) << "\n";
  cout << ariel::convertUnit1ToUnit2("m", "cm", 1) << "\n";
  */

  return 0;
}

/*
clear && clang-9 -o run NumberWithUnits.cpp -lstdc++ && ./run
*/