#include <iostream>
#include <ctime>

using namespace std;

const int SIZE = 3;
int game_field[SIZE][SIZE];
int reference[SIZE][SIZE];

void input_field()
{
	int a = 0;
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++, a++)
		{
			game_field[i][j] = a;
		}
	}
}

void reference_field()
{
	int b = 1;
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++, b++)
		{
			reference[i][j] = b;
			if (b == 9 || b == 4)
			{
				reference[i][j] = 0;
			}
		}
	}
}

void print_reference()
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (reference[i][j] == 0)
			{
				cout << " " << " ";
			}
			else
				cout << reference[i][j] << " ";
		}
		cout << endl;
	}
}

void shuffle()
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			swap(game_field[i][j], game_field[0 + rand() % SIZE][0 + rand() % SIZE]);
		}
	}
}

void print_field()
{
	system("cls");
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (game_field[i][j] == 0)
			{
				cout << " " << " ";
			}
			else
				cout << game_field[i][j] << " ";
		}
		cout << endl;
	}
}

void input()
{
	int key;
	cin >> key;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (game_field[i][j] == 0 && game_field[i][j - 1] == key)
			{
				game_field[i][j] = key;
				game_field[i][j - 1] = 0;
				break;
			}
			else if (game_field[i][j] == 0 && game_field[i + 1][j] == key)
			{
				game_field[i][j] = key;
				game_field[i + 1][j] = 0;
				break;
			}
			else if (game_field[i][j] == 0 && game_field[i][j + 1] == key)
			{
				game_field[i][j] = key;
				game_field[i][j + 1] = 0;
				break;
			}
			else if (game_field[i][j] == 0 && game_field[i - 1][j] == key)
			{
				game_field[i][j] = key;
				game_field[i - 1][j] = 0;
				break;
			}
		}
		break;
	}
	print_field();
}

bool winner()
{
	int count = 0;
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (game_field[i][j] != reference[i][j])
			{
				return false;
			}
		}
	}
	cout << "Победа" << endl;
	return 0;
}

int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	input_field();
	shuffle();
	print_field();
	cout << endl;
	reference_field();
	cout << "Образец для победы!\n";
	print_reference();
	while (true)
	{
		input();
		winner();
	}
}