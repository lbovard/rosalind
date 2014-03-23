#include <iostream>
#include <string>
#include <algorithm>

int main() {
  std::string RNA;
  std::getline(std::cin, RNA);
  std::replace(RNA.begin(),RNA.end(),'T','U');
  std::cout << RNA << std::endl;
  return 0;
}
