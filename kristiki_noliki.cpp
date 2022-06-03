//
#include <iostream>
int x, y;
const int size = 3;
char field[size][size];
bool check_winner(char mark);

void fill_field();
void place(int x, int y, char mark) {
	field[x][y] = mark;
}

void turn(char mark) {

	std::cout << "Введите координату x: ";
	std::cin >> x;
	std::cout << "Введите координату y: ";
	std::cin >> y;

	place(x, y, mark);
	system("cls");
	fill_field();

}



void fill_field() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			std::cout << "|";
			std::cout << field[i][j] << " ";
		}
		std::cout << "|";
		std::cout << std::endl;
	}
}
void print() {

	std::cout << "Добро пожаловать в игру крестики-нолики" << std::endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			field[i][j] = '_';
			std::cout << "|";
			std::cout << field[i][j] << " ";
		}
		std::cout << "|";
		std::cout << std::endl;
	}
}

bool check_winner(char mark)
{
	for (int i = 0; i < 3; i++) {
		if (field[i][0] == mark && field[i][1] == mark && field[i][2] == mark) {
			return true;
		}
		if (field[0][i] == mark && field[1][i] == mark && field[2][i] == mark) {
			return true;
		}

		if (field[0][0] == mark && field[1][1] == mark && field[2][2] == mark) {
			return true;
		}
		if (field[0][2] == mark && field[1][1] == mark && field[2][0] == mark) {
			return true;
		}
	}
	
	
	
	return false;
}
int main()
{
	setlocale(0, "rus");
	print();

	int i;
	for (i = 0; i < 9; i++) {
		char mark = i % 2 ? 'O' : 'X';
		turn(mark);
		if (check_winner(mark)) {
			std::cout << "Победил игрок: " << mark << std::endl;
			break;
		}
	}
	
	if (i > 8) {
		std::cout << "Ничья, игра закончена!";
	}
}