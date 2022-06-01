#include <iostream>
#include <ctime>

using namespace std;

char player1[30];
char player2[30];
char table[3][3];
bool a = true;
void check();
void instruction()
{
	cout << "\t\t***Крестики-нолики***\n\n";
	cout << "Правила: \n";
	cout << "Играют два игрока на поле 3х3\n";
	cout << "Побеждает тот кто быстрее составит комбинацию из трех одинаковых символов\n";

	int l = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << "| " << l + 1 << ' ';
			table[i][j] = char(49) + l;
			l++;
		}
		cout << '|';
		cout << endl;
	}
	cout << "==============================================" << endl;
}

void table_print()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << "| " << table[i][j] << ' ';
		}
		cout << '|';
		cout << endl;
	}
}

void input()
{
	int position;
	int i = 0;
	int j = 0;
	bool b = true;
	while (a)
	{
		check();
		while (b)
		{
			cout << "Ход игрока: " << player1 << endl;
			cout << "Для хода нажмите цифру ячейки поля\n";
			cin >> position;
			switch (position)
			{
			case 1:
				table[i][j] = 'X';
				break;
			case 2:
				i = 0;
				j = 1;
				table[i][j] = 'X';
				break;
			case 3:
				i = 0;
				j = 2;
				table[i][j] = 'X';
				break;
			case 4:
				i = 1;
				j = 0;
				table[i][j] = 'X';
				break;
			case 5:
				i = 1;
				j = 1;
				table[i][j] = 'X';
				break;
			case 6:
				i = 1;
				j = 2;
				table[i][j] = 'X';
				break;
			case 7:
				i = 2;
				j = 0;
				table[i][j] = 'X';
				break;
			case 8:
				i = 2;
				j = 1;
				table[i][j] = 'X';
				break;
			case 9:
				i = 2;
				j = 2;
				table[i][j] = 'X';
				break;
			}
			system("cls");
			table_print();
			b = false;
		}
		check();
		if (a)
		{
			while (!b)
			{

				cout << "Ход игрока: " << player2 << endl;
				i = 0;
				j = 0;
				cout << "Для хода нажмите цифру ячейки поля\n";
				cin >> position;
				switch (position)
				{
				case 1:
					table[i][j] = '0';
					break;
				case 2:
					i = 0;
					j = 1;
					table[i][j] = '0';
					break;
				case 3:
					i = 0;
					j = 2;
					table[i][j] = '0';
					break;
				case 4:
					i = 1;
					j = 0;
					table[i][j] = '0';
					break;
				case 5:
					i = 1;
					j = 1;
					table[i][j] = '0';
					break;
				case 6:
					i = 1;
					j = 2;
					table[i][j] = '0';
					break;
				case 7:
					i = 2;
					j = 0;
					table[i][j] = '0';
					break;
				case 8:
					i = 2;
					j = 1;
					table[i][j] = '0';
					break;
				case 9:
					i = 2;
					j = 2;
					table[i][j] = '0';
					break;
				}
				system("cls");
				table_print();
				b = true;
			}
		}
	}
	while (!a)
	{
		break;
	}
}

void check()
{
	if (table[0][1] == 'X' && table[0][0] == 'X' && table[0][2] == 'X' || table[1][0] == 'X' && table[1][1] == 'X' && table[1][2] == 'X' ||
		table[2][0] == 'X' && table[2][1] == 'X' && table[2][2] == 'X' || table[0][1] == 'X' && table[1][1] == 'X' && table[2][1] == 'X' ||
		table[0][2] == 'X' && table[1][2] == 'X' && table[2][2] == 'X')
	{
		cout << "Стоп игра у нас есть Победитель! " << player1 << endl;
		a = false;
	}
	if (table[0][1] == '0' && table[0][0] == '0' && table[0][2] == '0' || table[1][0] == '0' && table[1][1] == '0' && table[1][2] == '0' ||
		table[2][0] == '0' && table[2][1] == '0' && table[2][2] == '0' || table[0][1] == '0' && table[1][1] == '0' && table[2][1] == '0' ||
		table[0][2] == '0' && table[1][2] == '0' && table[2][2] == '0')
	{
		cout << "Стоп игра у нас есть Победитель! " << player2 << endl;
		a = false;
	}
}

int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	instruction();
	cout << "\nИгровое поле\n" << endl;
	table_print();
	cout << "Введите имя первого игрока: \n";
	cin >> player1;
	cout << "Введите имя второго игрока: \n";
	cin >> player2;
	input();
}