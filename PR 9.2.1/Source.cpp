// Lab_9_1.cpp
// Обухов Віктор
// Лабораторна робота № 9.1.1 Рівень B
// Послідовний пошук в масиві структур
// Варіант 7

#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>

using namespace std;

enum Specialty { KN, IT, ME, PI, TN };;
string SpecialtyStr[] = { "Комп’ютерні науки", "Інформатика", "Математика та економіка","Фізика та інформатика","Трудове навчання" };

struct Student
{
	string prizv;
	int kurs;
	Specialty specialty;
	int Phisic;
	int Math;
	union {
		int Prog;
		int Num_Methods;
		int Pedagogy;
	};


};


void Create(Student* p, const int N);
void Print(Student* p, const int N);
void Sort(Student* p, const int N);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int N;
	cout << "Введіть кількість студентів N: "; cin >> N;

	Student* p = new Student[N];

	int menuItem;
	do {
		cout << endl << endl;
		cout << "Виберіть дію:" << endl << endl;
		cout << " [1] - введення даних з клавіатури" << endl;
		cout << " [2] - вивід даних на екран" << endl;
		cout << " [3] - фізичне впорядкування даних" << endl;
		cout << " [0] - вихід та завершення роботи програми" << endl << endl;
		cout << "Введіть значення: "; cin >> menuItem;
		cout << endl << endl << endl;
		switch (menuItem)
		{
		case 1:
			Create(p, N);
			break;
		case 2:
			Print(p, N);
			break;
		case 3:
			Sort(p, N);
			break;
		case 0:
			break;
		default:
			cout << "Ви ввели помилкове значення! "
				"Слід ввести число - номер вибраного пункту меню" << endl;
		}
	} while (menuItem != 0);

	return 0;

}

void Create(Student* p, const int N)
{
	int specialty;
	for (int i = 0; i < N; i++)
	{
		cout << "Студент № " << i + 1 << ":" << endl;
		cin.get();
		cin.sync();

		cout << " Прізвище: "; getline(cin, p[i].prizv);
		cout << " Курс: "; cin >> p[i].kurs;
		cout << " Спеціальність (0 - Комп’ютерні науки, 1 - Інформатика, 2 - Математика та економіка, 3 - Фізика та інформатика, 4 - Трудове навчання): ";
		cin >> specialty;
		p[i].specialty = (Specialty)specialty;
		cout << " Оцінка з Фізики: "; cin >> p[i].Phisic;
		cout << " Оцінка з Математики: "; cin >> p[i].Math;
		switch (p[i].specialty)
		{
		case KN:
			cout << " Оцінка з Програмування: "; cin >> p[i].Prog;
			break;
		case IT:
			cout << " Оцінка з Чисельних методів: "; cin >> p[i].Num_Methods;
			break;
		case ME:
		case PI:
		case TN:
			cout << " Оцінка з Педагогіки: "; cin >> p[i].Pedagogy;
			break;
		}
		cout << endl;
	}
}
void Print(Student* p, const int N)
{
	cout << "============================================================================================================================================================================"
		<< endl;
	cout << "                                                                     Список студентів" << endl;

	cout << "============================================================================================================================================================================"
		<< endl;
	cout << "|  № |    Прізвище   | Курс |      Спеціальність      | Оцінка з Фізики | Оцінка з Математики | Оцінка з Програмування | Оцінка з Чисельних методів  | Оцінка з Педагогіки | "
		<< endl;
	cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------"
		<< endl;
	for (int i = 0; i < N; i++)
	{
		cout << "| " << setw(2) << right << i + 1 << " ";
		cout << "| " << setw(13) << left << p[i].prizv << " "
			<< "| " << setw(4) << right << p[i].kurs << " "
			<< "| " << setw(23) << left << SpecialtyStr[p[i].specialty] << " "
			<< "| " << setw(15) << right << p[i].Phisic << " "
			<< "| " << setw(19) << right << p[i].Math << " ";
		switch (p[i].specialty)
		{
		case KN:
			cout << "| " << setw(22) << right << p[i].Prog << " |" << setw(30) << "|" << setw(22) << "  |" << endl;
			break;
		case IT:
			cout << "| " << setw(24) << " |" << setw(29) << right << p[i].Num_Methods << "|" << setw(22) << " |" << endl;
			break;
		case ME:
		case PI:
		case TN:
			cout << "| " << setw(24) << " |" << setw(30) << "|" << setw(21) << right << p[i].Pedagogy << "|" << endl;
			break;
		}

	}
	cout << "============================================================================================================================================================================="
		<< endl;
	cout << endl;
}

void Sort(Student* p, const int N)
{
	Student tmp;
	for (int i0 = 0; i0 < N - 1; i0++)
		for (int i1 = 0; i1 < N - i0 - 1; i1++)
			if ((SpecialtyStr[p[i1].specialty] > SpecialtyStr[p[i1 + 1].specialty])
				||
				(SpecialtyStr[p[i1].specialty] == SpecialtyStr[p[i1 + 1].specialty] &&
					p[i1].specialty < p[i1 + 1].specialty)
				||
				(SpecialtyStr[p[i1].specialty] == SpecialtyStr[p[i1 + 1].specialty] &&
					p[i1].specialty == p[i1 + 1].specialty &&
					p[i1].prizv > p[i1 + 1].prizv))
			{
				tmp = p[i1];
				p[i1] = p[i1 + 1];
				p[i1 + 1] = tmp;
			}
}