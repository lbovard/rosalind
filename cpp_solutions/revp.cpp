#include <iostream>
#include "rosalind.h"

int main() {
	DNA_list data;
	DNA_label label;
	filename fn= "rosalind_revp.txt";
	read_FASTA(data,label,fn);
	std::string DNA;
	std::string DNA_rc;
	DNA=data[0];
	std::cout << DNA << std::endl;
	DNA_rc=DNA_reverse_compliment(DNA);
	std::cout << DNA_rc << std::endl;
 	return 0;
}
