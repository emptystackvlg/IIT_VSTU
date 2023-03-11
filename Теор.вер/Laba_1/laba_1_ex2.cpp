#include <iostream>
#include <math.h>
#include <iomanip>


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
long double allocate(int n, int m)
{
	long double up = factorial(n);  //числитель
	long double down = factorial(n - m); //знаменатель
	long double num_of_allocates = up / down;
	return num_of_allocates;
}
int main()
{
	setlocale(LC_ALL,"Rus");
	int m , n ;           //m - кол-во телеграм, n - кол-во каналов связи
	cout << "Используемая формула : P (A) = n!/((n-m)!/n^m).\n\n";
	cout << "Введите m (0 < m <= 22)\n>";
	cin >> m;
	cout << "Введите n ( n > " << m << ")" << "\n>";
	cin >> n;
	double prob;		//вероятность 
	long double sum_of_all = pow(n, m);
	prob = allocate(n, m) / sum_of_all;
	cout << "Вероятность равна : "<<setprecision(100)<<prob;
}