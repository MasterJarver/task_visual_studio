#include <iostream>
#include "../LibArithmetic/LibArithmetic.h"
int main()
{
	setlocale(LC_ALL, "russian");
	std::cout << "====================DYNAMIC LIBRARY====================" << std::endl;
    std::cout << sum(2, 3) << std::endl;
    std::cout << "====================DYNAMIC LIBRARY====================" << std::endl;
    std::cout << "====================STATIC LIBRARY====================" << std::endl;
    std::cout << "====================STATIC LIBRARY====================" << std::endl;
	system("pause");
	return 0;
}