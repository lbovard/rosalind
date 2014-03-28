#include <iostream>
#include <string>
#include <vector>
#include "rosalind.h"

int main() {
  std::string DNA,sub;
  std::cin >> DNA;
  std::cin >> sub;
	std::vector<unsigned int> locs;
	locs=substring_loc(DNA,sub);
	for(auto &x: locs) {
		std::cout << x << " ";
	}
	std::cout << std::endl;
  return 0;
}
