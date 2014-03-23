#include <iostream>
#include <vector>

int main() {
  unsigned int k,n,count;
  int maxElem;
  std::cin >> k;
  std::cin >> n;
  std::vector<int> data(n);
  for(unsigned int i=0;i<k;++i) {
    //get array
    count=0;
    for(unsigned int j=0;j<n;++j) {
      std::cin >> data[j]; 
      //Moore Voting algorithm to find max
      if(count==0) {
        maxElem=data[j];
      }
      if(data[j]==maxElem) {
        count++;
      } else {
        count--;
      }
    }
    count=0;
    for(auto it=data.begin();it!=data.end();++it) {
    //  std::cout << *it << " ";
      if(*it == maxElem) count++;
    }
    if(count > n/2) {
      std::cout << maxElem << " ";
    } else {
      std::cout << "-1 ";
    }
      
  }
  std::cout << std::endl;
  return 0;
}
