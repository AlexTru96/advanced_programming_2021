#include <fstream>
#include <algorithm>
#include <chrono>
#include "struct.h"


using namespace std::chrono;

int main(){

auto t0 = high_resolution_clock::now();

std::string word;
std::vector<std::string> strings_input;
std::map<std::string,unsigned int> save;
std::ifstream infile("LittleWomen.txt");
if(infile){
	while(infile>>word){
		filter(word);
		std::transform(word.begin(), word.end(), word.begin(), [](unsigned char c){ return std::tolower(c); });
		save[word]++;
	}

print(save);
infile.close();

auto t1 = high_resolution_clock::now();
auto elapsed = duration_cast<milliseconds>(t1-t0);
std::cout << "Elapsed time " << elapsed.count() << " [milliseconds]" << std::endl;
}
}

void print(std::map<std::string,unsigned int> strings_input){	
for (const auto& w : strings_input) {
	if(w.first.size()!=0) std::cout << w.first << " : " << w.second << "\n";
	}
std::cout <<std::endl;
}

void filter(std::string& word){
std::string chars = "_*[](),#!.!?;:\"";
for (char c: chars){
	word.erase(std::remove(word.begin(), word.end(), c), word.end());
	}
}
