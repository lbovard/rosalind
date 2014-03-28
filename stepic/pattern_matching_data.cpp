#include <iostream>
#include <vector>
#include "../cpp_solutions/rosalind.h"

int main() {
	std::vector<unsigned int> locs;
	std::string DNA,sub;
	std::cin >> sub;
	std::cin >> DNA;
	locs=substring_loc(DNA,sub);
	for(auto&x : locs) {
		std::cout << x-1 << " ";
	}
	std::cout << std::endl;
}
