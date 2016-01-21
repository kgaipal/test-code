#include <iostream>

#include "../fraction.h"

int main()
{
	Fraction f1(1,2), f2(1,2);

	(f1+f2).display();
	std::cout << std::endl;

	(f1-f2).display();
	std::cout << std::endl;

	(f1*f2).display();
	std::cout << std::endl;

	(f1/f2).display();
	std::cout << std::endl;
       
	std::cout << "f1 == f2 ?" << (f1==f2) << std::endl;
	std::cout << "f1 != f2 ?" << (f1!=f2) << std::endl;
}
