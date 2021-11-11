#include <iostream>
unsigned int is_prime(unsigned int*,unsigned int);
void print_primes(unsigned int*);
int main(){

unsigned int primes [50]{2};
unsigned int* ptr = (primes+1);
for(unsigned int i=3; i<101;++i){
if(is_prime(primes,i)){
	*ptr=i;
	++ptr;	
}
}
print_primes(primes);
}

unsigned int is_prime(unsigned int* primes, unsigned int p){

unsigned int remainder;
unsigned int* ptr = primes;
while(*ptr!=0){
	
	remainder = p%(*ptr);
if(remainder!=0)
	++ptr;
else
	return 0;
}

return p;
}

void print_primes(unsigned int* primes){
unsigned int* ptr = primes;
while(*ptr != 0){

	std::cout<<*ptr<<" ";
	++ptr;

}
std::cout<<std::endl;
}
