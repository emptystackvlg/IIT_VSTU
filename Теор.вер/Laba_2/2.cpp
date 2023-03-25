#include <iostream>
#include <stdio.h>
using namespace std;
void prob()
{
    float probs[100];
    cout << "Формула для события B - схема работает безотказно в течение времени T :" << "\n\n";
    cout << "B = ((!A1 + !A2) * !A3 * !A4) + (!A5 * !A6) " << "\n\n";
    cout << "Формула для расчета вероятности события B" << "\n\n";
    cout << "P(B) = ((1 - P(A1)) + (1 - P(A2)) * (1 - P(A3)) * (1 - P(A4))) + ((1- P(A5)) * (1 - P(A6)))" << "\n\n";
    system("pause");
    system("cls");
    for (int i = 0; i < 6; i++)
    {
        cout << "Введите вероятность отказа элемента № " << i + 1 << "\n> ";
        cin >> probs[i];
        cout << "\n";
    }
    
    float prob_of_b;
    prob_of_b = (((1 - probs [0]) + (1 - probs [1])) * (1 - probs [2]) * (1 - probs [3])) + ((1- probs [4]) * (1 - probs [5]));
    cout << "Вероятность события B = " << prob_of_b;


}



int main()
{
    setlocale(LC_ALL, "rus");
    prob();

}
