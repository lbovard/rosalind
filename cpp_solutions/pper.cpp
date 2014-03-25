#include <iostream>

int main() { 
  unsigned int n {};
  unsigned int k {}; 
  std::cin >> n;
  std::cin >> k;
  unsigned int prod=1;
  for(unsigned int i=n;i>n-k;--i) {
    prod=(prod*i)%1000000;
  }
  std::cout << prod << '\n'; 
  return 0;
}
