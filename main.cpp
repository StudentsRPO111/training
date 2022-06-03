#include <iostream>
#include <Windows.h>
#define SIZE 3

using namespace std;

char field[SIZE][SIZE];

void mark_field(int row, int col, char mark) {
	field[row][col] = mark;
}

void initialize_field() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			field[i][j] = '*';
		}
	}
}

void print_field() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << field[i][j] << " ";
		}
		cout << endl;
	}
}

bool check_winner(char mark) {
	if (field[0][0] == mark && field[1][1] == mark && field[2][2] == mark)
		return true;
	if (field[0][2] == mark && field[1][1] == mark && field[2][0] == mark)
		return true;
	for (int i = 0; i < SIZE; i++) {
		if (field[0][i] == mark && field[1][i] == mark && field[2][i] == mark)
			return true;
		if (field[i][0] == mark && field[i][1] == mark && field[i][2] == mark)
			return true;
	}
	return false;
}
void turn(char mark) {
	int x, y;
	cout << "Введите координаты для " << mark << ':' << endl;
	cin >> x >> y;
	mark_field(x-1, y-1, mark);
}
int main() {
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);


	initialize_field();

	char winner = 0;

	for (int i = 0; i < SIZE*SIZE; i++)
	{
		turn(i % 2 == 0 ? 'X' : '0');
		print_field();
		if (check_winner('X')) {
			cout << "winner is X";
			winner = 'X';
			break;
		}
		if (check_winner('0')) {
			cout << "winner is 0";
			winner = '0';
			break;
		}
	}

	if (winner == 0)
		cout << "Ничья";
	
	getchar();
	
	return 0;
}