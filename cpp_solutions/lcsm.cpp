#include <iostream>
#include <algorithm>
#include <string>
#include "rosalind.h"

int main() {
	DNA_list data;
	DNA_label label;
	filename f="rosalind_lcsm.txt";
	read_FASTA(data,label,f);
	std::string output="";
	for(int i=0;i<data.size();i++) {
		output+=data[i]+"*";	
	}

	std::cout << output;
}
	 
