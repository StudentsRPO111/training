#include <iostream>
#include <conio.h>
#include <stdlib.h>
#define SIZE 20
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define ESC 27
using namespace std;

struct player {
	int x;
	int y;
};

struct enemy {
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

//int *search(char**arr) {
//	int man[2];
//	for (int i = 0; i < SIZE; i++) {
//		for (int j = 0; j < SIZE; j++) {
//			if (arr[i][j] == 'X') {
//				man[0] = i;
//				man[1] = j;
//				return man;
//			}
//		}
//	}
//}

player movement(char **arr, player move) {
	/*char xy;
	xy = _getch();*/
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

enemy enemy_move(char **arr, enemy enemy) {
	int xs, ys, go = 0;
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (arr[i][j] == 'X') {
				xs = i;
				ys = j;
				go++;
				break;
			}
		}
		if (go == 1) break;
	}
	arr[enemy.x][enemy.y] = ' ';
	enemy.x = enemy.x < xs ? enemy.x + 1 : enemy.x - 1;
	arr[enemy.x][enemy.y] = '#';
	if (enemy.x == xs) {
		arr[enemy.x][enemy.y] = ' ';
		enemy.y = enemy.y < ys ? enemy.y + 1 : enemy.y - 1;
		arr[enemy.x][enemy.y] = '#';
	}
	return enemy;
}

bool kill(player player, enemy enemy) {
	if (player.x == enemy.x && player.y == enemy.y) {
		cout << "\n\tТебя поймали, ты проиграл!\n";
		return false;
	}
	return true;
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
	player player = { 5,5 };
	enemy enemy = { 0,0 };
	field[player.x][player.y] = 'X';
	field[enemy.x][enemy.y] = '#';
	while (true) {
		newpole(field);
		enemy = enemy_move(field, enemy);
		player = movement(field, player);
		if(!kill(player, enemy))break;
	}


	/*_getch();*/
	return 0;
}