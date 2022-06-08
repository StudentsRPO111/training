#include <windows.h>
#include <iostream>
#include <time.h>

int row, col;
int** field;
int glowing;

void create_field(int **field, int row, int col) {
	srand(time(NULL));
	
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			field[i][j] = i*row+j + 1;
		}
	}
}

//void print_field(int **field, int row, int col) {
//	for (int i = 0; i < row; i++) {
//		for (int j = 0; j < col; j++) {
//			std::cout << field[i][j] << " ";
//		}
//		std::cout << std::endl;
//	}
//}
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


void step(int **field, int row, int col) {
	int a;
	std::cout << "Введите цифру, которая подсвечена:";
	std::cin >> a;
	if (a == glowing)
		std::cout << "Верно!";
	else std::cout << "Неверно!";
}
		
void show_glowing_sequence(int **field, int row, int col, int glowing_sequence, int last_elem) {
		
}
	




int main()
{
	setlocale(0, "rus");
	std::cout << "Добро пожаловать в игру-память!" << std::endl;
	std::cout << "Введите размер поля:";
	std::cin >> row;
	std::cin >> col;
	int** field = new int* [row];
	for (int i = 0; i < row; i++) {
		field[i] = new int[col];
	}
	create_field(field, row, col);
	//print_field(field, row, col);
	
	
	show_glowing(field, row, col, 6);
	Sleep(1000);
	system("cls");
	step(field, row, col);
	//system("cls");
	//show_glowing1(field, row, col);
	Delete(field, row);
}

