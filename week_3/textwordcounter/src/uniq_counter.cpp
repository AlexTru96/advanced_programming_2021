#include "struct.h"

std::vector<result_line> uniq(std::vector<std::string> strings_input){

std::string line = "";
std::string previous= "";
std::string next= "";

result_line prev;
std::vector<result_line> save;
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
	if(previous == next)	++counter;
	else{
		prev.line=previous;
		prev.counter=counter;
		save.emplace_back(prev);
		counter = 1;
	}

	previous = line;
}
prev.line=previous;
prev.counter=counter;
save.emplace_back(prev);
return save;
}
