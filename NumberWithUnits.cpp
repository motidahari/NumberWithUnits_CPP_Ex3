/**
  * Number With Units implementaion
  * Create a Number With Units
  * CPP course, Ariel University
  * Created by: Moti Dahari
  * https://github.com/motidahari
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
constexpr double BOAZ = -0.000000001;
constexpr double BEM_MOSHE = 0.0001;


/**
 * readFileIntoString - A function that reads from a text file and returns a string that represents what is written in the file
 * @param: units_file - ifstream with path of the file
 * @return: str - A string of that represents what is written in the file
*/
string readFileIntoString(const ifstream& units_file) {
    auto ss = ostringstream{};
    if (!units_file.is_open()) {
        cerr << "Could not open the file - '" << "'" << endl;
        exit(EXIT_FAILURE);
    }
    ss << units_file.rdbuf();
    return ss.str();
}


namespace ariel {
    map<string, map<string, double>> mat;
    map<string, int> units;

    /**
     * constructor 
     * @param: unitAmount - Number representing unit Amount
     * @param: unit - String representing unit 
    */
    NumberWithUnits::NumberWithUnits(const double& unitAmount,const string& unit){
      try{
        if(units.at(unit) == 1){
          this->unit = unit;
          this->unitAmount = unitAmount;
        }
      }catch(const std::exception& e){
        throw invalid_argument{"Error creating object, ["+unit+"] conversion unit does not exist"};
      }
    }
    /**
     * printMap - A function that prints all the conversions that exist within the map
    */
    void printMap(){
      cout << "\n";
      for (const auto &i : mat) {
        for (const auto &j : mat[i.first]) {
          std::cout <<"mat["<< i.first << "][" << j.first << "] => " << j.second << endl;
        }
      }
    }

    /**
     * printInMap - A function that prints all the conversions that exist within the map with the specfied measure unit
     * @param: nameUnit - specfied measure unit in the map
    */
    void printInMap(const string& nameUnit){
      cout << "\n";
      const string& str = nameUnit;
      for (const auto &j : mat[str]) {
        std::cout <<"mat["<< str <<"][" << j.first << "] => " << j.second << endl;
      }
    }    

    /**
     * convertUnit1ToUnit2 - A function that converts from unit 1 to unit 2, if it is not possible to convert to unit we will return a throw
     * @param: unit1 - A string that represents our unit 1
     * @param: unit2 - A string that represents our unit 2
     * @param: val - The value assigned to convert to another unit
     * @return: double - A number representing the converted measure
    */
    double convertUnit1ToUnit2(const string& unit1, const string& unit2, const double val){
      if(unit1 == unit2) {return val;}
      if(mat.count(unit1) > 0 && mat.at(unit1).count(unit2) > 0){
        return mat.at(unit1).at(unit2) * val;
      }
      throw invalid_argument{"Units do not match - ["+unit1+"] cannot be converted to ["+unit2+"]"};
    }

    /**
     * compareForUnits - function for comparing 2 different object units, the function converts the second object to the first object unit measurement 
     * @param: nu1 - the first object of the unit
     * @param: nu2 - the second object of the unit
     * @return: 1 - if first object bigger then second object, -1 - if first object smaller then second object, Otherwise returns 0 
     * */
    int compareForUnits(const NumberWithUnits& nu1, const NumberWithUnits& nu2){
      double x1 = abs((nu1.unitAmount + BEM_MOSHE) - (convertUnit1ToUnit2(nu2.unit,nu1.unit, nu2.unitAmount)+ BEM_MOSHE));
      if(x1 <  BEM_MOSHE) {return 0;}
      double x2 = (nu1.unitAmount+ BEM_MOSHE) - (convertUnit1ToUnit2(nu2.unit,nu1.unit, nu2.unitAmount)+ BEM_MOSHE);
      return (x2 >  BEM_MOSHE) ? 1 : (-x2 >  BEM_MOSHE)? -1 : 0;
    }


