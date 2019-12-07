/*
 Напишите программу, находящую k-ую порядковую статистику. Программа должна работать за время O(n) в среднем.
 */
#include <iostream>
#include <vector>

using namespace std;

int n, k;
vector <int> vec;

void quick_sort(int l, int r, vector <int> &a)
{
    int l0 = l, r0 = r;
    int m = (l + r) / 2;
    while (l <= r)
    {
        while (a[l] < a[m])
            l++;
        while (a[r] > a[m])
            r--;
        if (l <= r)
            swap (a[l++], a[r--]);
    }
    if (r == k)
    {
        cout << a[r];
    }
    if (l0 < r)
        quick_sort(l0, r, a);
    if (r0 > l)
        quick_sort(l, r0, a);
}

int main()
{
    cin >> n >> k;
    vec.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }
    quick_sort(0, n, vec);
    return 0;
}