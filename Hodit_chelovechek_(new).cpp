#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <ctime>
#define SIZE 26
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define ESC 27
#define SPACE 32
using namespace std;

struct Entity {
	int x;
	int y;
};

void newpole(char **arr) {
	const int line_size = SIZE + 2;
	char *field_view = new char[SIZE*line_size + 1]{ 0 };
	for (int i = 0; i < SIZE; i++) {
		field_view[i*line_size] = '\t';
		for (int j = 0; j < SIZE; j++) {
			/*cout << arr[i][j] << " ";*/
			field_view[i*line_size + j + 1] = arr[i][j];
		}
		field_view[i*line_size + SIZE + 1] = '\n';
	}
	system("cls");
	cout << field_view;
}

Entity movement(char **arr, Entity move) {
	/*char xy;
	xy = _getch();*/
	if (!_kbhit())
		return move;
	arr[move.x][move.y] = ' ';
	switch (_getch()) //перед этим было switch(x)
	{
	case UP:
		move.x = move.x ? move.x - 1 : SIZE - 1;
		break;
	case DOWN:
		move.x = (move.x + 1) % 20;
		break;
	case LEFT:
		move.y = move.y ? move.y - 1 : SIZE - 1;
		break;
	case RIGHT:
		move.y = (move.y + 1) % 20;
		break;
	case ESC:
		exit(0);
		break;
	}
	arr[move.x][move.y] = 'X';
	return move;
}

Entity enemy_move(char **arr, Entity enemy) {
	int x_search{ 5 }, y_search{ 5 }, go = 0;
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (arr[i][j] == 'X') {
				x_search = i;
				y_search = j;
				go++;
				break;
			}
		}
		if (go == 1) break;
	}
	arr[enemy.x][enemy.y] = ' ';
	if (enemy.x == x_search) {
		enemy.y = enemy.y < y_search ? enemy.y + 1 : enemy.y - 1;
	}
	else enemy.x = enemy.x < x_search ? enemy.x + 1 : enemy.x - 1;
	arr[enemy.x][enemy.y] = '#';
	return enemy;
}

bool check_kill(Entity player, Entity enemy) {
	if (player.x == enemy.x && player.y == enemy.y) {
		cout << "\n\tТебя поймали, ты проиграл!\n";
		return true;
	}
	return false;
}

BOOL ShowConsoleCursor(BOOL bShow) {
	CONSOLE_CURSOR_INFO cci;
	HANDLE hStdOut;
	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hStdOut == INVALID_HANDLE_VALUE)
		return FALSE;
	if (!GetConsoleCursorInfo(hStdOut, &cci))
		return FALSE;
	cci.bVisible = bShow;
	if (!SetConsoleCursorInfo(hStdOut, &cci))
		return FALSE;
	return TRUE;
}


Entity construct_map(char** arr, Entity cursor) {
	if(arr[cursor.x][cursor.y] != '?') arr[cursor.x][cursor.y] = ' ';
	switch (_getch())
	{
	case UP:
		cursor.x = cursor.x ? cursor.x - 1 : SIZE - 1;
		if (arr[cursor.x][cursor.y] != '?') arr[cursor.x][cursor.y] = '<';
		break;
	case DOWN:
		cursor.x = (cursor.x + 1) % 20;
		if (arr[cursor.x][cursor.y] != '?') arr[cursor.x][cursor.y] = '<';
		break;
	case LEFT:
		cursor.y = cursor.y ? cursor.y - 1 : SIZE - 1;
		if (arr[cursor.x][cursor.y] != '?') arr[cursor.x][cursor.y] = '<';
		break;
	case RIGHT:
		cursor.y = (cursor.y + 1) % 20;
		if (arr[cursor.x][cursor.y] != '?') arr[cursor.x][cursor.y] = '<';
		break;
	case ESC:
		cursor.x = -10;
		break;
	case SPACE:
		if (arr[cursor.x][cursor.y] != '?')
			arr[cursor.x][cursor.y] = '?';
		else
			arr[cursor.x][cursor.y] = '<';
		return cursor;
	}
	return cursor;
}

int main() {
	HANDLE out_handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD crd = { 60, 30 };
	SMALL_RECT src = { 0, 0, crd.X - 1, crd.Y - 1 };
	SetConsoleWindowInfo(out_handle, true, &src);
	SetConsoleScreenBufferSize(out_handle, crd);

	setlocale(LC_ALL, "RUS");
	unsigned int start_time;
	char a;
	char yes[3];
	Entity player = { 15, 15 };
	Entity enemy1 = { 0,0 };
	Entity enemy2 = { 25,25 };
	Entity cursor = { 15,15 };
	char **field = new char*[SIZE];
	for (int i = 0; i < SIZE; i++) {
		field[i] = new char[SIZE];
		for (int j = 0; j < SIZE; j++)
			field[i][j] = ' ';
	}
	cout << "\n\tХотите нарисовать карту?\n";
	cin >> yes;
	_strlwr(yes);
	ShowConsoleCursor(FALSE);
	if ((_strnicmp((yes), "yes", 3) == 0)) {
		while (true) {

			cursor = construct_map(field, cursor);
			newpole(field);
			if (cursor.x == -10) break;
		}
	}
	else ((_strnicmp((yes), "no", 2) == 0));

	field[player.x][player.y] = 'X';
	field[enemy1.x][enemy1.y] = '#';
	field[enemy2.x][enemy2.y] = '%';
	newpole(field);

	while (!check_kill(player, enemy1) && !check_kill(player, enemy2)) {
		player = movement(field, player);
		start_time = clock();
		if (start_time % 500 >= 0 && start_time % 500 <= 100) {
			enemy1 = enemy_move(field, enemy1);
			enemy2 = enemy_move(field, enemy2);
		}
		//Sleep(200);
		newpole(field);
	}
	ShowConsoleCursor(TRUE);

	_getch();
	return 0;
}