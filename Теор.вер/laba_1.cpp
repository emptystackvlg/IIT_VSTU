#include <iomanip>
#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
unsigned long long factorial(unsigned long long a)
{
	if (a == 1 || a == 0) return 1;
	else return a * factorial(a - 1);
}
unsigned long long combination(unsigned long long n, unsigned long long m) //сочетания
{	
	if (m == 0 || m == n) return 1;
	else return combination(n - 1, m - 1) * n / m;
}


unsigned long long allocate_repeat(unsigned long long n, unsigned long long m) // размещения с повторениями
{

	unsigned long long num_of_allocations = pow(n, m);
	return num_of_allocations;
}

unsigned long long permutation_repeat(unsigned long long n, int k , unsigned long long M[20]) //перестановки с повторениями
{
	unsigned long long up = factorial(n);
	unsigned long long result = 1;
	int max_mi = n;
	for (int i = 0; i < k; i++)
	{	
		cout << "Введите число m_" <<i+1<<"(<="<<max_mi<<")"<< "\n>";
		cin >> M[i];
		max_mi -= M[i];
	}
	for (int i = 0; i < k; i++)
	{
		result = up /= factorial(M[i]);
	}
	return result;
}
int main()
{	setlocale (LC_ALL,"Rus");
	int mode = 0;
	
	while (mode != 1 && mode != 2 && mode != 3)
	{
		system("cls");
		cout << "Выберите тип комбинаций:\n 1 - сочетания без повторений\n 2 - размещения с повторениями\n 3 - перестановки с повторениями\n>";
		cin >> mode;
		if (mode == 1)
		{
			system("cls");
			cout << "Выбраны сочетания без повторений" << endl;
			cout << "Формула для вычислений\nC_(n)^(m) = (n!)/(m!(n-m)!)"<<endl;
			unsigned long long n = 0;
			unsigned long long m = 0;
			cout << "\nВведите n \n>";
			cin >> n;
			cout << "\nВведите m (m <= " << n << ")\n>";
			cin >> m;
			cout  << "\nЧисло комбинаций: " << combination(n, m);
		}
		else if (mode == 2)
		{
			system("cls");
			cout << "Выбраны размещения с повторениями" << endl;
			cout << "Формула для вычислений\nA_(n)^(m)=n^(m)" << endl;
			unsigned long long n ;
			unsigned long long m ;
			unsigned long long max_n = sqrt(9223372036854775808);
			cout << "\nВведите n (n < " << max_n << ")\n>";
			cin >> n;
			unsigned long long max_m = log(9223372036854775808) /log(n);
			cout << "\nВведите m (m <= " << max_m << ")\n>";
			cin >> m;
			cout << "\nЧисло комбинаций: " << allocate_repeat(n, m);

		}
		else if (mode == 3)
		{
			system("cls");
			unsigned long long n;
			unsigned long long m;
			unsigned long long k;
			unsigned long long M[100];
			cout << "Выбраны перестановки с повторениями" << endl;
			cout << "Формула для вычислений\nP_n(m_(1),m_(2),...m_(k)) )= (n!)/(m_(1)!*m_(2)!...m_(k)!)" << endl;
			cout << "Введите число n\n>";
			cin >> n;
			cout << "Введите число k\n>";
			cin >> k;
			cout << "\nЧисло комбинаций: " << permutation_repeat(n,k,M);

		}
		else
		{
			cout << "Введено неверное значение"<<endl;
			system("pause");
		}

	}
	return 0;
}