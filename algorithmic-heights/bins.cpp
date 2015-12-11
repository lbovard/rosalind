/*


*/
#include <iostream>
#include <vector>

int binary_search(const std::vector<int>& data,const int key,unsigned int imin, unsigned int imax) {
  unsigned int mid=0;
  while(imax>=imin) {
    mid = (imin+imax)/2;
    if(data[mid]==key) {
      //want value in range 1,n not 0,n-1
      return mid+1;
    } else if (data[mid]<key) {
      imin=mid+1;
    } else {
      imax=mid-1;
    } 
  } 
  return -1; 
}


int main() {
  unsigned int n,m;

  std::cin >> n;
  std::cin >> m;
  std::vector<int> data(n);
  std::vector<int> key(m);

  for(unsigned int i=0;i<n;++i) {
    std::cin >> data[i];
  }
  for(unsigned int i=0;i<m;++i) {
    std::cin >> key[i];
  }
  for(std::vector<int>::iterator it=key.begin();it!=key.end();++it) {
//    std::cout << *it << " ";
    std::cout << binary_search(data,*it,0,n) << " ";
  }
  std::cout<< std::endl;
  return 0;
}



