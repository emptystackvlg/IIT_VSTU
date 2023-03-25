#include <iostream>
#include <math.h>
using namespace std;
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
    cout << "Формула для расчета :\nPn(m) = f(x0)/sqrt (n*p*q), где\n\n\tx0 = (m-n*p)/sqrt (n*p*q)\n\n\tf(xo) = (1/sqrt(2*pi)) * e^(-(x^2)/2)\n\n";
    int n, m;
    double p;
    cout << "Введите n (n >= 100)\n> ";
    cin >> n;
    cout << "Введите m\n> ";
    cin >> m;
    cout << "Введите p (0.1 <= p <= 0.9)\n> ";
    cin >> p;

    cout << "Вероятность равна : " << moivre_laplace(n, m, p);
    return 0;
}