    /**
     * addMoreUnits - A function that adds measures of transcendence, 
     * the function run on the map at unit1 location and adds the measure of the grandchild with the grandfather.
     * For example:
     *  If in the file we received it says:
                  1 km = 1000 m
                  1 m = 100 cm
                  then the convertion: km -> cm || cm -> km is added.

     * @param: nameUnit1 - the first object of the unit
     * @param: nameUnit2 - the second object of the unit
     * @return: 1 - if first object bigger then second object, -1 - if first object smaller then second object, Otherwise returns 0 
     * */
    void addMoreUnits(const string& nameUnit1, const string& nameUnit2){
      for (const auto &x : mat[nameUnit1]) {
        if(x.first != nameUnit2){
          double val = x.second * mat[nameUnit2][nameUnit1];
          mat[x.first][nameUnit2] = 1/val;
          mat[nameUnit2][x.first] = val;
        }
      }
    }  

    /**
     * runByMapAndAddMoreUnits - run by the units and add it to map 
     * */
    void runByMapAndAddMoreUnits(){
      int size = units.size();
      for (const auto &unit : units) {
        for (const auto &x : mat[unit.first]) {
          addMoreUnits(unit.first,x.first);
          addMoreUnits(x.first,unit.first);
        }
      }
    }  
    /**
     * read_units - The function run on file and add the conversions into the map
     * @param: units_file - ifstream with path of the file
     * */   
    void NumberWithUnits::read_units(ifstream& units_file){
      string nameUnit1;
      string nameUnit2;
      string operEqual;
      double num1 = BOAZ; double num2 = BOAZ;
      while (units_file >> num1 >> nameUnit1 >> operEqual >> num2 >> nameUnit2){
        if(num1 == 1 && operEqual == "=" && num2 > 0){
          mat[nameUnit2][nameUnit1] = 1/num2;
          mat[nameUnit1][nameUnit2] = num2;
          units[nameUnit1] = 1;
          units[nameUnit2] = 1;
          // addMoreUnits(nameUnit1,nameUnit2);
          // addMoreUnits(nameUnit2,nameUnit1);
        }else{
          throw invalid_argument{"Error: Unit conversion file is invalid\n"};
        }
      }
      runByMapAndAddMoreUnits();
      printMap(); 
    }


   /**
   * Overloading the operator IO 
   * cout << a;
   * cin >> a;
   * */ 
    ostream& operator<<(ostream& os , const NumberWithUnits& nu){
        os << nu.unitAmount << "[" << nu.unit << "]";
        return os;
    }
    istream& operator>>(istream& is , NumberWithUnits& nu){
      string str;
      double num = BOAZ;
      char  c1 = '0',c2 = '0';
      is >> num >> c1 >> str;
      if(str.at(str.length() - 1) !=  ']'){
        is >> c2;
      }else{
        str = str.substr(0, str.length()-1);
      }
      nu = NumberWithUnits(num,str);
      return is;
    }

   /**
   * Overloading  the operator -
   * a - b
   * a - 5
   * 5 - a
   * (-a) 
   * */ 
    NumberWithUnits operator-(const NumberWithUnits& nu1 , const NumberWithUnits& nu2){
      // cout << nu1 << " - (" << convertUnit1ToUnit2(nu2.unit,nu1.unit, nu2.unitAmount) << "["<<nu1.unit << "]) = ";
      return NumberWithUnits(nu1.unitAmount - convertUnit1ToUnit2(nu2.unit,nu1.unit, nu2.unitAmount),nu1.unit);
    }
    NumberWithUnits operator-(const NumberWithUnits& nu1 , const double num){
      // cout << nu1 << " - (" << num << "[" << nu1.unit << "]) = ";
      return NumberWithUnits(nu1.unitAmount - num, nu1.unit);
    }
    NumberWithUnits operator-(const double num , const NumberWithUnits& nu1){
      // cout << num << "[" << nu1.unit  << "] - (" << nu1  << ") = ";
      return NumberWithUnits(num - nu1.unitAmount, nu1.unit);
    }
    NumberWithUnits operator-(const NumberWithUnits& nu1){
      // cout << "(-" << nu1 << ") = ";
      return NumberWithUnits(-nu1.unitAmount, nu1.unit);
    }

