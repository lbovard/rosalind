/*
hash map solution that doesn't work
*/
#include <iostream>
#include <unordered_map> 
#include <vector>

void sum3(const std::vector<int>& values,const std::unordered_map<int,unsigned int>& hash) {
  auto m = values.size();
  for(unsigned int i=0;i<m;i++) {
    for(unsigned int j=i+1;j<m;j++) { 
      if(hash.count(-values[i]-values[j])==1) {
        //need to use at because [] operator is non-const
        std::cout << i+1 << " " << j+1 << " " << hash.at(-values[i]-values[j])+1 << std::endl;
        return;
      }
    }
  }
  std::cout << "-1" << std::endl;
}
int main() {
  unsigned int m,n;
  int a;
  unsigned int p,q;
  std::cin >> n;
  std::cin >> m;
  std::unordered_map<int,unsigned int> hash;
  std::vector<int> values(m); 
  for(auto k=n;k>0;k--) {
    for(unsigned int i=0;i<m;++i) {
      std::cin >> values[i];
      hash[values[i]]=i;
    } 
    sum3(values,hash);
    hash.clear();
  }

  return 0;
}
