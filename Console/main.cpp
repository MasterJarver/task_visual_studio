#include <iostream>
#include <Windows.h>
#include "LibArithmeticStatic.h"
int main()
{
    setlocale(LC_ALL, "russian");
    int a = 12;
    int b = 3;
    std::cout << "a = " << a << " b = " << b << std::endl;
    HMODULE hLib = LoadLibrary("LibArithmeticDynamic.dll");
    if(hLib != nullptr)
    {
        std::cout << "====================DYNAMIC LIBRARY====================" << std::endl;
        int(*pDllSum)(int, int) = nullptr; // указатель на 
        int(*pDllSub)(int, int) = nullptr; // указатель на функцию
        int(*pDllMul)(int, int) = nullptr; // указатель на функцию
        int(*pDllDivide)(int, int) = nullptr; // указатель на функцию
        (FARPROC&)pDllSum = GetProcAddress(hLib, "?sum@@YAHHH@Z"); // присвоение адреса функции из dll в
        if(pDllSum != nullptr)
        {
            std::cout << "sum: " << pDllSum(12, 3) << std::endl;
        }
        (FARPROC&)pDllSub = GetProcAddress(hLib, "?sub@@YAHHH@Z"); // присвоение адреса функции из dll в
        if(pDllSub != nullptr)
        {
            std::cout << "sub: " << pDllSub(12, 3) << std::endl;
        }
        (FARPROC&)pDllMul = GetProcAddress(hLib, "?mul@@YAHHH@Z"); // присвоение адреса функции из dll в
        if(pDllMul != nullptr)
        {
            std::cout << "mul: " << pDllMul(12, 3) << std::endl;
        }
        (FARPROC&)pDllDivide = GetProcAddress(hLib, "?divide@@YAHHH@Z"); // присвоение адреса функции из dll в
        if(pDllDivide != nullptr)
        {
            std::cout << "div: " << pDllDivide(12, 3) << std::endl;
        }
        std::cout << "====================DYNAMIC LIBRARY====================" << std::endl;
    }
    std::cout << "====================STATIC LIBRARY====================" << std::endl;
    std::cout << "sum: " << sum(a, b) << std::endl;
    std::cout << "sub: " << sub(a, b) << std::endl;
    std::cout << "mul: " << mul(a, b) << std::endl;
    std::cout << "div: " << divide(a, b) << std::endl;
    std::cout << "====================STATIC LIBRARY====================" << std::endl;
	system("pause");
	return 0;
}