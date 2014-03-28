#include <iostream>
#include <vector>
#include <string>
#include "rosalind.h"

//note the logic is SLIGHTLY different from KMP on wikipedia
//they shift everything over. Same idea however.
std::vector<int> construct_failure(const std::string& sub) {
	unsigned int pos,len,cnd; std::vector<int> T;
	len=sub.length();
	T.resize(len);
	T[0]=0;
	pos=1;cnd=0;
	while(pos<len) {
		if(sub[pos]==sub[cnd]) {
			cnd++;
			T[pos]=cnd;
			pos++;
		} else if(cnd>0) {
			cnd=T[cnd-1];
		} else {
			T[pos]=0;
			pos++;
		}

	}
	return T;
}

//std::vector<unsigned int> KMP(const std::string 
int main() {
	DNA_list data;
	DNA_label label;
	filename fn="rosalind_kmp.txt";
//	filename fn="input.txt";
	read_FASTA(data,label,fn);
	std::vector<int> table;
	table=construct_failure(data[0]);
	for(auto& x:table) {
		std::cout << x << " ";
	}
	std::cout << std::endl;

	return 0;
}
