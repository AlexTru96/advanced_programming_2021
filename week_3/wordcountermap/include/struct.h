#ifndef struct_h
#define struct_h

#include <vector>
#include <map>
#include <string>
#include <iostream>
/*  STRUCT DECLARATION */

std::map<std::string,unsigned int> uniq(std::vector<std::string>);
void print(std::map<std::string,unsigned int>);
void filter(std::string&);
#endif
