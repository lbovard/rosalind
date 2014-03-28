#include <iostream>
#include "../cpp_solutions/rosalind.h"

int main() {
	std::string DNA;
	std::cin >> DNA;
	std::cout << DNA_reverse_compliment(DNA);
	return 0;
}
