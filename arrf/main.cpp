/*
 * Напишите программу на основе разделяй и властвуй позволяющую эффективно проверять принадлежность пары значений массиву.
 * Например, пара (2,3) принадлежит массиву [1,2,3,5,7,11,13,17], а пара (3,4) - нет.
 * Можно считать, что количество запросов многократно превышает размер массива.  В комментариях напишите, почему перебор - эффективное
 */
#include <iostream>
#include <vector>

using namespace std;

int n, x, y;
vector <int> vec;
void merge(int l, int m, int r)
{
    int i = l, j = m;
    vector <int> res;
    while (i < m && j < r)
    {
        if (vec[i] < vec[j])
        {
            res.push_back(vec[i]);
            i++;
        }
        else
        {
            res.push_back(vec[j]);
            j++;
        }
    }
    while (j < r)
    {
        res.push_back(vec[j]);
        j++;
    }
    while (i < m)
    {
        res.push_back(vec[i]);
        i++;
    }
    for (int k = l; k < r; k++)
    {
        vec[k] = res[k - l];
    }
}
void merge_sort(int l, int r)
{
    if (r - l <= 1)
        return;
    int m = (l + r) / 2;
    merge_sort(l, m);
    merge_sort(m, r);
    merge(l, m, r);
}

int main() {
    cin >> x >> y;
    while (cin >> n)
    {
        vec.push_back(n);
    }
    n = int(vec.size());
    merge_sort(0, n);
    int l = -1, r = n, m;
    while (r - l > 1)
    {
        m = (r + l) / 2;
        if (x > vec[m])
        {
            l = m;
        }
        else
        {
            r = m;
        }
    }
    if (vec[r] == x)
    {
        l = -1;
        r = n;
        while (r - l > 1)
        {
            m = (r + l) / 2;
            if (y > vec[m])
            {
                l = m;
            }
            else
            {
                r = m;
            }
        }
        if (vec[r] == y)
        {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}
//Программа эффективна т.к использует частичный перебор с помощью разделяй и властвуй