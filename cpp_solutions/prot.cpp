#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <sstream>

// std::map<std::string,char> get_prot_dic() {
std::map<std::string,char> get_prot_dic(std::string fn) {
  using namespace std;
  map<string,char> prot_dic;
//  ifstream prot_dic_file("prot_dic.txt");
  ifstream prot_dic_file(fn);
  string line,code,symbol;
  stringstream temp; 
  while(getline(prot_dic_file,line)) { 
    //move string line to stringstream
    temp<<line;
    temp >> code >> symbol;
    prot_dic[code]=symbol[0];
    
    //clear stringstream
    temp.clear();   
  } 
  prot_dic_file.close();
  return prot_dic;
}
int main() {
  std::map<std::string,char> prot_dic;
  std::string prot_dic_fn="prot_dic.txt";
  std::string RNA,amino;
  //get protein dictionary 
  prot_dic=get_prot_dic(prot_dic_fn);
  std::cin >> RNA;
  for(unsigned int i=0;i<RNA.size();i+=3) {
    amino=RNA.substr(i,3); 
    if(prot_dic[amino]!='0') { 
      std::cout << prot_dic[amino];
    } 
    amino.clear();
  }
  std::cout << std::endl;
  return 0;
}
