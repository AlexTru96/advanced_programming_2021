#include <iostream>
#include <string>

int main(){

std::string line = "";
std::string result = "";
unsigned int max_char;
std::cout<<"insert maximum number of chars per line (words wont be cut if exceeds)"<<std::endl;
if(std::cin>>max_char){
for(std::string line;std::getline(std::cin,line);){
	unsigned int _size = line.size();
	if(_size > max_char){
		unsigned int counter=0;
		unsigned int pos_space=0;
		while(counter<_size){
			if(line.substr(counter,max_char).rfind(" ")<_size){
				pos_space =line.substr(counter,max_char).rfind(" ");
				result.append(line.substr(counter,++pos_space));
				result.append("\n");
				counter+=pos_space;}
			else{
				result.append(line.substr(counter,max_char));
				counter+=max_char;}	
		}
		result.append("\n");
	}
	else{
		result.append(line);
		result.append("\n");}
}

std::cout<<"\n **Here it is the formatted version**"<<std::endl;
std::cout<<result<<std::endl;
}
else
	std::cout<<"uh wrong input"<<std::endl;
}
