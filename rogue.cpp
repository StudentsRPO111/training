#include <iostream>
#include <conio.h>

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77

using namespace std;

char** initialize_field(int size) {
	char **field = new char*[size];
	for (int i = 0; i < size; i++) {
		field[i] = new char[size];
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			field[i][j] = '*';
		}
	}
	return field;
}

void print_field(char** field, int size) {
	system("cls");
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << field[i][j] << " ";
		}
		cout << endl;
	}
}

struct Position {
	int x;
	int y;
};

int main() {
	char **field;
	// char **field = new char*[20];
	// field[0] = new char[20];

	const int size = 20;

	field = initialize_field(size);

	Position player = { 5,5 };
	field[player.x][player.y] = 'X';

	while (true) {
		field[player.x][player.y] = '*';
		switch (_getch()) {
			case UP:
				player.x = player.x ? player.x - 1 : size-1;
				break;
			case DOWN:
				player.x = (player.x + 1) % size;
				break;
			case LEFT:
				player.y = player.y ? player.y - 1 : size - 1;
				break;
			case RIGHT:
				player.y = (player.y + 1) % size;
				break;
	
		}
		field[player.x][player.y] = 'X';
		print_field(field, size);
	}

}
