#include <iostream>
#include <string>

int main() {
  std::string DNA,sub;
  std::cin >> DNA;
  std::cin >> sub;
  unsigned int n,m;
  n=DNA.length();
  m=sub.length();
  for(unsigned int i=0;i<n-m;i++) {
    if(DNA.substr(i,m)==sub) {
      std::cout << i+1 << " ";
    }
  }
  std::cout<<std::endl;
  return 0;
}
