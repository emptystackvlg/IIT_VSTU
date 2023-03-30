#include <iostream>
#include <stdio.h>
using namespace std;
void prob()
{
	float probs[100];
	cout << "Схема :" << "\n\n";
	cout << "                   ---------------|   2   |---------------" << endl;
	cout << "                 |                                        |" << endl;
	cout << "o---|   1   |----|                                        |----|   3   |---o" << endl;
	cout << "                 |                                        |" << endl;
	cout << "                   ---|   4   |---|   5   |---|   6   |---" << endl;
	cout << "\n\nФормула для события B-схема работает безотказно в течение времени T :" << "\n\n";
	cout << "B = !A1 * ((!A2 + (!A4 * !A5 * !A6)) - !A2 * A4 * A5 * A6) * !A3" << "\n\n";
	cout << "Формула для расчета вероятности события B" << "\n\n";
	cout << "P(B) = (1 -P(A1)) * ((1-P(A2)) + ((1-P(A4)) * (1-P(A5)) * (1-P(A6))) - ((1-P(A2)) * ((1-P(A4)) * (1-P(A5)) * (1-P(A6)) * (1-P(A3))" << "\n\n";
	for (int i = 0; i < 6; i++)
	{
		cout << "Введите вероятность отказа элемента № " << i + 1 << "\n> ";
		cin >> probs[i];
		cout << "\n";
	}
	float prob_of_b;
	float minus = (1 - probs[1]) * (1 - probs[3]) * (1 - probs[4]) * (1 - probs[5]);
	prob_of_b = (1 - probs[0]) * ((1 - probs[1]) + ((1 - probs[3]) * (1 - probs[4]) * (1 - probs[5])) - minus) * (1 - probs[2]);
	cout << "Вероятность события B = " << prob_of_b << "\n\n";
	system("pause");



}



int main()
{
	setlocale(LC_ALL, "rus");
	prob();

}