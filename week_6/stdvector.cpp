#include <iostream>
template<typename T>
class vector{

	T* data{nullptr};
	std::size_t _size{0};
	std::size_t _capacity{0};
	void check_capacity(){
		if(_size < _capacity ) return;
		// _size==_capacity
		reserve(_size*2);
	}
	template<typename X>
	void _push_back(X&& x){
		if(_size==0)
			reserve(8);
		else
			check_capacity();
		data[_size] = std::forward<X>(x);
		++_size;
	}

	void move_data_to(T* tmp){
		// std::copy(data,data+_size,tmp);
		for(std::size_t i{0}; i<_size ;++i)
			tmp[i]=std::move(data[i]);
		delete[] data;
		data= tmp;
	}
public:
	vector() = default;
	~vector(){
		if(data) delete [] data;
	}
	
	void push_back(const T& x){
		_push_back(x);

	}

	void reserve (std::size_t n){
		auto tmp = new T[n]; //may invoke default ctrs
		move_data_to(tmp);
		_capacity=n;
	}
	void push_back(T&& x){
		_push_back(std::move(x));
	}
	auto size() const {return _size;}
	auto capacity() const {return _capacity;}

};

int main(){
	vector<int> v;
	for(auto i=0; i<33;++i){
		v.push_back(i);
		std::cout<<v.capacity()<<", "<<v.size()<<std::endl;

	}


}
