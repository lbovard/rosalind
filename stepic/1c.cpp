#include <iostream>
#include <vector>
#include <string>

//note the logic is SLIGHTLY different from KMP on wikipedia
//they shift everything over. Same idea however.
std::vector<int> construct_failure(const std::string& sub) {
	unsigned int pos,len,cnd,k; 
	std::vector<int> T;
	len=sub.length();
	T.resize(len);
	T[0]=-1; k=0;
	for(unsigned int i=1;i<len;++i) {
		if(sub[i]==sub[k]) {
			T[i]=k;
			k++;
		} else {
			T[i]=-1;
			k=0;
		}
	}
	return T;
}

std::vector<unsigned int> KMP(const std::string& text, const std::string& sub,const std::vector<int>& T) {
	unsigned int i,k,m,n,p;
	std::vector<unsigned int> sol;
	i=0;m=0;
	n=text.size();
	p=sub.size();
	while(m+i < n) {
//		std::cout << m << " " << i << " " << i+m << std::endl;
		if(sub[i]==text[m+i]) {
			if(i==(p-1)) {
//				std::cout << "Found at: " << m << std::endl;
				sol.push_back(m);
				m=m+i-T[i];
				i=T[i]+1; //this handles the logic
			} else {
				i++;
			}
		} else {
				m=m+i-T[i];
				i=T[i]+1; //this handles the logic 
		}
	}
	return sol; 
}

int main() {
	std::string sub;
	std::string text;
	std::cin >> sub;
	std::cin >> text;
	std::vector<int> table;
	std::vector<unsigned int> sol;
	table=construct_failure(sub);
	sol=KMP(text,sub,table);
	for(auto& x:table) {
		std::cout << x << " ";
	}
	std::cout << std::endl;

	return 0;
}
