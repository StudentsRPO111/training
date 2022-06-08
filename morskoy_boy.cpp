#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <ctime>
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

void create_field(char **arr, int size) {
	for (int i = 0; i < size; i++) {
		arr[i] = new char[size];
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			arr[i][j] = ' ';
		}
	}
}

void show_field(char **arr, int size) {
	for (int i = 0; i < size; i++) {
		if (i == 0) {
			cout << "\t";
			for (int z = 0; z < size + 2; z++) cout << "-";
			cout << "\n";
		}
		cout << "\t|";
		for (int j = 0; j < size; j++) {
			cout << arr[i][j];
			if (j == size - 1) cout << "|\n";
		}
		//cout << "\n";
		if (i == size - 1) {
			cout << "\t";
			for (int z = 0; z < size + 2; z++) cout << "-";
			cout << "\n";
		}
	}
}

void field_player_shot(char **arr, int size) {
	for (int i = 0; i < size; i++) {
		if (i == 0) {
			cout << "\t";
			for (int z = 0; z < size + 2; z++) cout << "-";
			cout << "\n";
		}
		cout << "\t|";
		for (int j = 0; j < size; j++) {
			cout << arr[i][j];
			if (j == size - 1) cout << "|\n";
		}
		//cout << "\n";
		if (i == size - 1) {
			cout << "\t";
			for (int z = 0; z < size + 2; z++) cout << "-";
			cout << "\n";
		}
	}
}


Entity player_choise(char **arr, int size, Entity move) {
	if (arr[move.x][move.y] != '+') arr[move.x][move.y] = ' ';
	switch (_getch()) {
	case UP:
		move.x = move.x ? move.x - 1 : size - 1;
		if (arr[move.x][move.y] != '?' && arr[move.x][move.y] != '+') arr[move.x][move.y] = '<';
		break;
	case DOWN:
		move.x = (move.x + 1) % size;
		if (arr[move.x][move.y] != '?' && arr[move.x][move.y] != '+') arr[move.x][move.y] = '<';
		break;
	case LEFT:
		move.y = move.y ? move.y - 1 : size - 1;
		if (arr[move.x][move.y] != '?' && arr[move.x][move.y] != '+') arr[move.x][move.y] = '<';
		break;
	case RIGHT:
		move.y = (move.y + 1) % size;
		if (arr[move.x][move.y] != '?' && arr[move.x][move.y] != '+') arr[move.x][move.y] = '<';
		break;
	case ESC:
		move.x = -10;
		break;
	case SPACE:
		if (arr[move.x][move.y] != '?')
			arr[move.x][move.y] = '?';
		else
			arr[move.x][move.y] = '<';
		return move;
	}
	return move;
}

Entity placement_of_ships(char **arr, int size, Entity choise_ship) {
	if (arr[choise_ship.x][choise_ship.y] != '#') arr[choise_ship.x][choise_ship.y] = ' ';
	switch (_getch()) {
	case UP:
		choise_ship.x = choise_ship.x ? choise_ship.x - 1 : size - 1;
		if (arr[choise_ship.x][choise_ship.y] != '#') arr[choise_ship.x][choise_ship.y] = '<';
		break;
	case DOWN:
		choise_ship.x = (choise_ship.x + 1) % size;
		if (arr[choise_ship.x][choise_ship.y] != '#') arr[choise_ship.x][choise_ship.y] = '<';
		break;
	case LEFT:
		choise_ship.y = choise_ship.y ? choise_ship.y - 1 : size - 1;
		if (arr[choise_ship.x][choise_ship.y] != '#') arr[choise_ship.x][choise_ship.y] = '<';
		break;
	case RIGHT:
		choise_ship.y = (choise_ship.y + 1) % size;
		if (arr[choise_ship.x][choise_ship.y] != '#') arr[choise_ship.x][choise_ship.y] = '<';
		break;
	case ESC:
		choise_ship.x = -10;
		break;
	case SPACE:
		if (arr[choise_ship.x][choise_ship.y] != '#')
			arr[choise_ship.x][choise_ship.y] = '#';
		else
			arr[choise_ship.x][choise_ship.y] = 'O';
		return choise_ship;
	}
	return choise_ship;
}

