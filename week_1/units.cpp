#include <iostream>
#include <string>

int main(){
int units;
double amount;
std::cout<<"Conversion options:\n"<<"1) inch \n2) lb \n3) mile \n4) gallon"<<std::endl;
std::cin>>units;
std::cout<<"Insert amount"<<std::endl;
std::cin>>amount;
switch(units){
	case 1:
		std::cout<<amount*2.54<<"cm"<<std::endl;
		break;
	case 2:
		std::cout<<amount*0.453592<<"kg"<<std::endl;
		break;
	case 3:
		std::cout<<amount*1.609<<"km"<<std::endl;
		break;
	case 4:
		std::cout<<amount*3.79<<"L"<<std::endl;
		break;
	default:
		std::cout<<"Idk wym, but u should always use SI units :)"<<std::endl;

}
}
