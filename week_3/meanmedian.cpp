#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
void print(std::vector<double>);
double mean(std::vector<double>);
double median(std::vector<double>);

int main(){
	double temp;
	std::vector<double> temperatures;
	std::ifstream infile("temperatures.txt");
	if(infile){
		while(infile>>temp){
			temperatures.emplace_back(temp);
		}
		std::cout<<"The mean is: "<<mean(temperatures)<<" The median is: "<<median(temperatures)<<std::endl;}
	else
		std::cout<<"file doesnt exist"<<std::endl;
	infile.close();
}

double mean(std::vector<double> temperatures){

std::size_t _size = temperatures.size();
double sum{0};
for(unsigned int i=0;i<_size;++i)
	sum+=temperatures[i];
return sum/_size;
}


double median(std::vector<double> temperatures){

std::size_t _size = temperatures.size();
std::sort(temperatures.begin(), temperatures.end());
if(_size%2!=0) return temperatures[(_size+1)/2];
else return (temperatures[_size/2]+temperatures[(_size/2)+1])/2;
}
