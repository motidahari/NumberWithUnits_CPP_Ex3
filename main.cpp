/**
  * Number With Units Main
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
#include "NumberWithUnits.cpp"
using namespace std;
using namespace ariel;


int main(){


  ifstream units_file{"units.txt"};
  ariel::NumberWithUnits::read_units(units_file);

  ariel::NumberWithUnits a{2, "km"};
  ariel::NumberWithUnits b{500, "m"};
  ariel::NumberWithUnits c;
  cout << "\n\n";
  cout << "a = " << a << "\n";
  cout << "b = " << b << "\n\n";

  
/*
  check to the operator -

  The output should be{
    a-b = 1.5[km]
    c-2 = -0.5[km]
    2-c = 2.5[km]
    2-(-c) = 4.5[km]
    (-c) = -4.5[km]
  }  
  */
  cout << "check to the operator -" << "\n";
  c = a - b;
  cout << "a-b = "<< c << "\n";
  c = c - 2;
  cout  << "c-2 = " << c << "\n";
  c = 2 - c;
  cout << "2-c = " << c << "\n";
  c = 2 -(-c);
  cout << "2-(-c) = " << c << "\n";
  c =(-c) - 2;
  cout << "(-c) - 2 = " << c << "\n";
  cout << "(-c) = " <<-c << "\n\n";
  

/*
  check to the operator +

  The output should be{
    a+b = 2.5[km]
    c+2 = 4.5[km]
    2+c = 6.5[km]
    2+(+c) = 8.5[km]
    (+c) = 8.5[km]
  }  
  */
  cout << "check to the operator +" << "\n";
  c = a + b;
  cout << "a+b = "<< c << "\n";
  c = c + 2;
  cout  << "c+2 = " << c << "\n";
  c = 2 + c;
  cout << "2+c = " << c << "\n";
  c = 2 +(+c);
  cout << "2+(+c) = " << c << "\n";
  cout << "(+c) = " <<+c << "\n\n";
  

/*
  check to the operator *

  The output should be{
    a*b = 1[km]
    c*2 = 2[km]
    2*c = 4[km]
    2*(c) = 8[km]
  }  
  */
  cout << "check to the operator *" << "\n";
  c = a * b;
  cout << "a*b = "<< c << "\n";
  c = c * 2;
  cout  << "c*2 = " << c << "\n";
  c = 2 * c;
  cout << "2*c = " << c << "\n";
  c = 2 *(c);
  cout << "2*(c) = " << c << "\n\n";
  


  /*
  check to the operator /

  The output should be{
    a/b = 4[km]
    c/2 = 2[km]
    2/c = 1[km]
    2/(c) = 2[km]
  }  
  */
  cout << "check to the operator /" << "\n";
  c = a / b;
  cout << "a/b = "<< c << "\n";
  c = c / 2;
  cout  << "c/2 = " << c << "\n";
  c = 2 / c;
  cout << "2/c = " << c << "\n";
  c = 2 /(c);
  cout << "2/(c) = " << c << "\n\n";
  


  
  /*
  check to the operator +=

  The output should be{
    c+=a = 3[km]
    c+=2 = 5[km]
    2+=c = 7[km]
  }  
  */
  cout << "check to the operator +=" << "\n";
  c += a;
  cout << "c+=a = "<< c << "\n";
  c += 2;
  cout  << "c+=2 = " << c << "\n";
  2 += c;
  cout << "2+=c = " << c << "\n\n";
  


    /*
  check to the operator -=

  The output should be{
    c-=a = -1[km]
    c-=2 = -3[km]
    2-=c = 5[km]
  }  
  */
  cout << "check to the operator -=" << "\n";
  c -= a;
  cout << "c-=a = "<< c << "\n";
  c -= 2;
  cout  << "c-=2 = " << c << "\n";
  2 -= c;
  cout << "2-=c = " << c << "\n\n";
  
  
  
  /*
  check to the operator *=

  The output should be{
    c*=a = 2[km]
    c*=2 = 4[km]
    2*=c = 8[km]
  }  
  */
  cout << "check to the operator *=" << "\n";
  c *= a;
  cout << "c*=a = "<< c << "\n";
  c *= 2;
  cout  << "c*=2 = " << c << "\n";
  2 *= c;
  cout << "2*=c = " << c << "\n\n";
  
  
  /*
  check to the operator /=

  The output should be{
    c/=a = 0.5[km]
    c/=2 = 0.25[km]
    2/=c = 0.125[km]
  }  
  */
  cout << "check to the operator /=" << "\n";
  c /= a;
  cout << "c/=a = "<< c << "\n";
  c /= 2;
  cout  << "c/=2 = " << c << "\n";
  2 /= c;
  cout << "2/=c = " << c << "\n\n";




 /*
  check to the operator ==

  The output should be{
    (a == b) = 0
    (b == a) = 0
    (b == b) = 1
    (a == a) = 1
    (a == 2) = 1
    (2 == a) = 1
  } 
  */ 
  cout << "check to the operator ==" << "\n";
  cout << "(a == b) = " << (a == b) << "\n";
  cout << "(b == a) = " << (b == a) << "\n";
  cout << "(b == b) = " << (b == b) << "\n";
  cout << "(a == a) = " << (a == a) << "\n";
  cout << "(a == 2) = " << (a == 2) << "\n";
  cout << "(2 == a) = " << (2 == a) << "\n\n";
  

