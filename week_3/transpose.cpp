#include <iostream>
#include <ostream>
#include <utility>
#include <vector>

unsigned int rows,columns;
void print(std::vector<double>,unsigned int,unsigned int);
void transpose(std::vector<double>&,unsigned int&);
std::vector<double> transpose(std::vector<double>& ,unsigned int&, unsigned int&);
std::vector<double> initialize(unsigned int, unsigned int);
int main(){

	std::cout<<"please define size of matrix (rows, columns)\n";
	std::cin>>rows;
	std::cin>>columns;
	unsigned int _size= rows*columns;
	std::vector<double> matrix(_size);
        matrix	= initialize(rows,columns);
	std::cout<<"this is your matrix\n";
	print(matrix,rows,columns);
	if(rows==columns)
		transpose(matrix,rows);
	else
		matrix= transpose(matrix,rows,columns);
std::cout<<"here it comes its transpose\n";
print(matrix,rows,columns);
}

void print(std::vector<double> m ,unsigned int rows,unsigned int columns){

for (unsigned int i=0;i<rows;i++){
	for (unsigned int j=0;j<columns;j++){
		std::cout<<m[i*columns+j]<<" ";	
			}
	std::cout<<std::endl;
	}
}

std::vector<double> initialize(unsigned int rows,unsigned int columns){
	std::vector<double> m(rows*columns);
for (unsigned int i=0;i<rows;++i){
	for (unsigned int j=0;j<columns;++j){
		std::cout<<"insert value ["<<i+1<<"] ["<<j+1<<"]  ";
		std::cin>>m[i*columns+j];	
			}
}
return m;
}

void transpose(std::vector<double>& matrix, unsigned int& rows){
for (unsigned int i = 0; i < rows; ++i) {
        for (unsigned int j = 0; j <i ; ++j) {
        	std::swap(matrix[j*rows+i], matrix[i*rows+j]);
        }
   }
}

std::vector<double> transpose(std::vector<double>& matrix, unsigned int& rows, unsigned int& columns){
	std::vector<double> transpose_m(rows*columns);
for (unsigned int i = 0; i < columns; ++i) {
        for (unsigned int j = 0; j < rows ; ++j) {
        	transpose_m[i*rows+j]=matrix[j*columns+i];
        }
   }
std::swap(rows,columns);
return transpose_m;
}
