#include <iostream>
#include <stdio.h>
using namespace std;
void prob()
{
    float probs[100];
    cout << "Схема:" << "\n\n";
    cout << "       -|   2   |- " << endl;
    cout << "      |           |" << endl;
    cout << "     -             -|   3   |---|   4   |---" << endl;
    cout << "    | |           |                         |" << endl;
    cout << "о---|  -|   1   |-                           ---o" << endl;
    cout << "    |                                       |" << endl;
    cout << "     ---|   5   |---|   6   |---------------" << endl;
    cout << "\n\nФормула для события B - схема работает безотказно в течение времени T :" << "\n\n";
    cout << "B = ((!A1 + !A2) * !A3 * !A4) + (!A5 * !A6) " << "\n\n";
    cout << "Формула для расчета вероятности события B" << "\n\n";
    cout << "P(B) = ((1 - P(A1)) + (1 - P(A2)) * (1 - P(A3)) * (1 - P(A4))) + ((1- P(A5)) * (1 - P(A6)))" << "\n\n";
    
    for (int i = 0; i < 6; i++)
    {
        cout << "Введите вероятность отказа элемента № " << i + 1 << "\n> ";
        cin >> probs[i];
        cout << "\n";
    }

    float prob_of_b;
    prob_of_b = (((1 - probs[0]) + (1 - probs[1])) * (1 - probs[2]) * (1 - probs[3])) + ((1 - probs[4]) * (1 - probs[5]));
    cout << "Вероятность события B = " << prob_of_b << "\n\n";
    system("pause");

}



int main()
{
    setlocale(LC_ALL, "rus");
    prob();

}
