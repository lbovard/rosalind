#include <iostream>
#include <vector>


//merges two arrays
std::vector<int> merge(std::vector<int>& ar1,std::vector<int>& ar2,unsigned int& inv_count) {
  unsigned int n=ar1.size();
  unsigned int m=ar2.size();
  std::vector<int> merged(n+m); 
  unsigned int a,b;
  a=0;b=0;
  for(unsigned int i=0;i<(n+m);++i) {
    if(a==n) {
      merged[i]=ar2[b];
      b++;
    } else if(b==m) {
      merged[i]=ar1[a];
      a++; 
    } else if(ar1[a]<=ar2[b]) {
      merged[i]=ar1[a];
      a++;
    } else { 
      merged[i]=ar2[b];
      inv_count+=n-a;
      b++;
    }
  }
  return merged;
}

std::vector<int> mergesort(std::vector<int>& arr,unsigned int& inv_count) {
  unsigned int n=arr.size();
  unsigned int n1,n2;
  if(n==1) return arr;
  else {
    n1=n/2;
    n2=n-n1;
    std::vector<int> ar1(n1),ar2(n2); 
    for(unsigned int i=0;i<n1;++i) {
      ar1[i]=arr[i];
    }
    for(unsigned int i=0;i<n2;++i) {
      ar2[i]=arr[i+n1]; 
    } 
    ar1=mergesort(ar1,inv_count);
    ar2=mergesort(ar2,inv_count);
    arr=merge(ar1,ar2,inv_count);
    return arr;
  }
}
int main() {
  unsigned int n;
  unsigned int n1,n2;
  unsigned int inv_count=0;
  std::cin >> n;
  std::vector<int> org(n);
  for(unsigned int i=0;i<n;++i) { 
    std::cin >> org[i];
  }
  org=mergesort(org,inv_count);
//  for(auto &it: org) {
//    std::cout << it << " ";
//  }
//  std::cout << std::endl;
  std::cout << inv_count << std::endl;
  return 0;
}
