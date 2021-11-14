#include "definitions.h"

int main(){
std::vector<std::string> strings_input;
std::cout<<"Write whatever you want, to exit (CTRL+D)"<<std::endl;
for(std::string line; std::getline(std::cin,line);){
	strings_input.emplace_back(line);
}

std::sort(strings_input.begin(), strings_input.end());
std::vector<std::string> result = uniq(strings_input);
std::cout<<"\nList without repetitions"<<std::endl;
print(result);
}

void print(std::vector<std::string> strings_input){
std::size_t _size = strings_input.size();
for(unsigned int i=0;i<_size;++i)
	std::cout<<strings_input[i]<<std::endl;
}
