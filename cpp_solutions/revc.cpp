#include <iostream>
#include <string>
#include <algorithm>
#include "rosalind.h"

int main() {
  std::string DNA,DNA_C;
	std::cin >> DNA;
	DNA_C=DNA_compliment(DNA);
	
  for(auto& x:DNA_C) {
    std::cout << x;
  }
  std::cout << std::endl;

  return 0;
}
