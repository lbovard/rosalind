#include <iostream>
#include <string>
#include "rosalind.h"

int main() {
  std::string DNA,RNA;
  std::cin >> DNA;
  RNA=DNA_to_RNA(DNA);
  std::cout << RNA;
  std::cout << std::endl;
  return 0;

}
