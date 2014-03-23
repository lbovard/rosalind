#include <iostream>

int main() {
  long long int a,b,c,n;
  a=1,b=0;
  
  std::cin >> n;
  for(int i=0;i<n;i++) {
    c=a+b;
    b=a;
    a=c;
  }
  std::cout << b << std::endl;
  return 0;
}
