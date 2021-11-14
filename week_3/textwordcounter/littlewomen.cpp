#include <fstream>
#include <algorithm>
#include <chrono>
#include "struct.h"


using namespace std::chrono;

int main(){

auto t0 = high_resolution_clock::now();

std::string word;
std::vector<std::string> strings_input;
std::ifstream infile("LittleWomen.txt");
if(infile){
	while(infile>>word){
		filter(word);
		std::transform(word.begin(), word.end(), word.begin(), [](unsigned char c){ return std::tolower(c); });
		strings_input.emplace_back(word);}

std::sort(strings_input.begin(), strings_input.end());
std::vector<result_line> result = uniq(strings_input);
//std::sort(result.begin(),result.end());
print(result);
infile.close();

auto t1 = high_resolution_clock::now();
auto elapsed = duration_cast<milliseconds>(t1-t0);
std::cout << "Elapsed " << elapsed.count() << " [milliseconds]" << std::endl;
}
}

bool operator<(const result_line & lhs, const result_line & rhs){
return lhs.counter < rhs.counter;
}

void print(std::vector<result_line> strings_input){
std::size_t _size = strings_input.size();
for(unsigned int i=0;i<_size;++i)
	if(strings_input[i].line.size()!=0){
		std::cout<<strings_input[i].line;
		std::cout<<" "<<strings_input[i].counter<<std::endl;}
}

void filter(std::string& word){
std::string chars = "_*[](),#!.!?;:\"";
for (char c: chars){
	word.erase(std::remove(word.begin(), word.end(), c), word.end());}
}
