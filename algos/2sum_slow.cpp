#include <iostream>
#include <vector>

void sum2(const std::vector<int>& values) {
  unsigned int i,j;
  for(i=0;i<values.size();i++) {
    for(j=i+1;j<values.size();j++) {
      if(values[i]+values[j]==0) {
        std::cout << i+1 << " " << j+1<< std::endl;
        return;
      }
    }
  }
  std::cout << "-1" << std::endl;
  return;
}
int main() {
  unsigned int n,m;
  std::cin >> n;
  std::cin >> m;
  std::vector<int> values(m);
  for(auto k=n;k>0;k--) {
    for(unsigned int i=0;i<m;i++) {
      std::cin >> values[i];
    }
    sum2(values);
  }
  return 0;
}
