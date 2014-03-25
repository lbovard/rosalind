#include <iostream>
#include <vector>

int main() {
  unsigned int n;
  int st,val;
  std::cin >> n;
  std::vector<int> A,B;
  std::cin >> st;
  for(unsigned int i=1;i<n;++i) { 
    std::cin >> val;
    if(val<=st) { 
      A.push_back(val);
    } else {
      B.push_back(val);
    }
  }
  A.push_back(st);
  A.insert(A.end(),B.begin(),B.end());
  for(auto &x : A) {
    std::cout << x << " ";
  }
  std::cout << std::endl;
  return 0;
}
