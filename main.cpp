#include <iostream>
#define EMPTY 0
#define CROSS 1
#define ZERO 2

using namespace std;
char win = '-';  //Символ победы
char user1[80]; char user2[80]; //Переменнные для имен игроков
char  cells[9] = { '-','-','-','-','-','-', '-','-','-' }; //Здесь будут храниться данные о ячейках

//Выводим поле функцией 
void pole() {
	system("cls"); //Очищаем экран, что б было все по красоте

	cout << " Числа клеток \n";
	cout << "-" << 1 << "-" << "|" << "-" << 2 << "-" << "|" << "-" << 3 << "-" << "\n";
	cout << "-" << 4 << "-" << "|" << "-" << 5 << "-" << "|" << "-" << 6 << "-" << "\n";
	cout << "-" << 7 << "-" << "|" << "-" << 8 << "-" << "|" << "-" << 9 << "-" << "\n";

	cout << "Вот что мы имеем сейчас (--пустой): \n";

	cout << "-" << cells[0] << "-" << "|" << "-" << cells[1] << "-" << "|" << "-" << cells[2] << "-" << "\n";
	cout << "-" << cells[3] << "-" << "|" << "-" << cells[4] << "-" << "|" << "-" << cells[5] << "-" << "\n";
	cout << "-" << cells[6] << "-" << "|" << "-" << cells[7] << "-" << "|" << "-" << cells[8] << "-" << "\n";
}

void turn(int number) { //Эта функция ничего не возвращает. У нее есть аргумент - номер игрока, который будет делать ход
	if (number == 1)
		cout << user1;
	else cout << user2;
	int cell;
	cout << "Ваш ход! Введите номер ячейки \n";



	while (cell > 9 || cell < 1 || cells[cell - 1] == '0' || cells[cell - 1] == 'X') {
		cout << "Введите номер клетки: \n";
		cin >> cell;
		cout << "\n";
	}
	//Первый игрок играет крестиками, а второй ноликами 
	if (number == 1) cells[cell - 1] = 'X';
	else cells[cell - 1] = 'O';
}

char check()
{
	for (int i = 0; i < 3; i++) //Для победы нужны три клеточки
		if (cells[i * 3] == cells[i * 3 + 1] && cells[i * 3 + 1] == cells[i * 3 + 2])  //Проверка по горизонтали. Совпадают ли 
			return cells[i];
		else if (cells[i] == cells[i + 3] && cells[i + 3] == cells[i + 6]) //Проверка по вертикали
			return cells[i];
		else if ((cells[4] && cells[4] == cells[6]) || (cells[4] && cells[4] == cells[8]))//Проверка по диагонали  
			return cells[i];
	return '-'; //Иначе - ничья
}

void result() {
	if (win == 'X')
		cout << user1 << "Игрок 1 - Мои поздравления! Вы победили! \n ";
	else if (win == 'O')
		cout << "Игрок 2 - Мои поздравления! Вы победили!\n";
}


int main() {
	setlocale(LC_ALL, "Rus");
	cout << "Добро пожаловать в игру ! \n";

	pole();
	for (int turn = 1; turn <= 9; turn++) {
		if (turn % 2)
	}
}

