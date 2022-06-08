#include <iostream>
#include <ctime>

using namespace std;

const int SIZE = 3;
int game_field[SIZE][SIZE] = {1,6,3,0,5,4,7,8,2};

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
			if (game_field[i][j] == 0 && game_field[i][j-1] == key)
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

int main()
{
	setlocale(LC_ALL, "rus");
	print_field();
	input();
}
