/*
 * Для чисел Фибоначчи известны некоторые тождества:
 * Докажите эти тождества и напишите программу для вычисления ЧФ с помощью разделяй и властвуй.
 */
#include <iostream>

using namespace std;

int n;
int find_fib(int m)
{
    if (m == 1)
        return 1;
    if (m == 2)
        return 1;
    if (m % 5 == 0)
    {
        int x = find_fib(m / 5);
        if (m % 2 == 0)
            return 25 * x * x * x * x * x + 25 * x * x * x + 5 * x;
        else
            return 25 * x * x * x * x * x - 25 * x * x * x + 5 * x;
    }
    else if (m % 2 == 0)
    {
        int x = find_fib(m / 2 + 1), y = find_fib(m / 2 - 1);
        return x * x - y * y;
    }
    else
    {
        m--;
        int x = find_fib(m / 2), y = find_fib(m / 2 + 1);
        return x * x + y * y;
    }
}

int main() {
    cin >> n;
    cout << find_fib(n);
    return 0;
}