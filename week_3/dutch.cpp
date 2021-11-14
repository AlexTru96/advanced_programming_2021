#include <vector>
#include <iostream>
#include <stdlib.h>

void initialize(std::vector<int>&);
void dutchflag(std::vector<int>&, unsigned int);
void print(std::vector<int>);
int main(){
	srand (time(NULL));
	std::size_t _size;
	unsigned int pivot;
	std::cout<<"Insert size of vector"<<std::endl;
	std::cin>>_size;
	std::cout<<"Insert pivot number"<<std::endl;
	std::cin>>pivot;
	std::vector<int> dutch(_size);
	initialize(dutch);
	std::cout<<"This is your vector"<<std::endl;
	print(dutch);
	dutchflag(dutch,pivot);
	std::cout<<"This is the 'ordered' vector"<<std::endl;
	print(dutch);

}

void initialize(std::vector<int>& dutch){
std::size_t _size = dutch.size();
for(unsigned int i=0;i<_size;++i)
	dutch[i] = rand() % 10;  
}

void print(std::vector<int> dutch){

std::size_t _size = dutch.size();
for(unsigned int i=0;i<_size;++i)
	std::cout<<dutch[i]<<" ";  
std::cout<<std::endl;
}

void dutchflag(std::vector<int>& dutch, unsigned int pivot){
std::size_t _size=dutch.size();
unsigned int eraser= 0;
unsigned int i=0;
for(unsigned int j=0;j<_size;++j){
	if(dutch[i]>pivot){
		dutch.push_back(dutch[i]);
		--i;
		dutch.erase(dutch.begin()+eraser);
	}
	else if(dutch[i]==pivot){
		++eraser;
	}
	else{
		dutch.insert(dutch.begin(),dutch[i]);
		++eraser;
		dutch.erase(dutch.begin()+eraser);
	}
	++i;
}
}
