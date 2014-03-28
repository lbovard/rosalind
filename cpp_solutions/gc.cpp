#include <iostream>
#include <string>
#include "rosalind.h"

int main() {
	DNA_list data;
	DNA_label label;
	filename input_fn="rosalind_gc.txt";
	read_FASTA(data,label,input_fn);
	std::vector<unsigned int> DNA_data;	
	for(unsigned int i=0;i<data.size();++i) {
		DNA_data=DNA_stats(data[i]);
		for(auto& x: DNA_data) {
			std::cout << x << " ";
		}
		std::cout << std::endl;
	}
  return 0;

}
