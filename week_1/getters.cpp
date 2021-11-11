#include <iostream>
#include<limits>
#include <string>

void get_int();
void get_double();
int main (){
	int i;
	std::cout<<"insert option (1) : get_int				 (2) : get_double"<<std::endl;
	std::cin >> i;
	switch(i){
		case 1:
			get_int();
			break;
	
		case 2:
			get_double();
			break;
	
		default:
		std::cout<<"option does not exist, bye then"<<std::endl;
	}
}
void get_int(){

	int i;
	bool trap=false;

	while(std::cin >> i){

		if(std::cin.get()==10){
			std::cout<<"Noice, the int number you typed is "<<i<<std::endl;
		return;}
		else{
			trap = true;
			break;
		}

	}

	if(std::cin.fail()||trap){
		std::cout << "please type an integer int (4 bytes)"<< std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
		get_int();
	}

}

void get_double(){

	double num;
	bool trap=false;

	while(std::cin >> num){

		if(std::cin.get()==10){
			std::cout<<"Noice, the double number you typed is "<<num<<std::endl;
		return;}
		else{
			trap = true;
			break;
		}

	}

	if(std::cin.fail()||trap){
		std::cout << "please type a double int (8 bytes)"<< std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
		get_double();
	}

}
