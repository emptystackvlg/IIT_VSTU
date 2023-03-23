#include <iostream>
#include <stdio.h>
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
    for (int i = 0; i < k; i++)
    {
        cout << "Введите m" << i + 1 << "\n> ";
        cin >> mass_of_m[i];
    }
    for (int i = 0; i < k; i++)
    {
        cout << "Введите p" << i + 1 << "\n> ";
        cin >> mass_of_probs[i];
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
        prod *= pow(mass_of_probs[i],mass_of_m[i]);
    }
    prob = (up / down) * prod;
    return prob;
}

int main()
{
    setlocale(LC_ALL, "rus");
    int n, k;
    cout << "Введите n\n> ";
    cin >> n;
    cout << "Введите k\n> ";
    cin >> k;
    cout << "Вероятность равна : " << polinom(n, k);
    return 0;
}
