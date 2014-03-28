#include <iostream>
#include <string>
#include <vector>
#include <map>

//linear time algorithm 
int main() { 
	std::map<std::string,unsigned int> frequency;
	std::vector<std::string> solution;
	unsigned int max=0;
	unsigned int n,k;
	std::string string,sub;
	std::cin >> string;
	std::cin >> k;
	n=string.length();
	
	for(unsigned int i=0;i<n-k;++i) {
		sub=string.substr(i,k);
		//key doesn't exist, add it
		if(frequency.count(sub)==0) {	
			frequency[sub]=1;
		} else {
			frequency[sub]++;
		}
	}
	for(auto& x:frequency) {
		if(x.second > max) {
			solution.clear();
			solution.push_back(x.first);
			max=x.second;
		} else if(x.second ==max) {
			solution.push_back(x.first);
		} 
//		std::cout << x.first << " " << x.second << std::endl;
	}
	for(auto &x:solution) {
		std::cout << x << " ";
	}
	std::cout << std::endl;
	
	return 0;
}
