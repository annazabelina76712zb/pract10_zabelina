// pract10_zabzab.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <locale>
#include <conio.h>     
#include <windows.h>
volatile long long iter1 = 0;
volatile long long iter2 = 0;
volatile long long iter3 = 0;
volatile long long iter4 = 0;
DWORD WINAPI Thread1(LPVOID) {
    while (true) {
        volatile long long x = 0;
        x++; 
        iter1++;
    }
    return 0;
}
DWORD WINAPI Thread2(LPVOID) {
    volatile long long a = 0, b = 1;
    while (true) {
        long long c = a + b;
        a = b;
        b = c;
        iter2++;
    }
    return 0;
}

DWORD WINAPI Thread3(LPVOID) {
    volatile long long n = 1, fact = 1;
    while (true) {
        fact *= n;
        n++;
        iter3++;
    }
    return 0;
}
int main()
{
    HANDLE h1 = CreateThread(NULL, 0, Thread1, NULL, 0, NULL);
    HANDLE h2 = CreateThread(NULL, 0, Thread2, NULL, 0, NULL);
    HANDLE h3 = CreateThread(NULL, 0, Thread3, NULL, 0, NULL);

    SetThreadPriority(h1, THREAD_PRIORITY_LOWEST);
    SetThreadPriority(h2, THREAD_PRIORITY_BELOW_NORMAL);
    SetThreadPriority(h3, THREAD_PRIORITY_NORMAL);
   
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
