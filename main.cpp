#include <iostream>

template<typename T>
class Base{
	
public:
	Base(T a) : urmom(a){
		
		std::cout<<"Base class"<<std::endl;
		
		}
	T urmom;
	};

void semmi(){
	
	
}

int main(int argc, char **argv)
{
	Base<int> b(2);
	
}