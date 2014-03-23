#include <iostream>
#include <vector>

int main() { 
  unsigned int n,m;
  unsigned int a,b;
  std::cin >> n;
  std::vector<int> ar1(n+1);
  for(unsigned int i=0;i<n;++i) {
    std::cin >> ar1[i];
  }
  //boundary element
  ar1[n]=100000;
  std::cin >> m;
  std::vector<int> ar2(m+1);
  for(unsigned int i=0;i<m;++i) {
    std::cin >> ar2[i];
  }
  ar2[m]=100000;
  std::vector<int> merged(n+m);
  a=0;b=0;
  for(unsigned int i=0;i<(n+m);++i) {
    if(ar1[a]<=ar2[b]) {
      merged[i]=ar1[a];
      a++;
    } else { 
      merged[i]=ar2[b];
      b++;
    }
  }
  for(auto it=merged.begin();it!=merged.end();++it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;

  
  return 0;
}
