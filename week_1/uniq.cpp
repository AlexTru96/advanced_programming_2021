#include <iostream>
#include <string>
int main(){

std::string line = "";
std::string previous= "" ;
std::string next= "";
std::string save= "";
bool first= true;
int counter=0;
//it is better than while due to local scope
for(std::string line; std::getline(std::cin,line);){
next= line;

if(first){
	++counter;
	first= false;
	previous=line;
	continue;
}

if(previous == next)
	++counter;
else{
	save.append(previous);
	save.append(" ");
	save.append(std::to_string(counter));
	save.append("\n");	
	counter = 1;
}	
previous = line;
}
	save.append(previous);
	save.append(" ");
	save.append(std::to_string(counter));
	std::cout<<save<<std::endl;
}
