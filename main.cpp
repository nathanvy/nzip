#include <iostream>
#include <gmp.h>
#include <gmpxx.h>
#include <stdint.h>

//k fuck this, it's actually really really inefficient.
// probably better to precompute values up to some maximum size
mpz_class previousPowerOfTwo(mpz_class x) {
  mpz_class i;
  for(i=0; (2^i) <= x; i++) {
    std::cout<< i << std::endl;
  }
  if( (2^i) == x) {
    return 0;
  }
  else {
    return i;
  }
}

int main(int argc, char* argv[]) {
  if( argc != 2){
    std::cout<< "Usage: "<<argv[0]<<" <path to file>" << std::endl;
    return 1;
  }

  mpz_class filedata(argv[1]);
  std::cout << previousPowerOfTwo(filedata) << std::endl;

  return 0;
}
