#include <windows.h>
#include <iostream>

int row, col;
int** field;
int* glowing_sequence;
int last_elem = 5;

void create_field(int **field, int row, int col) {

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			field[i][j] = i * row + j + 1;
		}
	}
}


void Delete(int** field, int row)
{
	for (int i = 0; i < row; i++)
	{
		delete[] field[i];
	}
	delete[] field;
}
void show_glowing(int **field, int row, int col, int glowing) {
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (field[i][j] == glowing) {
				SetConsoleTextAttribute(console, FOREGROUND_GREEN);
			}
			std::cout << field[i][j] << " ";
			SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		}
		std::cout << std::endl;

	}

}


void step(int **field, int row, int col, int glowing) {
	int a;
	std::cout << "Введите цифру, которая подсвечена:";
	std::cin >> a;
	if (a == glowing)
		std::cout << "Верно!";
	else {
		std::cout << "Неверно!";
	}

}

void show_glowing_sequence(int **field, int row, int col, int glowing, int glowing_sequence) {
	for (int i = 1; i < last_elem; i++) {
		std::cout << std::endl;
		show_glowing(field, row, col, i);
		Sleep(1000);
		system("cls");
	}
}





int main()
{
	setlocale(0, "rus");
	std::cout << "Добро пожаловать в игру-память!" << std::endl;
	std::cout << "Введите размер поля:";
	std::cin >> row;
	std::cin >> col;
	int** field = new int*[row];
	for (int i = 0; i < row; i++) {
		field[i] = new int[col];
	}
	create_field(field, row, col);
	int* glowing_sequence = new int[row*col];
	//.glowing_sequence[last_elem++] = rand() % (row * col);
	show_glowing_sequence(field, row, col, );
	step(field, row, col, 2);
	Delete(field, row);
}