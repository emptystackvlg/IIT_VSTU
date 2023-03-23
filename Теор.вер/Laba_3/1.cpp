#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
unsigned long long combination(int n, int m) //сочетания
{
    if (m == 0 || m == n) return 1;
    else return combination(n - 1, m - 1) * n / m;
}
float bernulli(float p, int n, int m)
{
    float q = 1 - p;
    unsigned long long comb = combination(n, m);
    p = pow(p, m);
    q = pow(q, n - m);
    float prob = comb * p * q;
    return prob;
}

int main()
{
    setlocale(LC_ALL, "rus");
    float p;
    int n;
    int m;
    int k;
    int m1;
    int m2;
    float prob = 0;
    int mode;
    cout << "Введите n\n> ";
    cin >> n;
    cout << "Введите p\n> ";
    cin >> p;
    cout << "Введите m\n> ";
    cin >> m;
    cout << "Выберите событие:\n 1) Pn(k = m)\n 2) Pn(k < m)\n 3) Pn(k => m)\n 4) Pn(m1 <= k <= m2)\n> ";
    cin >> mode;
    system("pause");
    system("cls");
    if (mode == 1)
    {
        prob = 0;
        prob = bernulli(p, n, m);
        cout << "Вероятность события Pn(k = m) равна : " << prob;
    }
    else if (mode == 2)
    {
        prob = 0;
        prob = bernulli(p, n, m);   
        prob = 1 - prob;
        cout << "Вероятность события Pn(k < m) равна : " << prob;
    }
    else if (mode == 3)
    {
        prob = 0;
        for (int i = m; i <= n; i++)     
        {
            prob += bernulli(p, n, i);
        }
        cout << "Вероятность события Pn(k => m) равна : " << prob;
    }
    else if (mode == 4)
    {
        prob = 0;
        cout << "Введите m1\n> ";
        cin >> m1;
        cout << "Введите m2\n> ";
        cin >> m2;
        for (int i = m1; i <=m2; i++)   
        {
            prob += bernulli(p, n, i);
        }
        cout << "Вероятность события Pn(m1 <= k <= m2) равна : "  << prob;

    }
        
    return 0;
}
