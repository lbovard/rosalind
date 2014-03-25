#include <iostream>
#include <algorithm>

int main() {
  int facts[8]={1,1,2,6,24,120,720,5040};
  int nums[7]={1,2,3,4,5,6,7};
  int n;
  std::cin >> n;
  std::cout << facts[n] << std::endl;
  do {
    for(unsigned int i=0;i<n;++i) {
      std::cout << nums[i] << " ";
    }
    std::cout << std::endl;
  } while (std::next_permutation(nums,nums+n));
  
  return 0;
}
