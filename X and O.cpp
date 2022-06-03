#include <iostream>

using namespace std;

char table[3][3];
const int SIZE = 3;

bool check_winner(char mark);

void show_instruction()
{
	cout << "\t\t***Крестики-нолики***\n\n";
	cout << "Правила: \n";
	cout << "Играют два игрока на поле 3х3\n";
	cout << "Побеждает тот кто быстрее составит комбинацию из трех одинаковых символов\n";

	int l = 0;
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
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
	cout << "  X0  X1  X2" << endl;
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			cout << "| " << table[i][j] << ' ';
		}
		cout << '|';
		cout << endl;
	}
}

void turn(char mark)
{
	int x, y;
	cout << "Введите координату X: " << endl;
	cin >> x;
	cout << "Введите координату Y:" << endl;
	cin >> y;
	while (table[y][x] == 'X' || table[y][x] == '0') {
		cout << "Введите координату X: " << endl;
		cin >> x;
		cout << "Введите координату Y:" << endl;
		cin >> y;
		cout << "Ошибка ввода попробуйте еще раз!";
	}
	table[y][x] = mark;
	system("cls");
	table_print();
}

bool check_winner(char mark)
{
	int count_diag_left = 0;
	int count_diag_right = 0;
	for (int i = 0; i < SIZE; i++)
	{
		int count_row = 0;
		int count_col = 0;
		if (table[i][i] == mark)
			count_diag_left++;
		if (table[i][SIZE - i] == mark)
			count_diag_right++;
		for (int j = 0; j < SIZE; j++)
		{
			if (table[i][j] == mark)
			{
				count_row++;
			}
			if (table[j][i] == mark)
			{
				count_col++;
			}
		}
		if (count_row == 3 || count_col == 3 || count_diag_left == 3 || count_diag_right == 3)
		{
			cout << "Победил " << mark << " END GAME!" << endl;
			return true;
		}
	}
	return false;
}

int main()
{
	setlocale(LC_ALL, "rus");
	show_instruction();
	char player1[]{ 'X' };
	char player2[]{ 'O' };
	cout << "\nИгровое поле\n" << endl;
	table_print();
	for (int i = 0; i < 9; i++)
	{
		turn(i % 2 ? *player1 : *player2);
		if (check_winner(i % 2 ? *player1 : *player2)) {
			cout << "Победитель: " << i % 2 ? *player1 : *player2;
			return 0;
		}
	}
	cout << "Ничья";
	return 0;
}