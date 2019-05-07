#include <iostream>
#include <Windows.h>
#include "../LibArithmetic/LibArithmetic.h"
int main()
{
    HMODULE hLib = LoadLibrary("LibArithmetic.dll");
    int(*pFunction)(int, int) = nullptr; // указатель на функцию
    (FARPROC&)pFunction = GetProcAddress(hLib, "?sum@@YAHHH@Z"); // присвоение адреса функции из dll в дескриптор
    std:: cout << pFunction(2, 3) << std::endl;
    setlocale(LC_ALL, "russian");
    std::cout << "====================DYNAMIC LIBRARY====================" << std::endl;
    std::cout << "====================DYNAMIC LIBRARY====================" << std::endl;
    std::cout << "====================STATIC LIBRARY====================" << std::endl;
    std::cout << "====================STATIC LIBRARY====================" << std::endl;
	system("pause");
	return 0;
}