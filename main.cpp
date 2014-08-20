#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>
#include <sstream>

#include <gmp.h>
#include <gmpxx.h>

#include "twos.h"

//                                                                32309054545037006034346729482
// test case:  "hello world" as a text file on unix translates to 32309054545037006034346730506


//get the largest power of 2 that is smaller than or equal to the target file
// returns the exponent to which you'd raise 2 to get the number
int powerOfTwo(mpz_class x) {
  int i;
  for(i=0; ( TWOS[i] <= x ) && ( i < 226 ); i++) {
    //std::cout<<TWOS[i]<<std::endl;
  }
  
  return i-1;
}

int main(int argc, char* argv[]) {
  if( argc != 2){
    std::cout<< "Usage: "<<argv[0]<<" <path to file>" << std::endl;
    return 1;
  }

  std::string outputstr = "";
  std::ostringstream oss;
  
  //change this to actually read a file from disk instead of stdin
  mpz_class filedata(argv[1]);

  //if compiler supported c++11 we could use this to search for filedata in TWOS[], but I'm on debian stable w gcc 4.6 :/
  //bool exists = std::find(std::begin(TWOS), std::end(TWOS), filedata) != std::end(TWOS);

  int exponent = powerOfTwo(filedata);
  mpz_class remainder( filedata - TWOS[exponent]);

  if( remainder == 0 ){
    oss << exponent;
    outputstr = "2^" + oss.str();
    std::cout << outputstr << std::endl;
    return 0;
  }

  std::cout << "exponent is " << exponent << std::endl;
  std::cout << "twos[exponent] is " << TWOS[exponent] << std::endl;
  std::cout << TWOS[exponent] << std:: endl;
  std::cout << filedata <<  std::endl;
  std::cout << "iterating on remainder which equals" << remainder << std::endl;
  while(remainder >= 128){
    //can't just concatenate an int to a string
    oss << exponent;
    outputstr+="2^" +oss.str()+ "+";

    //see if the remainder is near any powers of two
    exponent = powerOfTwo(remainder);
    remainder = remainder - TWOS[exponent];
    std::cout << exponent << std::endl;

    //set stringstream to empty string and then clear error flag(s)
    oss.str("");
    oss.clear();
  }
  oss.str("");
  oss.clear();
  oss << remainder;
  outputstr += oss.str();

  std::cout << outputstr << std::endl;
  
  return 0;
}
