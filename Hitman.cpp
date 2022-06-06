#include <iostream>
#include <conio.h>

using namespace std;

const int SIZE = 20;
char field[SIZE][SIZE];

void create_field()
{
	for (int i = 0; i <= SIZE; i++)
	{
		for (int j = 0; j <= SIZE; j++)
		{
			if (i == 0 || i == SIZE)
			{
				field[i][j] = '*';
			}
			else if (j == 0 || j == SIZE)
			{
				field[i][j] = '*';
			}
			else
			{
				field[i][j] = ' ';
			}
		}
		cout << endl;
	}
}

void print_field(int arr[2])
{
	int x, y;
	x = arr[0];
	y = arr[1];

	system("cls");

	for (int i = 0; i <= SIZE; i++)
	{
		for (int j = 0; j <= SIZE; j++)
		{
			cout << field[i][j] << " ";
		}
		cout << endl;
	}
}

int step(int arr[2])
{
	int i, j;
	i = arr[0];
	j = arr[1];
	int x = _getch();
	field[i][j] = ' ';
	switch (x)
	{
	case 72:
		i = i ? --i : SIZE - 1;
		field[i][j] = char(1);
		break;
	case 80:
		i = (i+1) % 20;
		field[i][j] = char(1);
		break;
	case 77:
		field[i][++j] = char(1);
		break;
	case 75:
		field[i][--j] = char(1);
		break;
	default:
		break;
	}
	arr[0] = i;
	arr[1] = j;
	return arr[2];
}

int main()
{
	setlocale(LC_ALL, "rus");
	int arr[2]{ 5,5 };
	create_field();
	while (true)
	{
		print_field(arr);
		arr[2] = step(arr);
	}

}