    /**
     * Overloading the operator +
     * a + b
     * a + 5
     * 5 + a
     * (+a) 
     * */ 
    NumberWithUnits operator+(const NumberWithUnits& nu1 , const NumberWithUnits& nu2){
      // cout << nu1 << " + (" << convertUnit1ToUnit2(nu2.unit,nu1.unit, nu2.unitAmount) << "["<<nu1.unit << "]) = ";
      return NumberWithUnits(nu1.unitAmount + convertUnit1ToUnit2(nu2.unit,nu1.unit, nu2.unitAmount),nu1.unit);
    }
    NumberWithUnits operator+(const NumberWithUnits& nu1 , const double num){
      // cout << nu1 << " + (" << num << "[" << nu1.unit << "]) = ";
      return NumberWithUnits(nu1.unitAmount + num, nu1.unit);
    }
    NumberWithUnits operator+(const double num , const NumberWithUnits& nu1){
      // cout << num  << "[" << nu1.unit  << "] + (" << nu1  << ") = ";
      return NumberWithUnits(num + nu1.unitAmount, nu1.unit);
    }
    NumberWithUnits operator+(const NumberWithUnits& nu1){
      // cout << "(+" << nu1 << ") = ";
      return NumberWithUnits(nu1.unitAmount, nu1.unit);
    }

    /**
     * Overloading the operator *
     * a * b
     * a * 5
     * 5 * a
     * */ 
    NumberWithUnits operator*(const NumberWithUnits& nu1 , const NumberWithUnits& nu2){
      // cout << nu1 << " * (" << convertUnit1ToUnit2(nu2.unit,nu1.unit, nu2.unitAmount) << "["<<nu1.unit << "]) = ";
      return NumberWithUnits(nu1.unitAmount * convertUnit1ToUnit2(nu2.unit,nu1.unit, nu2.unitAmount),nu1.unit);
    }
    NumberWithUnits operator*(const NumberWithUnits& nu1 , const double num){
      // cout << nu1 << " * (" << num << "[" << nu1.unit << "]) = ";
      return NumberWithUnits(nu1.unitAmount * num, nu1.unit);
    }
    NumberWithUnits operator*(const double num , const NumberWithUnits& nu1){
      // cout << num  << "[" << nu1.unit  << "] * (" << nu1  << ") = ";
      return NumberWithUnits(num * nu1.unitAmount, nu1.unit);
    }

    /**
     * Overloading the operators with = that not check equals
     * a += b
     * a += 5
     * */
    NumberWithUnits &NumberWithUnits::operator+=(const NumberWithUnits &nu2){
      // cout << *this << " += (" << convertUnit1ToUnit2(nu2.unit,this->unit, nu2.unitAmount) << "["<<this->unit << "]) = ";
      *this = *this + nu2;
      return *this;
    }
    NumberWithUnits &NumberWithUnits::operator+=(const double &num){
      // cout << *this << " += (" << num << "[" << this->unit << "]) = ";
      *this = *this + num;
      return *this;
    }
    NumberWithUnits operator+=(const double num , NumberWithUnits& nu1){
      // cout << num  << "[" << nu1.unit  << "] += (" << nu1  << ") = ";
      nu1.unitAmount += num;
      return nu1;
    }

    /**
     * Overloading the operators with = that not check equals
     * a -= b
     * a -= 5
     * */
    NumberWithUnits &NumberWithUnits::operator-=(const NumberWithUnits &nu2){
      // cout << *this << " -= (" << convertUnit1ToUnit2(nu2.unit,this->unit, nu2.unitAmount) << "["<<this->unit << "]) = ";
      *this = *this - nu2;
      return *this;
    }
    NumberWithUnits &NumberWithUnits::operator-=(const double &nu2){
      // cout << *this << " -= (" << nu2 << "[" << this->unit << "]) = ";
      *this = *this - nu2;
      return *this;
    }
    NumberWithUnits operator-=(const double num , NumberWithUnits& nu1){
      // cout << num  << "[" << nu1.unit  << "] -= (" << nu1  << ") = ";
      nu1.unitAmount = -nu1.unitAmount + num;
      return nu1;
    }
  
    /**
     * Overloading the operators with = that not check equals
     * a *= b
     * a *= 5
     * 5 *= a
     * */ 
    NumberWithUnits &NumberWithUnits::operator*=(const NumberWithUnits &nu2){
      // cout << *this << " *= (" << convertUnit1ToUnit2(nu2.unit,this->unit, nu2.unitAmount) << "["<<this->unit << "]) = ";
      *this = *this * nu2;
      return *this;
    }
    NumberWithUnits &NumberWithUnits::operator*=(const double &nu2){
      // cout << *this << " *= (" << nu2 << "[" << this->unit << "]) = ";
      *this = *this * nu2;
      return *this;
    }
    NumberWithUnits operator*=(const double num , NumberWithUnits& nu1){
      // cout << num  << "[" << nu1.unit  << "] *= (" << nu1  << ") = ";
      nu1.unitAmount *= num;
      return nu1;
    }

