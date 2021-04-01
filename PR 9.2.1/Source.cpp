// Lab_9_1.cpp
// ������ ³����
// ����������� ������ � 9.1.1 г���� B
// ���������� ����� � ����� ��������
// ������ 7

#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>

using namespace std;

enum Specialty { KN, IT, ME, PI, TN };;
string SpecialtyStr[] = { "��������� �����", "�����������", "���������� �� ��������","Գ���� �� �����������","������� ��������" };

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
	cout << "������ ������� �������� N: "; cin >> N;

	Student* p = new Student[N];

	int menuItem;
	do {
		cout << endl << endl;
		cout << "������� ��:" << endl << endl;
		cout << " [1] - �������� ����� � ���������" << endl;
		cout << " [2] - ���� ����� �� �����" << endl;
		cout << " [3] - ������� ������������� �����" << endl;
		cout << " [0] - ����� �� ���������� ������ ��������" << endl << endl;
		cout << "������ ��������: "; cin >> menuItem;
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
			cout << "�� ����� ��������� ��������! "
				"��� ������ ����� - ����� ��������� ������ ����" << endl;
		}
	} while (menuItem != 0);

	return 0;

}

void Create(Student* p, const int N)
{
	int specialty;
	for (int i = 0; i < N; i++)
	{
		cout << "������� � " << i + 1 << ":" << endl;
		cin.get();
		cin.sync();

		cout << " �������: "; getline(cin, p[i].prizv);
		cout << " ����: "; cin >> p[i].kurs;
		cout << " ������������ (0 - ��������� �����, 1 - �����������, 2 - ���������� �� ��������, 3 - Գ���� �� �����������, 4 - ������� ��������): ";
		cin >> specialty;
		p[i].specialty = (Specialty)specialty;
		cout << " ������ � Գ����: "; cin >> p[i].Phisic;
		cout << " ������ � ����������: "; cin >> p[i].Math;
		switch (p[i].specialty)
		{
		case KN:
			cout << " ������ � �������������: "; cin >> p[i].Prog;
			break;
		case IT:
			cout << " ������ � ��������� ������: "; cin >> p[i].Num_Methods;
			break;
		case ME:
		case PI:
		case TN:
			cout << " ������ � ���������: "; cin >> p[i].Pedagogy;
			break;
		}
		cout << endl;
	}
}
void Print(Student* p, const int N)
{
	cout << "============================================================================================================================================================================"
		<< endl;
	cout << "                                                                     ������ ��������" << endl;

	cout << "============================================================================================================================================================================"
		<< endl;
	cout << "|  � |    �������   | ���� |      ������������      | ������ � Գ���� | ������ � ���������� | ������ � ������������� | ������ � ��������� ������  | ������ � ��������� | "
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