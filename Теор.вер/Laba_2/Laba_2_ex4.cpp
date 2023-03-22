#include <iostream>
#include <math.h>
#include <iomanip>


using namespace std;

float main_prob()
{
	int num_of_events;
	cout << "Введите число событий, образующих полную группу\n> ";
	cin >> num_of_events;
	float probs_of_hyps[100];
	float cond_probs[100];
	float sum_of_probs_of_hyps = 0;
	
	while (sum_of_probs_of_hyps !=1)
	{
		sum_of_probs_of_hyps = 0;
		system("cls");
		for (int i = 0; i < num_of_events; i++)
		{
			cout << "Введите вероятность гипотезы H_" << i + 1 << "\n> ";
			cin >> probs_of_hyps[i];
			sum_of_probs_of_hyps += probs_of_hyps[i];
		}
		if (sum_of_probs_of_hyps > 1 || sum_of_probs_of_hyps < 0)
		{
			cout << "Введены неверные значения вероятностей" << endl;
			system("pause");
		}
	}
	cout << endl;
	system("pause");
	system("cls");
	for (int i = 0; i < num_of_events; i++)
	{
		cout << "Введите условную вероятность события A относительно гипотезы H_" << i + 1 <<"\n> ";
		cin >> cond_probs[i];
	}
	cout << endl;
	system("pause");
	int mode = 0;
	while (mode != 1 && mode != 2)
	{
		float full_prob = 0;
		for (int i = 0; i < num_of_events; i++)
		{
			full_prob += probs_of_hyps[i] * cond_probs[i];
		}
		system("cls");
		cout << "Выберите формулу для расчета вероятности:\n 1 - формула полной вероятности\n 2 - формула Байеса\n Введите 0 для выхода\n> ";
		cin >> mode;
		if (mode == 0) return 0;
		else if (mode == 1)
		{
			
			system("cls");
			cout << "Выбрана формула полной вероятности\n\n";
			cout << "P(A) = сумма по i от 0 до n (P(Hi) * P(Hi|A)) " << "\n\n";
			cout << "Вероятность равна:  " << full_prob << endl;
			system("pause");
		}
		else if (mode == 2)
		{
			system ("cls");
			cout << "Выбрана формула Байеса\n\n";
			cout << "P(Hi|A) = (P(Hi)*P(A|Hi))/P(A)\n\n";
			float hyp_prob = 0;
			int b_mode = 0;
			cout << "Выберите режим:\n 1.Вывод всех условных вероятностей\n 2.Вывод части условных вероятностей\n> ";
			cin >> b_mode;
			if (b_mode == 1) 
				for (int i = 0; i < num_of_events; i++)
				{
					hyp_prob = 0;
					hyp_prob = (probs_of_hyps[i] * cond_probs[i]) / full_prob;
					cout << "Условная вероятность гипотезы H_" << i + 1 << " при наступлении события A : " << hyp_prob << "\n\n";
					system("pause");
				}
			else if (b_mode == 2)
			{
				int hyp_prob_to_show[100];
				int count = 0;
				int again = 1;
				while (again != 0)
				{
					system("cls");
					cout << "Введите номер i гипотезы, для которой хотите вывести значение условной вероятности\n> ";
					cin >> hyp_prob_to_show[count];
					count++;
					cout << "\n\nХотите добавить еще одну гипотезу ? (0 - нет, 1 - да)\n> ";
					cin >> again;
				}
				for (int i = 0; i < count; i++)
				{
					hyp_prob = 0;
					hyp_prob = (probs_of_hyps[hyp_prob_to_show[i] -1] * cond_probs[hyp_prob_to_show[i] - 1]) / full_prob;
					cout << "Условная вероятность гипотезы H_" << hyp_prob_to_show[i] << " при наступлении события A : " << hyp_prob << "\n\n";
				}
				
			}
			
		}
	}
	return 0;
}

int main()
{
	setlocale(LC_ALL, "Rus");
	main_prob();
	
}