    /**
     * Overloading the operators with = that not check equals
     * a /= b
     * a /= 5
     * 5 /= a
     * */ 
    NumberWithUnits &NumberWithUnits::operator/=(const NumberWithUnits &nu2){
      // cout << *this << " /= (" << convertUnit1ToUnit2(nu2.unit,this->unit, nu2.unitAmount) << "["<<this->unit << "]) = ";
      *this = *this / nu2;
      return *this;
    }
    NumberWithUnits &NumberWithUnits::operator/=(const double &nu2){
      // cout << *this << " /= (" << nu2 << "[" << this->unit << "]) = ";
      *this = *this / nu2;
      return *this;
    }
    NumberWithUnits operator/=(const double num , NumberWithUnits& nu1){
      // cout << num  << "[" << nu1.unit  << "] /= (" << nu1  << ") = ";
      nu1.unitAmount = nu1.unitAmount/num;
      return nu1;
    }

    /**
     * Overloading the operator /
     * a / b
     * a / 5
     * 5 / a
     * */ 
    NumberWithUnits operator/(const NumberWithUnits& nu1 , const NumberWithUnits& nu2){
      // cout << nu1 << " / (" << convertUnit1ToUnit2(nu2.unit,nu1.unit, nu2.unitAmount) << "["<<nu1.unit << "]) = ";
      return NumberWithUnits(nu1.unitAmount / convertUnit1ToUnit2(nu2.unit,nu1.unit, nu2.unitAmount),nu1.unit);
    }
    NumberWithUnits operator/(const NumberWithUnits& nu1 , const double num){
      // cout << nu1 << " / (" << num << "[" << nu1.unit << "]) = ";
      return NumberWithUnits(nu1.unitAmount / num, nu1.unit);
    }
    NumberWithUnits operator/(const double num , const NumberWithUnits& nu1){
      // cout << num  << "[" << nu1.unit  << "] / (" << nu1  << ") = ";
      return NumberWithUnits(num / nu1.unitAmount, nu1.unit);
    }

    /**
     * Overloading the operators that check equals
     * a == b
     * a == 5
     * 5 == a
     * */ 
    bool operator==(const NumberWithUnits& nu1 , const NumberWithUnits& nu2){
      // cout << nu1 << " == " << convertUnit1ToUnit2(nu2.unit,nu1.unit, nu2.unitAmount) << "[" << nu1.unit <<"] = ";
      return compareForUnits(nu1,nu2) == 0;
    }
    bool operator==(const double num, const NumberWithUnits& nu1){
      // cout << nu1 << " == " << num << "[" << nu1.unit << "] = ";
      return compareForUnits(nu1, NumberWithUnits(num , nu1.unit)) == 0;
    }
    bool operator==(const NumberWithUnits& nu1 , const double num){
      // cout << num << "[" << nu1.unit << "] == "  << nu1 << " = " ;
      return compareForUnits(nu1, NumberWithUnits(num , nu1.unit)) == 0;
    }

    /**
     * Overloading the operators that check equals
     * a < b
     * a < 5
     * 5 < a
     * */ 
    bool operator<(const NumberWithUnits& nu1 , const NumberWithUnits& nu2){
      // cout << nu1 << " < " << nu2 << " = ";
      return compareForUnits(nu1,nu2) == -1;
    }
    bool operator<(const NumberWithUnits& nu1 , const double num){
      // cout << nu1 << " < " << num << "[" << nu1.unit << "] = ";
      return compareForUnits(nu1, NumberWithUnits(num,nu1.unit)) == -1;
    }
    bool operator<(const double num, const NumberWithUnits& nu1){
      // cout << num << "[" << nu1.unit << "] < "  << nu1 << " = " ;
      return compareForUnits(NumberWithUnits(num,nu1.unit), nu1) == -1;
    }

