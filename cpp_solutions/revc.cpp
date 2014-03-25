#include <iostream>
#include <string>
#include <algorithm>

int main() {
  std::string RNA,RNA_C;
  std::getline(std::cin, RNA); 
  for(auto it=RNA.rbegin();it!=RNA.rend();++it) {
    switch(*it) {
      case 'A':
        RNA_C+='T';
        break;
      case 'T':
        RNA_C+='A';
        break;
      case 'G':
        RNA_C+='C';
        break;
      case 'C':
        RNA_C+='G';
        break; 
      default:
        break;
    }
  }
  for(auto& x:RNA_C) {
    std::cout << x;
  }
  std::cout << '\n';

  return 0;
}