/*
 check to the operator <

  The output should be{
    (a < b) = 0
    (b < a) = 1
    (b < b) = 0
    (a < a) = 0
    (a < 2) = 0
    (2 < a) = 0
    (1 < a) = 1
    (a < 4) = 1
  } 
  */ 
  cout << "check to the operator < " << "\n";
  cout << "(a < b) = " << (a < b) << "\n";
  cout << "(b < a) = " << (b < a) << "\n";
  cout << "(b < b) = " << (b < b) << "\n";
  cout << "(a < a) = " << (a < a) << "\n";
  cout << "(a < 2) = " << (a < 2) << "\n";
  cout << "(2 < a) = " << (2 < a) << "\n";
  cout << "(1 < a) = " << (1 < a) << "\n";
  cout << "(a < 4) = " << (a < 4) << "\n\n";
  


/*
 check to the operator >

  The output should be{
    (a > b) = 1
    (b > a) = 0
    (b > b) = 0
    (a > a) = 0
    (a > 2) = 0
    (2 > a) = 0
    (1 > a) = 0
    (a > 4) = 0
  } 
  */ 
  cout << "check to the operator > " << "\n";
  cout << "(a > b) = " << (a > b) << "\n";
  cout << "(b > a) = " << (b > a) << "\n";
  cout << "(b > b) = " << (b > b) << "\n";
  cout << "(a > a) = " << (a > a) << "\n";
  cout << "(a > 2) = " << (a > 2) << "\n";
  cout << "(2 > a) = " << (2 > a) << "\n";
  cout << "(1 > a) = " << (1 > a) << "\n";
  cout << "(a > 4) = " << (a > 4) << "\n\n";

/*
 check to the operator >=

  The output should be{
    (a >= b) = 1
    (b >= a) = 0
    (b >= b) = 1
    (a >= a) = 1
    (a >= 2) = 1
    (2 >= a) = 1
    (1 >= a) = 0
    (a >= 4) = 0
  } 
  */ 
  cout << "check to the operator >= " << "\n";
  cout << "(a >= b) = " << (a >= b) << "\n";
  cout << "(b >= a) = " << (b >= a) << "\n";
  cout << "(b >= b) = " << (b >= b) << "\n";
  cout << "(a >= a) = " << (a >= a) << "\n";
  cout << "(a >= 2) = " << (a >= 2) << "\n";
  cout << "(2 >= a) = " << (2 >= a) << "\n";
  cout << "(1 >= a) = " << (1 >= a) << "\n";
  cout << "(a >= 4) = " << (a >= 4) << "\n\n";


/*
 check to the operator <=

  The output should be{
    (a >= b) = 1
    (b >= a) = 0
    (b >= b) = 1
    (a >= a) = 1
    (a >= 2) = 1
    (2 >= a) = 1
    (1 >= a) = 0
    (a >= 4) = 0
  } 
  */ 
  cout << "check to the operator <= " << "\n";
  cout << "(a <= b) = " << (a <= b) << "\n";
  cout << "(b <= a) = " << (b <= a) << "\n";
  cout << "(b <= b) = " << (b <= b) << "\n";
  cout << "(a <= a) = " << (a <= a) << "\n";
  cout << "(a <= 2) = " << (a <= 2) << "\n";
  cout << "(2 <= a) = " << (2 <= a) << "\n";
  cout << "(1 <= a) = " << (1 <= a) << "\n";
  cout << "(a <= 4) = " << (a <= 4) << "\n\n";



 /*
  check to the operator !=

  The output should be{
    (a != b) = 1
    (b != a) = 1
    (b != b) = 0
    (a != a) = 0
    (a != 2) = 0
    (2 != a) = 0
  } 
  */ 
  cout << "check to the operator !=" << "\n";
  cout << "(a != b) = " << (a != b) << "\n";
  cout << "(b != a) = " << (b != a) << "\n";
  cout << "(b != b) = " << (b != b) << "\n";
  cout << "(a != a) = " << (a != a) << "\n";
  cout << "(a != 2) = " << (a != 2) << "\n";
  cout << "(2 != a) = " << (2 != a) << "\n\n";
  

 /*
  check to the operator ++

  The output should be{
    (a++) = 2[km]
    a = 3[km]
    (++a) = 4[km]
    a = 4[km]
  } 
  */ 
  cout << "check to the operator ++" << "\n";
  cout << "(a++) = " << a++ << "\n";
  cout << "a = " << a << "\n";
  cout << "(++a) = " << ++a << "\n";
  cout << "a = " << a << "\n\n";


 /*
  check to the operator --

  The output should be{
    (a--) = 4[km]
    a = 3[km]
    (--a) = 2[km]
    a = 2[km]
  } 
  */ 
  cout << "check to the operator --" << "\n";
  cout << "(a--) = " << a-- << "\n";
  cout << "a = " << a << "\n";
  cout << "(--a) = " << --a << "\n";
  cout << "a = " << a << "\n\n";

  istringstream sample_input{"700 [ kg ]"};
  sample_input >> a;
  cout << a << endl;   // Prints "700[kg]"
  cout << (a += ariel::NumberWithUnits{1, "ton"}) << endl;  // prints "1700[kg]"
  cout << a << endl;   // Prints "1700[kg]". Note that a has changed.


  return 0;
}

/*
clear && clang-9 -o run main.cpp -lstdc++ && ./run
*/