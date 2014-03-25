#include <iostream>
#include <vector>

int main() {
  unsigned int n;
  int st,val;
  std::cin >> n;
  std::vector<int> A,B,C;
  std::cin >> st;
  for(unsigned int i=1;i<n;++i) { 
    std::cin >> val;
    if(val<st) { 
      A.push_back(val);
    } else if(val==st){
      B.push_back(val);
    } else {
      C.push_back(val);
    }
  }
  B.push_back(st);
  A.insert(A.end(),B.begin(),B.end());
  A.insert(A.end(),C.begin(),C.end());
   
  for(auto &x : A) {
    std::cout << x << " ";
  }
  std::cout << std::endl;
  return 0;
}
