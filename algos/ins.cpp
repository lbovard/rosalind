#include <iostream>
#include <vector>
#include <algorithm>

void swaps(int &a, int &b) {
  int c=a;
  a=b;
  b=c;
}

int main() {
  unsigned int n,k,count=0;
  std::cin >> n;
  std::vector<int> data(n);
  for(unsigned int i=0;i<n;i++) {
    std::cin >> data[i];
  }
  for(unsigned int i=1;i<n;++i) {
    k=i;
    while(k>0 && data[k]<data[k-1]) {
     // swaps(data[k],data[k-1]);
      std::swap(data[k],data[k-1]);
      count++;
      k--;
    }
  } 
  std::cout << count << std::endl;
  return 0;
}
