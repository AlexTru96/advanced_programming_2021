#include "definitions.h"

std::vector<std::string> uniq(std::vector<std::string> strings_input){	
std::string line = "";
std::string previous= "" ;
std::string next= "";
std::vector<std::string> save;
bool first= true;
int counter=0;
std::size_t _size = strings_input.size();

for(unsigned int i=0;i<_size;++i){
line=strings_input[i];
next= line;

if(first){
	++counter;
	first= false;
	previous=line;
	continue;
}

if(previous == next)
	++counter;
else{
	save.emplace_back(previous);
	counter = 1;
}	
previous = line;
}
	save.emplace_back(previous);
	return save;
}
