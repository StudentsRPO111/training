#include <iostream>
using namespace std;

char player1[80]; char player2[80]; //Переменнные для имен игроков
char cells[9] = { '-','-','-','-','-','-', '-','-','-' };
char win = '-';
void vivod_pole() {
	system("cls"); //Очищаем экран

	cout << " Числа клеток \n";
	cout << "-" << 1 << "-" << "|" << "-" << 2 << "-" << "|" << "-" << 3 << "-" << "\n";
	cout << "-" << 4 << "-" << "|" << "-" << 5 << "-" << "|" << "-" << 6 << "-" << "\n";
	cout << "-" << 7 << "-" << "|" << "-" << 8 << "-" << "|" << "-" << 9 << "-" << "\n";

	cout << "Вот что мы имеем сейчас (--пустой): \n";

	cout << "-" << cells[0] << "-" << "|" << "-" << cells[1] << "-" << "|" << "-" << cells[2] << "-" << "\n";
	cout << "-" << cells[3] << "-" << "|" << "-" << cells[4] << "-" << "|" << "-" << cells[5] << "-" << "\n";
	cout << "-" << cells[6] << "-" << "|" << "-" << cells[7] << "-" << "|" << "-" << cells[8] << "-" << "\n";
}

void make_move(int numplayer) {
	if (numplayer == 1) cout << player1;
	else cout << player2;
	int cell; //Клетка(ячейка)
	cout << "Введите номер ячейки \n";
	cin >> cell;
	while (cell < 9 || cell < 1 || cells[cell - 1] == 'O' || cells[cell - 1] == 'X')
		cout << "Ошибка \n";
	cin >> cell;

	if (numplayer == 1) cells[cell - 1] = 'X';
	else cells[cell - 1] = 'O';
}

char check() {
	for (int i = 0; i < 3; i++)
		if (cells[i * 3] == cells[i * 3 + 1] && cells[i * 3 + 1] == cells[i * 3 + 2])
			return cells[i];
		else if (cells[i] == cells[i + 3] && cells[i + 3] == cells[i + 6])
			return cells[i];
		else if ((cells[2] == cells[4] && cells[4] == cells[6]) || (cells[0] == cells[4] && cells[4] == cells[8]))
			return cells[i];
	return '-';

}
void res() {
	if (win == 'X')
		cout << player1 << "Победил игрок 1 \n";
	else if (win == 'O')
		cout << player2 << "Победил игрок 2 \n";
}


int main()
{
	setlocale(LC_ALL, "Rus");
	cout << "Добро пожаловать! \n";
}


void vivod_pole() {
	if (move >= 5)
	{
		win = check();
		if (win != '-')
			break;
	}

}




