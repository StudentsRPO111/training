#include <iostream>
#include <conio.h>
#include <stdlib.h>
#define SIZE 20
using namespace std;

void newpole(char **arr) {
	const int line_size = SIZE + 2;
	char *field_view = new char[SIZE*line_size + 1]{ 0 };
	for (int i = 0; i < SIZE; i++) {
		field_view[i*line_size] = '\t';
		for (int j = 0; j < SIZE; j++) {
			/*cout << arr[i][j] << " ";*/
			field_view[i*line_size+j+1] = arr[i][j];
		}
		field_view[i*line_size+SIZE+1] = '\n';
	}
	system("cls");
	cout << field_view;
}

int *search(char**arr) {
	int man[2];
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (arr[i][j] == 'X') {
				man[0] = i;
				man[1] = j;
				return man;
			}
		}
	}
}

void movement(char **arr) {
	int *move = new int[2];
	char x;
	x = _getch();
	switch (x) //перед этим было switch(x)
	{
	case 72:
		move = search(arr);
		arr[move[0] - 1][move[1]] = 'X';
		arr[move[0]][move[1]] = ' ';
		cout << "Up" << endl;
		break;
	case 80:
		move = search(arr);
		arr[move[0] +1][move[1]] = 'X';
		arr[move[0]][move[1]] = ' ';
		cout << "Down" << endl;
		break;
	case 75:
		move = search(arr);
		arr[move[0]][move[1] - 1] = 'X';
		arr[move[0]][move[1]] = ' ';
		cout << "Left" << endl;
		break;
	case 77:
		move = search(arr);
		arr[move[0] - 1][move[1] + 1] = 'X';
		arr[move[0]][move[1]] = ' ';
		cout << "Right" << endl;
		break;
	case 27:
		exit(0);
		cout << "ESC" << endl;
		break;
	}
}

int main() {
	setlocale(LC_ALL, "RUS");
	char a;
	char **field = new char*[SIZE];
	for (int i = 0; i < SIZE; i++) {
		field[i] = new char[SIZE];
		for (int j = 0; j < SIZE; j++)
			field[i][j] = ' ';
	}
	field[5][5] = 'X';
	// newpole(field);
	while (true) {
		newpole(field);
		movement(field);
	}


	_getch();
	return 0;
}