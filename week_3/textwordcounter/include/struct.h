#ifndef struct_h
#define struct_h

#include <vector>
#include <string>
#include <iostream>
/*  STRUCT DECLARATION */
struct result_line{
	std::size_t counter;
	std::string line;	
};

std::vector<result_line> uniq(std::vector<std::string>);
void print(std::vector<result_line>);
void filter(std::string&);
#endif