    /**
     * Overloading the operators that check equals
     * a > b
     * a > 5
     * 5 > a
     * */ 
    bool operator>(const NumberWithUnits& nu1 , const NumberWithUnits& nu2){
      // cout << nu1 << " > " << nu2 << " = ";
      return compareForUnits(nu1,nu2) == 1;
    }
    bool operator>(const NumberWithUnits& nu1 , const double num){
      // cout << nu1 << " > " << num << "[" << nu1.unit << "] = ";
      return compareForUnits(nu1, NumberWithUnits(num,nu1.unit)) == 1;
    }
    bool operator>(const double num, const NumberWithUnits& nu1){
      // cout << num << "[" << nu1.unit << "] > "  << nu1 << " = " ;
      return compareForUnits(NumberWithUnits(num,nu1.unit), nu1) == 1;
    }

    /**
     * Overloading the operators that check equals
     * a >= b
     * a >= 5
     * 5 >= a
     * */
    bool operator>=(const NumberWithUnits& nu1 , const NumberWithUnits& nu2){
      // cout << nu1 << " >= " << convertUnit1ToUnit2(nu2.unit,nu1.unit, nu2.unitAmount) << "[" << nu1.unit <<"] = ";
      return compareForUnits(nu1,nu2) >= 0;
    }
    bool operator>=(const NumberWithUnits& nu1 , const double num){
      // cout << nu1 << " >= " << num << "[" << nu1.unit << "] = ";
      return compareForUnits(nu1,NumberWithUnits{num,nu1.unit}) >= 0;
    }
    bool operator>=(const double num , const NumberWithUnits& nu1){
      // cout << num << "[" << nu1.unit << "] >= "  << nu1 << " = " ;
      return compareForUnits(NumberWithUnits{num,nu1.unit},nu1) >= 0;
    }

    /**
     * Overloading the operators that check equals
     * a <= b
     * a <= 5
     * 5 <= a
     * */ 
    bool operator<=(const NumberWithUnits& nu1 , const NumberWithUnits& nu2){
      // cout << nu1 << " <= " << convertUnit1ToUnit2(nu2.unit,nu1.unit, nu2.unitAmount) << "[" << nu1.unit <<"] = ";
      return compareForUnits(nu1,nu2) <= 0;
    }
    bool operator<=(const NumberWithUnits& nu1 , const double num){
      // cout << nu1 << " <= " << num << "[" << nu1.unit << "] = ";
      return compareForUnits(nu1,NumberWithUnits{num,nu1.unit}) <= 0;
    }
    bool operator<=(const double num , const NumberWithUnits& nu1){
      // cout << num << "[" << nu1.unit << "] <= "  << nu1 << " = " ;
      return compareForUnits(NumberWithUnits{num,nu1.unit},nu1) <= 0;
    }

    /**
     * Overloading the operators that check equals
     * a <= b
     * a <= 5
     * 5 <= a
     * */ 
    bool operator!=(const NumberWithUnits& nu1 , const NumberWithUnits& nu2){
        // cout << nu1 << " != " << convertUnit1ToUnit2(nu2.unit,nu1.unit, nu2.unitAmount) << "[" << nu1.unit <<"] = ";
        return compareForUnits(nu1,nu2) != 0;
    }
    bool operator!=(const NumberWithUnits& nu1 , const double num){
        // cout << nu1 << " != " << num << "[" << nu1.unit << "] = ";
        return compareForUnits(nu1, NumberWithUnits(num , nu1.unit)) != 0;
    }
    bool operator!=(const double num , const NumberWithUnits& nu1){
        // cout << num << "[" << nu1.unit << "] != "  << nu1 << " = " ;
        return compareForUnits(nu1, NumberWithUnits(num , nu1.unit)) != 0;
    }

  /**
   * Overloading the operators that check equals
   * a++
   * ++a
   * */ 
    NumberWithUnits& NumberWithUnits::operator++() {  //prefix - ++a
        // cout << "++"<< *this << " = ";
        ++(this->unitAmount);
        return *this;
    }
    NumberWithUnits NumberWithUnits::operator++(int) {  //postfix - a++
        // cout << *this << "++ = ";
        return NumberWithUnits((this->unitAmount)++, this->unit);
    }

  /**
   * Overloading the operators that check equals
   * a--
   * --a
   * */ 
    NumberWithUnits& NumberWithUnits::operator--() {  //prefix - --a
        // cout << "--"<< *this << " = ";
        --(this->unitAmount);
        return *this;
    }
    NumberWithUnits NumberWithUnits::operator--(int) {  //postfix - a--
        // cout << *this << "-- = ";
        return NumberWithUnits((this->unitAmount)--, this->unit);
    }
};
