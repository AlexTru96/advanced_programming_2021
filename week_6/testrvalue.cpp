#include <iostream>
class F{
	public:
		template<typename X>
		void test(X&& x);
		//std::cout<<x<<std::endl;
		//}

};


int main(){
int x=10;
F prueba;
prueba.test(x);
}
