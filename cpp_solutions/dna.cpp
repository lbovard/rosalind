#include <iostream>
#include <string>

int main() {
  unsigned int A_count=0,C_count=0,G_count=0,T_count=0;
  std::string DNA;
  std::getline(std::cin, DNA);
  for(std::string::iterator it=DNA.begin(); it!=DNA.end();++it) {
    switch(*it) {
      case 'A':
        A_count++;
        break;
      case 'C':
        C_count++;
        break;
      case 'G':
        G_count++;
        break;
      case 'T':
        T_count++;
        break;
      default:
        break;
    } 
  }
  std::cout << A_count << " " << C_count << " " << G_count << " " << T_count << std::endl;

  return 0;
}
