#include <iostream>
#include <stdio.h>
using namespace std;
void prob()
{
    cout << " Пять стрелков производят по одному выстрелу в цель. Вероятности попадания в цель i-ым стрелком соответственно равны pi.\n Найти вероятность попадания в цель:\n a) только i-го стрелка\n b) только одного стрелка\n c) только двух стрелков\n d) не менее четырех стрелков\n";
    cout << "\n\nФормулы для вычисления вероятностей\n a) P(a) = ~pi*q1*q2*q3*q4, где ~pi - вероятность попадания i-го стрелка\n\n b,c,d,e) P (b,c,d,e) = (p1*x + q1) *  (p2*x + q2) *  (p3*x + q3) *  (p4*x + q4) *  (p5*x + q5)\n где \n P(b) = коэфф при x\n P(c) = коэфф при x^2\n P(d) = коэфф при x^4 + коэфф при x^5  \n P(e) = коэфф при x + коэфф при x^2 + коэфф при x^3 +коэфф при x^4 + коэфф при x^5" << "\n\n";
    float prob_of_hit[5];
    float prob_of_miss[5];
    for (int i = 0; i < 5; i++)
    {
        cout << "Введите вероятность попадания в цель стрелком № " << i + 1 << "\n> ";
        cin >> prob_of_hit[i];
        prob_of_miss[i] = 1 - prob_of_hit[i];
    }
    cout << "Введите номер стрелка для пункта a\n> ";
    int num = 0; 
    cin >> num;
    float four_miss = 1;
    for (int i = 0; i < 5; i++)
    {
        if (i != num - 1) four_miss *= prob_of_miss[i];
    }
    float i_hit = prob_of_hit[num - 1] * four_miss;

    float odds[6];
    float five = prob_of_hit[0] * prob_of_hit[1] * prob_of_hit[2] * prob_of_hit[3] * prob_of_hit[4];

    float four = 
        prob_of_hit[0] * prob_of_hit[1] * prob_of_hit[2] * prob_of_hit[3] * prob_of_miss[4] +
        prob_of_hit[0] * prob_of_hit[1] * prob_of_hit[2] * prob_of_hit[4] * prob_of_miss[3] +
        prob_of_hit[0] * prob_of_hit[1] * prob_of_hit[3] * prob_of_hit[4] * prob_of_miss[2] +
        prob_of_hit[0] * prob_of_hit[2] * prob_of_hit[3] * prob_of_hit[4] * prob_of_miss[1] +
        prob_of_hit[1] * prob_of_hit[2] * prob_of_hit[3] * prob_of_hit[4] * prob_of_miss[0];

    float three = 
        prob_of_hit[0] * prob_of_hit[1] * prob_of_hit[2] * prob_of_miss[3] * prob_of_miss[4] +
        prob_of_hit[0] * prob_of_hit[1] * prob_of_hit[3] * prob_of_miss[2] * prob_of_miss[4] +
        prob_of_hit[0] * prob_of_hit[1] * prob_of_hit[4] * prob_of_miss[2] * prob_of_miss[3] +
        prob_of_hit[0] * prob_of_hit[2] * prob_of_hit[3] * prob_of_miss[1] * prob_of_miss[4] +
        prob_of_hit[0] * prob_of_hit[2] * prob_of_hit[4] * prob_of_miss[1] * prob_of_miss[3] +
        prob_of_hit[0] * prob_of_hit[3] * prob_of_hit[4] * prob_of_miss[1] * prob_of_miss[2] +
        prob_of_hit[1] * prob_of_hit[2] * prob_of_hit[3] * prob_of_miss[0] * prob_of_miss[4] +
        prob_of_hit[1] * prob_of_hit[2] * prob_of_hit[4] * prob_of_miss[0] * prob_of_miss[3] + 
        prob_of_hit[1] * prob_of_hit[3] * prob_of_hit[4] * prob_of_miss[0] * prob_of_miss[2] + 
        prob_of_hit[2] * prob_of_hit[3] * prob_of_hit[4] * prob_of_miss[0] * prob_of_miss[1] ;

    float two =
        prob_of_hit[0] * prob_of_hit[1] * prob_of_miss[2] * prob_of_miss[3] * prob_of_miss[4] +
        prob_of_hit[0] * prob_of_hit[2] * prob_of_miss[1] * prob_of_miss[3] * prob_of_miss[4] +
        prob_of_hit[0] * prob_of_hit[3] * prob_of_miss[1] * prob_of_miss[2] * prob_of_miss[4] +
        prob_of_hit[0] * prob_of_hit[4] * prob_of_miss[1] * prob_of_miss[2] * prob_of_miss[3] +
        prob_of_hit[1] * prob_of_hit[2] * prob_of_miss[0] * prob_of_miss[3] * prob_of_miss[4] +
        prob_of_hit[1] * prob_of_hit[3] * prob_of_miss[0] * prob_of_miss[2] * prob_of_miss[4] +
        prob_of_hit[1] * prob_of_hit[4] * prob_of_miss[0] * prob_of_miss[2] * prob_of_miss[3] +
        prob_of_hit[2] * prob_of_hit[3] * prob_of_miss[0] * prob_of_miss[1] * prob_of_miss[4] +
        prob_of_hit[2] * prob_of_hit[4] * prob_of_miss[0] * prob_of_miss[1] * prob_of_miss[3] +
        prob_of_hit[3] * prob_of_hit[4] * prob_of_miss[0] * prob_of_miss[1] * prob_of_miss[2];
    float one =
        prob_of_hit[0] * prob_of_miss[1] * prob_of_miss[2] * prob_of_miss[3] * prob_of_miss[4] +
        prob_of_hit[1] * prob_of_miss[0] * prob_of_miss[2] * prob_of_miss[3] * prob_of_miss[4] +
        prob_of_hit[2] * prob_of_miss[0] * prob_of_miss[1] * prob_of_miss[3] * prob_of_miss[4] +
        prob_of_hit[3] * prob_of_miss[0] * prob_of_miss[1] * prob_of_miss[2] * prob_of_miss[4] +
        prob_of_hit[4] * prob_of_miss[0] * prob_of_miss[1] * prob_of_miss[2] * prob_of_miss[3];

    float zero = prob_of_miss[0] * prob_of_miss[1] * prob_of_miss[2] * prob_of_miss[3] * prob_of_miss[4];

    odds[0] = zero;
    odds[1] = one;
    odds[2] = two;
    odds[3] = three;
    odds[4] = four;
    odds[5] = five;
    cout << "a) " << i_hit << "\n\n";
    cout << "b) " << odds[1] << "\n\n";
    cout << "c) " << odds[2] << "\n\n";
    cout << "d) " << odds[4] + odds[5] << "\n\n";
    cout << "d) " << 1 - odds [0] << "\n\n";
   
}

int main()
{
    setlocale(LC_ALL, "rus");
    prob();
    return 0;
}
