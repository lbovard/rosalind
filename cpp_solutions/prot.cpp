#include <iostream>
#include <string>
#include <map>
#include "rosalind.h"

int main() {
  std::map<std::string,char> prot_dic;
  std::string prot_dic_fn="prot_dic.txt";
  std::string RNA,amino;
	std::string protein;
  //get protein dictionary 

  prot_dic=initialise_prot_dic(prot_dic_fn);
  std::cin >> RNA;
	protein=RNA_to_protein(RNA,prot_dic);
	
	std::cout << protein;
  std::cout << std::endl;
  return 0;
}
