#include <iostream>

enum class months { jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec };


class DATE{
int _day, _year;
months _month;
void add_day(){
	++_day;
}

unsigned int check_month();

void add_month(){
	_month = static_cast<months>(static_cast<int>(_month)+1);
}

void add_year(){
	++_year;
}

bool is_leap(){
	if((_year%4==0 && !(_year%100==0))||_year%400==0) return 1;
	else return 0;

}
	public:
	DATE():_day{1},_month{months::jan}, _year{1900} {}
	DATE(int day, months month, int year):
		_day{day},_month{month},_year{year} {}

	int day() const{
	return _day;
	}
	months month() const{
	return _month;
	}
	int year() const{
	return _year;
	}
	DATE add_days(const int n);
};

std::ostream& operator<<(std::ostream& os, const DATE& d){
os<<d.day()<<"/"<< static_cast<int>(d.month())<<"/"<<d.year()<<std::endl;
return os;
}

bool operator==(const DATE& lhs, const DATE& rhs){
return (lhs.day()==rhs.day()&&lhs.month()==rhs.month()&&lhs.year()==rhs.year());
}

DATE initialize(int&);

int main(){
	int n_days{0};
	DATE actual_date = initialize(n_days);
	if(n_days<=0) {std::cout<<"Insert a correct number\n"; return 1;}

	DATE modified_date= actual_date.add_days(n_days);
	if(actual_date==modified_date) {std::cout<<"NOT VALID DATE\n"; return 2;}
	std::cout<<"The date you insert: "<<actual_date<<"The result date: "<<modified_date;
}

DATE initialize(int& n_days){
	int A_DAY,m,A_YEAR;
	months A_MONTH;

	std::cout<<"Insert date pls \n"<<"day: "; std::cin>>A_DAY;
	std::cout<<"\nmonth: "; std::cin>>m;
	A_MONTH = static_cast<months>(m);
	std::cout<<"\nyear: "; std::cin>>A_YEAR;
	std::cout<<"\nnumbers of days to add: "; std::cin>>n_days;
	DATE actual_date{A_DAY,A_MONTH,A_YEAR};

	return actual_date;
}

unsigned int DATE::check_month() {
months m = _month;
switch (m) {
	case months::jan: case months::mar: case months::may: case months::jul: case months::aug: case months::oct:
		return 1;
		break;
	case months::apr: case months::jun: case months::sep: case months::nov:
      		return 2;
		break;
	case months::feb:
      		return 3;
		break;
	case months::dec:
      		return 4;
		break;
    	default:
		return 0;
      	break;
  }
}

DATE DATE::add_days(const int n){
DATE return_date = *this;
for(unsigned int i=0; i<n; ++i){
	if(return_date._day<28 && return_date.check_month()){
		return_date.add_day();
	}
	else{
		auto option = return_date.check_month();
		switch (option) {
			case 1: 
				if(return_date._day<31) return_date.add_day();
				else if(return_date._day==31) {return_date.add_month(); return_date._day=1;}
			       	break;
			case 2: 
				if(return_date._day<30) return_date.add_day();
				else if(return_date._day==30) {return_date.add_month(); return_date._day=1;} 
				break;
			case 3: 
				if(!return_date.is_leap()&&return_date._day==28) {return_date.add_month();return_date._day=1;}
				else if(return_date._day==28) return_date.add_day();
				else if(return_date.is_leap()&&return_date._day==29) {return_date.add_month();return_date._day=1;}
				break;
			case 4:	
				if(return_date._day<31) return_date.add_day();
				else if(return_date._day==31) {return_date._month=months::jan; return_date.add_year();}
			       	break;

		}
		
	}
}
return return_date;
}
