#include <iostream>
#include <vector>
#include <cmath>

void print_primes(std::vector<bool>);

int main(){
	std::size_t max;
	std::cout<<"insert maximum number"<<std::endl;
	std::cin>>max;
	std::vector<bool> bool_primes(max+1,true);
	for (unsigned int i=2;i<std::sqrt(max+1);++i){
		if(bool_primes[i]){
		for(unsigned int j=i*i;j<max+1;j+=i){
			bool_primes[j]=false;		}
	}

}
print_primes(bool_primes);
}

void print_primes(std::vector<bool> bool_primes){
for(unsigned int i=2;i<bool_primes.size();++i){
	if(bool_primes[i])
	std::cout<<i<<" ";
}
std::cout<<std::endl;
}
