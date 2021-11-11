#include <cstddef>
#include <iostream>
#include<string>
template<typename T>
T* initialize(const std::size_t size);
template<typename T>
void print_array(T*, const std::size_t size);
template<typename T>
void reverse(T*, std::size_t size);

int main(){
	std::size_t size;
	std::cout<<"Insert size of int array"<<std::endl;
	std::cin>>size;
	int* vector = initialize<int>(size);
//	double* vector2 = initialize<double>(size);
	print_array(vector,size);
//	print_array(vector2,size);
	reverse(vector,size);
	print_array(vector,size);
	delete [] vector;
       	//delete [] vector2;


}

template<typename T>
T* initialize(const std::size_t size){
T* array{new T[size]};
std::cout<<"insert values:"<<std::endl;
for(T* ptr = array;ptr<(array+size);++ptr){
	std::cin>>*ptr;
}
return array;
}

template<typename T>
void print_array(T* array, const std::size_t size){
	
for(T* ptr = array;ptr<(array+size); ++ptr){
	std::cout<<*ptr<< " ";
}
std::cout<<std::endl;
}


template<typename T>
void reverse(T* array, std::size_t size){
	std::cout<<"Reversing"<<std::endl;
for(int i= 0;i<(size/2); ++i){
	T tmp = *(array+i);
	*(array+i) = *(array+size-i-1);
	*(array+size-i-1) = tmp;
}
std::cout<<std::endl;
}
