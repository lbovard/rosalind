#ifndef ROSALIND_H
#define ROSALIND_H
#include <string>
#include <vector>
#include <map>

//typedefs
typedef std::vector<std::string> DNA_list;
typedef std::vector<std::string> DNA_label;
typedef std::string filename;

//converts DNA string to RNA string
std::string DNA_to_RNA(std::string DNA);
//get DNA compliment 
std::string DNA_reverse_compliment(std::string DNA);
//find substring naive
std::vector<unsigned int> substring_loc(std::string DNA, std::string substring);
//initialise RNA to protein dictionary
std::map<std::string,char> initialise_prot_dic(std::string fn);
//convert RNA to protein
std::string RNA_to_protein(const std::string& RNA,const std::map<std::string,char>& prot_dic);
//read in FASTA data
void read_FASTA(std::vector<std::string>& DNA,std::vector<std::string>& label,
								std::string fn);
//get DNA stats
std::vector<unsigned int> DNA_stats(const std::string& DNA);
#endif 
