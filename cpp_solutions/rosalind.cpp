#include <iostream>
#include <algorithm>
#include <string>

#include "rosalind.h"

std::string DNA_to_RNA(std::string DNA) {
  std::string RNA;
  RNA=DNA;
  std::replace(RNA.begin(),RNA.end(),'T','U');
  return RNA;
}

