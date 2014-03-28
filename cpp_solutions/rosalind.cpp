#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <map>

#include "rosalind.h"

std::string DNA_to_RNA(std::string DNA) {
  std::string RNA;
  RNA=DNA;
  std::replace(RNA.begin(),RNA.end(),'T','U');
  return RNA;
}

std::string DNA_reverse_compliment(std::string DNA) {
	std::string DNA_C;
  for(auto it=DNA.rbegin();it!=DNA.rend();++it) {
    switch(*it) {
      case 'A':
        DNA_C+='T';
        break;
      case 'T':
        DNA_C+='A';
        break;
      case 'G':
        DNA_C+='C';
        break;
      case 'C':
        DNA_C+='G';
        break; 
      default:
        break;
    }
  }
	return DNA_C;
}

std::vector<unsigned int> substring_loc(std::string DNA,std::string sub) {
	std::vector<unsigned int> locs;
  unsigned int n,m;
  n=DNA.length();
  m=sub.length();
  for(unsigned int i=0;i<n-m;i++) {
    if(DNA.substr(i,m)==sub) {
			locs.push_back(i+1);
    }
  }
	return locs;	
}

std::map<std::string,char> initialise_prot_dic(std::string fn) {
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

std::string RNA_to_protein(const std::string& RNA,const std::map<std::string,char>& prot_dic) { 

	std::string protein;
	std::string amino;
  for(unsigned int i=0;i<RNA.size();i+=3) {
    amino=RNA.substr(i,3); 
    if(prot_dic.at(amino)!='0') { 
			protein+=prot_dic.at(amino);
    } 
    amino.clear();
  }
	return protein;
}

void read_FASTA(std::vector<std::string>& DNA,std::vector<std::string>& label,
								std::string fn) {
	using namespace std;
	unsigned int count=0;
  ifstream FASTA_file(fn);
  string line;
	string DNA_string;
	//read in data from FASTA file
  while(getline(FASTA_file,line)) { 
		//check if first character is not >ACTGU 
		//this line could be improved
		if(line[0]!='>' && line[0]!='T' && line[0]!='A'&& 
				line[0]!='C' && line[0]!='G' && line[0]!='U') {
			cout << "ERROR IN INPUT" << endl;
			return;
		} else if(line[0]=='>') {
			//put DNA string into vector iff we have reached the next >
			if(count>0) {
				DNA.push_back(DNA_string);
				DNA_string.clear();
			}
			line.erase(0,1);
			label.push_back(line); 
			count=0;
		} else {
			DNA_string+=line; 
			count++;
		}	
	} 
	//put the last DNA string into the vector
	DNA.push_back(DNA_string);
	return;
}

std::vector<unsigned int> DNA_stats(const std::string& DNA) {
	unsigned int A_count,C_count,G_count,T_count;
	A_count=0;C_count=0;G_count=0;T_count=0;
	std::vector<unsigned int> DNA_content;	
  for(std::string::const_iterator it=DNA.begin(); it!=DNA.end();++it) {
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
	DNA_content={A_count,C_count,G_count,T_count};
	return DNA_content;
}
