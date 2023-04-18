#include <iostream>
#include <math.h>
#include <iomanip>
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
    cout << "Выберите событие:\n 1) Pn(k = m)\n 2) Pn(k < m)\n 3) Pn(k => m)\n 4) Pn(m1 <= k <= m2)\n> ";
    cin >> mode;
    system("pause");
    system("cls");
    if (mode == 1 || mode == 2 || mode == 3)
    {
        cout << "Введите m\n> ";
        cin >> m;
    }
    if (mode == 1)
    {
        cout << "Формула для события Pn(k = m):\n\nPn(k=m) = C_(n)^(m) * p^m * q^(n-m)\n\n";
        prob = 0;
        prob = bernulli(p, n, m);
        cout << "Вероятность события Pn(k = m) равна : " << prob;
    }
    else if (mode == 2)
    {
        cout << "Формула для события Pn(k < m):\n\nPn(k<m) = сумма по i от 0 до m-1 (C_(n)^(i) * p^i * q^(n-i)\n\n") 
        prob = 0;
        for (int i = 0; i <= m-1; i++)
        {
            prob += bernulli(p, n, i);
        }
        cout << "Вероятность события Pn(k < m) равна : " << prob;
    }
    else if (mode == 3)
    {
        cout << "Формула для события Pn(k => m):\n\nPn(k<m) = Сумма по i от m до n {C_(n)^(i) * p^i * q^(n-i)}\n\n";
        prob = 0;
        for (int i = m; i <= n; i++)
        {
            prob += bernulli(p, n, i);
        }
        cout << "Вероятность события Pn(k => m) равна : " << prob;
    }
    else if (mode == 4)
    {
        cout << "Формула для события Pn(k => m):\n\nPn(k<m) = Сумма по i от m1 до m2 {C_(n)^(i) * p^i * q^(n-i)}\n\n";
        prob = 0;
        cout << "Введите m1 (m1<=" <<n-1<<")\n> ";
        cin >> m1;
        cout << "Введите m2 ("<< m1 << " <m2<="<< n << " )\n> ";
        cin >> m2;
        for (int i = m1; i <= m2; i++)
        {
            prob += bernulli(p, n, i);
        }
        cout << "Вероятность события Pn(m1 <= k <= m2) равна : " << setprecision (50)<<  prob;

    }

    return 0;
}
