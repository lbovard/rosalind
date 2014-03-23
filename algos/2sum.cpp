/*
hash map solution that doesn't work
*/
#include <iostream>
#include <unordered_map> 
#include <vector>

int sum2(const std::vector<int>& values,const std::unordered_map<int,bool>& hash) {
  for(auto it=values.begin();it!=values.end();++it) {
    if(hash.count(-*it)==1) {
      //always return the positive value
      if(*it>=0) return *it;
      else return -*it;
    } 
  }
  return -1;
}
int main() {
  unsigned int m,n;
  unsigned int ii;
  int a;
  unsigned int p,q;
  std::cin >> n;
  std::cin >> m;
  std::unordered_map<int,bool> hash;
  std::vector<int> values(m); 
  for(auto k=n;k>0;k--) {
    for(unsigned int i=0;i<m;++i) {
      std::cin >> values[i];
      hash[values[i]]=true;
    }
    a=sum2(values,hash);
    if(a==-1) { std::cout << "-1"; } 
    else {
      for(unsigned int i=0;i<m;i++) {
        if(values[i]==a) p=i+1;
        if(values[i]==-a) q=i+1;
      }
      std::cout << p << " " << q;
    }
    
    std::cout << std::endl;
    hash.clear();
  }

  return 0;
}