void player_shot(char **player, char **enemy, int size, Entity shot) {
	int x = shot.x;
	int y = shot.y;
	//for (int i = 0; i < size; i++) {
	//	for (int j = 0; j < size; j++) {
	//		if (shot == arr[i][j])
	//	}
	//}
	if (enemy[x][y] == '#') {
		system("cls");
		cout << "\n\tПОПАЛ!!!\n";
		Sleep(1500);
		player[x][y] = '+';
	}
}

void bot_shot(char **player, char **enemy_shot, int size) {
	int x = rand() % size;
	int y = rand() % size;
	while (player[x][y] != ' ') {
		if (player[x][y] == '#') {
			enemy_shot[x][y] = '+';
			system("cls");
			cout << "\n\tЯ попал в тебя!\n";
			Sleep(1500);
			return;
		}
		if (player[x][y] == ' ') {
			enemy_shot[x][y] = 'O';
			system("cls");
			cout << "\n\tЯ не попал в тебя!\n";
			Sleep(1500);
			return;
		}
	}
}

bool check_winner(char **player, char **enemy, int size) {
	int player_lost = 0, enemy_lost = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (player[i][j] == '+') enemy_lost++;
			if (enemy[i][j] == '+') player_lost++;
		}
	}
	if (player_lost == 20) {
		system("cls");
		cout << "\n\tИгрок проиграл";
		Sleep(1500);
		return true;
	}
	if (enemy_lost == 2) {
		system("cls");
		cout << "\n\tКомпьютер проиграл";
		Sleep(1500);
		return true;
	}
	return false;
}

int main() {
	HANDLE out_handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD crd = { 40, 40 };
	SMALL_RECT src = { 0, 0, crd.X - 1, crd.Y - 1 };
	SetConsoleWindowInfo(out_handle, true, &src);
	SetConsoleScreenBufferSize(out_handle, crd);

	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	const int size = 12;
	char **field = new char*[size];
	char **field_shot = new char*[size];
	char **enemy_field = new char*[size];
	char **enemy_shot = new char*[size];
	create_field(field, size);
	create_field(field_shot, size);
	create_field(enemy_field, size);
	create_field(enemy_shot, size);
	Entity player{ 10,10 };
	Entity choise_ship{ 10,10 };
	cout << "\n\tМорской бой.\n";
	while (true) {
		choise_ship = placement_of_ships(field, size, choise_ship);
		system("cls");
		cout << "\n\tСоставление поля для игрока.\n";
		show_field(field, size);
		if (choise_ship.x == -10) break;
	}
	choise_ship.x = 0;
	system("cls");
	cout << "\n\tСоставление поля для компьютера.\n";
	show_field(enemy_field, size);
	while (true) {
		choise_ship = placement_of_ships(enemy_field, size, choise_ship);
		system("cls");
		cout << "\n\tСоставление поля для компьютера.\n";
		show_field(enemy_field, size);
		if (choise_ship.x == -10) break;
	}
	system("cls");
	cout << "\n\tНачинается игра";
	Sleep(2000);
	cout << "\n\tПоле игрока.\n";
	show_field(field, size);
	cout << "\n\tПоле выстрела игрока.\n";
	field_player_shot(field_shot, size);
	while (!check_winner(field_shot, enemy_shot, size)) {
		player = player_choise(field_shot, size, player);
		system("cls");
		cout << "\n\tПоле игрока.\n";
		show_field(field, size);
		cout << "\n";
		cout << "\n\tПоле выстрела игрока.\n";
		field_player_shot(field_shot, size);
		if (field_shot[player.x][player.y] == '?') {
			player_shot(field_shot, enemy_field, size, player);
			bot_shot(field, enemy_shot, size);
		}
		if (player.x == -10) break;
	}
	


	return 0;
}

