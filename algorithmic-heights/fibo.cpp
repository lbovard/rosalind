/*
 This is a very straight forward implementation of the Fibonacci algorithm. 
 Since this site doesn't run on the server, a fast implementation isn't required. 
 Furthermore, given the restriction that N<=25, a simple non-recursive implementation
 that uses the previous values will suffice.

 Furthermore, we know that F_{n} = O(\phi ^{n}) ~ O(1.6^n) which gives ~126,000 for N=25  
 The actual answer is F_{25} = 75025 but this is fine since we are aren't really in an asymptotic regime.
 A quick numerical calculation reveals that around N~70 is this approximation much more valid, where the 
 above answer differs by only 2% from the real.

 This result tells us that we can fit the answer safely in an integer. However, I have used unsigned long ints
 just because I can and it allows us to compute up to F_{93} correctly. For higher values, we would have to have 
 some form of large integers to accurately compute the numbers. However, most problems that require this high value 
 of Fibonacci typically ask you mod 2^64 which means that all our calculations can safely fit in to a 64-bit integer. 
 In those cases, we have to be clever about what algorithms we are using. 
*/
#include <iostream>


typedef unsigned long int uint64;

int main() {
  uint64 a,b,c,n;
  a=1,b=0;
  
  std::cin >> n;
  for(unsigned int i=0;i<n;i++) {
    c=a+b;
    b=a;
    a=c;
  }
  std::cout << b << std::endl;
  return 0;
}
