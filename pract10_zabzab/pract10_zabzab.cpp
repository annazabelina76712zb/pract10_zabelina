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
using namespace std;
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

DWORD WINAPI Thread4(LPVOID) {
    while (true) {
        volatile double sum = 0;
        for (int i = 0; i < 1000; i++)
        {
            sum += sin(i) * sqrt(i);
        }
        iter4++;
    }
    return 0;
}
int main()
{
    setlocale(LC_ALL, "rus");
    bool loaderStarted = false;
    HANDLE h1 = CreateThread(NULL, 0, Thread1, NULL, 0, NULL);
    HANDLE h2 = CreateThread(NULL, 0, Thread2, NULL, 0, NULL);
    HANDLE h3 = CreateThread(NULL, 0, Thread3, NULL, 0, NULL);
    HANDLE h4 = CreateThread(NULL, 0, Thread4, NULL, 0, NULL);

    SetThreadPriority(h1, THREAD_PRIORITY_LOWEST);
    SetThreadPriority(h2, THREAD_PRIORITY_BELOW_NORMAL);
    SetThreadPriority(h3, THREAD_PRIORITY_NORMAL);
  
    SetThreadAffinityMask(h1, 1) ;
    SetThreadAffinityMask(h2, 1);
    SetThreadAffinityMask(h3, 1);
      
     
    while (true)
    {  
        cout << "Управление: \n" << endl;
    cout << "1-2-3. Поменять приоритет первому потоку\n" << endl;
    cout << "4-5-6. Поменять приоритет второму потоку\n" << endl;
    cout << "7-8-9. Поменять приоритет третьему потоку\n" << endl;
    cout << "10. Вызвать нагрузчик \n" << endl;
    cout << "11. Завершить все работы \n" << endl;
        long long i1 = iter1; 
        long long i2 = iter2; 
        long long i3 = iter3; 
        long long i4 = iter4; 
       
            cout << "Нагрузчик: " << i4 << endl;
            cout << "Первый поток: " << i1 << endl;
            cout << "Второй поток: " << i2 << endl;
            cout << "Третий поток: " << i3 << endl;
        

        if (_kbhit())
        {
            int key;

            cin >> key;

            switch (key)
            {
            case 1: if (SetThreadPriority(h1, THREAD_PRIORITY_LOWEST))
            {
                cout << "LOWEST";

            }
                  break;
            case 2: if (SetThreadPriority(h1, THREAD_PRIORITY_BELOW_NORMAL))
            {
                cout << "BELOW_NORMAL";

            }
                  break;
            case 3: if (SetThreadPriority(h1, THREAD_PRIORITY_NORMAL))
            {
                cout << "NORMAL";

            }
                  break;
            case 4: if (SetThreadPriority(h2, THREAD_PRIORITY_LOWEST))
            {
                cout << "LOWEST";

            }
                  break;
            case 5: if (SetThreadPriority(h2, THREAD_PRIORITY_BELOW_NORMAL))
            {
                cout << "BELOW_NORMAL";

            }
                  break;
            case 6: if (SetThreadPriority(h2, THREAD_PRIORITY_NORMAL))
            {
                cout << "NORMAL";

            }
                  break;
            case 7: if (SetThreadPriority(h3, THREAD_PRIORITY_LOWEST))
            {
                cout << "LOWEST";

            }
                  break;
            case 8: if (SetThreadPriority(h3, THREAD_PRIORITY_BELOW_NORMAL))
            {
                cout << "BELOW_NORMAL";

            }
                  break;
            case 9: if (SetThreadPriority(h3, THREAD_PRIORITY_NORMAL))
            {
                cout << "NORMAL";

            }
                  break;
            case 10:
            {
                if (!loaderStarted)
                {
                    h4 = CreateThread(NULL, 0, Thread4, NULL, 0, NULL);
                    if (h4)
                    {
                        SetThreadPriority(h4, THREAD_PRIORITY_HIGHEST);
                        SetThreadAffinityMask(h4, 1);
                        loaderStarted = true;
                        cout << "Нагрузчик запущен!" << endl;
                    }
                }
                
            }
            break;
            case 11:
            {
                TerminateProcess(h1, 0);
                TerminateProcess(h2, 0);
                TerminateProcess(h3, 0);
                TerminateProcess(h4, 0);
                CloseHandle(h1);
                CloseHandle(h2);
                CloseHandle(h3);
                CloseHandle(h4);


            }
            break;
            } 

        }
        
        system("cls");

    }
   
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
