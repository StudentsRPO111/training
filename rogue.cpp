#include <iostream>
#include <conio.h>
#include <math.h>

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

void print_field(char **field, int size) {
	char* field_text = new char[size*(size+1)+1]{0};
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			field_text[i*(size+1) + j] = field[i][j];
		}
		field_text[i*(size+1) + size] = '\n';
	}
	system("cls");
	cout << field_text;
	delete[] field_text;
}

struct Entity {
	char mark;
	int x;
	int y;
};

void place_entity(Entity entity, char **field) {
	field[entity.x][entity.y] = entity.mark;
}

void clear_entity(Entity entity, char **field) {
	field[entity.x][entity.y] = '*';
}

void move_enemy(Entity player, Entity& enemy, char **field) {
	if (abs(player.x - enemy.x) > abs(player.y - enemy.y)) {
		clear_entity(enemy, field);
		enemy.y = enemy.y + ((enemy.y - player.y) < 0 ? 1 : -1);
		place_entity(enemy, field);
	} else {
		clear_entity(enemy, field);
		enemy.x = enemy.x + ((enemy.x - player.x) < 0 ? 1 : -1);
		place_entity(enemy, field);
	}
}

int main() {
	char **field;

	const int size = 20;

	field = initialize_field(size);

	Entity player = { 'X', 5, 5 };
	Entity enemy = { 'Y', 10, 10 };

	place_entity(player, field);

	print_field(field, size);

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
		place_entity(player, field);
		move_enemy(player, enemy, field);

		print_field(field, size);
	}

}