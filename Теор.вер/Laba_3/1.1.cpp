#include <iostream>
#include <math.h>
using namespace std;

long double factorial(int f)
{
    long double result = 1;
    if (f == 0)
    {
        result = 1;
    }
    else
    {
        for (int i = 1; i <= f; i++)
        {
            result *= i;
        }
    }
    return result;
}


long double polinom(int n, int k)
{
    int mass_of_m[100];

    float mass_of_probs[100];
Input_m:
    int current_m = 0;
    int ex_n = n;
    for (int i = 0; i < k; i++)
    {
        cout << "Введите m" << i + 1 << "(m" << i + 1 << " <= " << ex_n << ")" << "\n> ";
        cin >> mass_of_m[i];
        current_m = mass_of_m[i];
        ex_n -= current_m;

    }
    if (ex_n < 0)
    {
        cout << "Ошибка, сумма mi > n." << endl;
        system("pause");
        system("cls");
        goto Input_m;
    }
    
Input_p:
    float summ_of_p = 0;
    for (int i = 0; i < k; i++)
    {
        cout << "Введите p" << i + 1 << "\n> ";
        cin >> mass_of_probs[i];
        summ_of_p += mass_of_probs[i];
    }
    if (summ_of_p != 1)
    {
        cout << "Ошибка, сумма вероятностей не равна 1  > n." << endl;
        system("pause");
        system("cls");
        goto Input_p;
    }
    long double prob = 1;
    long double up = factorial(n);
    long double down = 1;
    long double prod = 1;
    for (int i = 0; i < k; i++)
    {
        down *= factorial(mass_of_m[i]);
    }
    for (int i = 0; i < k; i++)
    {
        prod *= pow(mass_of_probs[i], mass_of_m[i]);
    }
    prob = (up / down) * prod;

    cout << "Вероятность равна : " << prob;
    return prob;
}

int main()
{
    setlocale(LC_ALL, "rus");
    cout << "Формула для расчета :\n P(n!/m1!m2!...mk!) * p1^m1 * p2^m2 * ... * pk^mk" << "\n\n";
    int n, k;
    cout << "Введите n\n> ";
    cin >> n;
    cout << "Введите k\n> ";
    cin >> k;
    polinom(n, k);
    return 0;
}
