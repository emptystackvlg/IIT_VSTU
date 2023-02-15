#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

unsigned long long factorial(unsigned long long i)
{
	if (i == 1 || i == 0) return 1;
	else return i * factorial(i - 1);
}




unsigned long long combination(unsigned long long n, unsigned long long m)
{
	if (m == 0 || m == n) return 1;
	else return combination(n - 1, m - 1) * n / m;
}


unsigned long long allocate_repeat(unsigned long long n, unsigned long long m)
{

	unsigned long long num_of_allocations = pow(n, m);
	return num_of_allocations;
}
void main()
{
	setlocale(LC_ALL, "RUS");
	cout << allocate_repeat(33, 9);

}