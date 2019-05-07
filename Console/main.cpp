#include <iostream>
#include <Windows.h>
// #include "../LibArithmetic/LibArithmetic.h"
int main()
{
    int a = 12;
    int b = 3;
    HMODULE hLib = LoadLibrary("LibArithmetic.dll");
    int(*pDllSum)(int, int) = nullptr; // указатель на функцию
    (FARPROC&)pDllSum = GetProcAddress(hLib, "?sum@@YAHHH@Z"); // присвоение адреса функции из dll в
    
    int(*pDllSub)(int, int) = nullptr; // указатель на функцию
    (FARPROC&)pDllSub = GetProcAddress(hLib, "?sub@@YAHHH@Z"); // присвоение адреса функции из dll в
    
    int(*pDllMul)(int, int) = nullptr; // указатель на функцию
    (FARPROC&)pDllMul = GetProcAddress(hLib, "?mul@@YAHHH@Z"); // присвоение адреса функции из dll в
    
    int(*pDllDivide)(int, int) = nullptr; // указатель на функцию
    (FARPROC&)pDllDivide = GetProcAddress(hLib, "?divide@@YAHHH@Z"); // присвоение адреса функции из dll в
    
    setlocale(LC_ALL, "russian");
    std::cout << "a = " << a << " b = " << b << std::endl;
    std::cout << "====================DYNAMIC LIBRARY====================" << std::endl;
    std::cout << "sum: " << pDllSum(12, 3) << std::endl;
    std::cout << "sub: " << pDllSub(12, 3) << std::endl;
    std::cout << "mul: " << pDllMul(12, 3) << std::endl;
    std::cout << "div: " << pDllDivide(12, 3) << std::endl;
    std::cout << "====================DYNAMIC LIBRARY====================" << std::endl;
    std::cout << "====================STATIC LIBRARY====================" << std::endl;
    std::cout << "====================STATIC LIBRARY====================" << std::endl;
	system("pause");
	return 0;
}