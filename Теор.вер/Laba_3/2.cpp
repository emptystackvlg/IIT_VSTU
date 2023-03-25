#include <iostream>
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
double moivre_laplace(int n, int m, double p)
{
    double q = 1 - p;
    double x0 = (m - n * p) / sqrt(n * p * q);
    double fi_x0 = (1 / sqrt(2 * 3.14)) * exp(-pow(x0, 2) / 2);
    double prob = fi_x0 / sqrt(n * p * q);
    return prob;

}


int main()
{
    setlocale(LC_ALL, "rus");
    cout << "Формула для расчета вероятности с использованием локальной теоремы Муавра - Лапласа :\nPn(m) = f(x0)/sqrt (n*p*q), где\n\n\tx0 = (m-n*p)/sqrt (n*p*q)\n\n\tf(xo) = (1/sqrt(2*pi)) * e^(-(x^2)/2)\n\n";
    cout << "Формула Бернулли Pn(m) = C_(n)^(m) * p^m * q^(n-m)\n\n";
    int n, m;
    double p;
    cout << "Введите n (n >= 100)\n> ";
    cin >> n;
    cout << "Введите m\n> ";
    cin >> m;
    cout << "Введите p (0.1 <= p <= 0.9)\n> ";
    cin >> p;

    cout << "Вероятность, вычисленная c использованием локльной теоремы Муавра - Лапласа равна : " << moivre_laplace(n, m, p)<< "\n\n";
    cout << "Вероятность, вычисленная по формуле Берунулли равна : " << bernulli(p, n, m) << "\n\n";
    return 0;
}