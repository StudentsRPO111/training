#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int* field(int **arr) {
	cout << "             x0  x1  x2\n\n";
	for (int i = 0; i < 3; i++) {
		cout << "\t";
		if (i == 1 || i == 2) cout << "    -----------\n\t";
		cout << "y" << i << "  ";
		for (int j = 0; j < 3; j++) {
			if (j == 1) cout << "|";
			if (j == 2) cout << "|";
			if (arr[i][j] == 1) cout << " X ";
			if (arr[i][j] == 2) cout << " O ";
			if (arr[i][j] == 0) cout << "   ";
		}
		cout << "\n";
	}
	return *arr;
}

int winner(int **arrpole, int player) {
	int win = 0;
	if (arrpole[0][0] == player && arrpole[0][1] == player && arrpole[0][2] == player) {
		return ++win;
	}
	if (arrpole[1][0] == player && arrpole[1][1] == player && arrpole[1][2] == player) {
		return ++win;
	}
	if (arrpole[2][0] == player && arrpole[2][1] == player && arrpole[2][2] == player) {
		return ++win;
	}
	if (arrpole[0][0] == player && arrpole[1][0] == player && arrpole[2][0] == player) {
		return ++win;
	}
	if (arrpole[0][1] == player && arrpole[1][1] == player && arrpole[2][1] == player) {
		return ++win;
	}
	if (arrpole[0][2] == player && arrpole[1][2] == player && arrpole[2][2] == player) {
		return ++win;
	}
	if (arrpole[0][0] == player && arrpole[1][1] == player && arrpole[2][2] == player) {
		return ++win;
	}
	if (arrpole[2][0] == player && arrpole[1][1] == player && arrpole[0][2] == player) {
		return ++win;
	}
	return win;
}

int main() {
	setlocale(LC_ALL, "rus");
	int size = 3, x, y, player, temp, again = 0;
	char a[5], xc[5], yc[5];
	do {
		cout << "\n\tКрестики-Нолики.\n";
		player = 1;
		int **field9 = new int*[size];
		for (int i = 0; i < size; i++) field9[i] = new int[size] {0};
		cout << "\n\n";
		field(field9);
		for (int move = 0; move < 9; move++) {
			cout << "\n\tДелайте свой ход с помощью вписывания координат,\n";
			cout << "\tX по горизонтали, Y по вертикали (выход - quit(Q))\n";
			cout << "\n\tХод " << move + 1 << endl;
			cout << "\tХодит игрок " << player << endl;
			do {
				temp = 0;
				cout << "\tВведите координату X: ";
				cin >> xc;
				x = atoi(xc);
				_strlwr(xc);
				if ((_strnicmp((xc), "quit", 4) == 0) || (_strnicmp((xc), "q", 1) == 0)) break;
				cout << "\tВведите координату Y: ";
				cin >> yc;
				y = atoi(yc);
				_strlwr(yc);
				if ((_strnicmp((yc), "quit", 4) == 0) || (_strnicmp((yc), "q", 1) == 0)) break;
				if ((x >= 0 && x <= 2) && (y >= 0 && y <= 2)) {
					if (field9[y][x] == 0) { field9[y][x] = player; temp++; }
					else cout << "\n\tТуда ходить нельзя!\n";
				}
				else cout << "\n\tНеправильные координаты!\n\n";
			} while (temp != 1);
			if ((_strnicmp((xc), "quit", 4) == 0) || (_strnicmp((xc), "q", 1) == 0)) break;
			if ((_strnicmp((yc), "quit", 4) == 0) || (_strnicmp((yc), "q", 1) == 0)) break;
			system("cls");
			cout << "\n\n";
			field(field9);
			if (winner(field9, player) != 0) {
				cout << "\n\n\tИгрок " << player << " выиграл!\n"; break;
			}
			if (player == 1) player = 2;
			else player = 1;
			if (move == 8) {
				cout << "\n\tНичья!\n";
			}
		}
		cout << "\n\tЕщё раз? (Впишите: yes(Y) или quit(Q) для выхода из игры) ";
		cin >> a;
		_strlwr(a);
		if ((_strnicmp((a), "yes", 3) == 0) || (_strnicmp((a), "y", 1) == 0)) {
			again = 0; system("cls");
		}
		else if ((_strnicmp((a), "quit", 4) == 0) || (_strnicmp((a), "q", 1) == 0)) again = 8;
		for (int i = 0; i < size; i++) {
			delete field9[i];
		}
		delete[] field9;
		field9 = nullptr;
	} while (again != 8);
	
	return 0;
}