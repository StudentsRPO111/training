#include <iostream>
#define EMPTY 0
#define CROSS 1
#define ZERO 2

using namespace std;
char win = '-';  //������ ������
char user1[80]; char user2[80]; //����������� ��� ���� �������
char  cells[9] = { '-','-','-','-','-','-', '-','-','-' }; //����� ����� ��������� ������ � �������

//������� ���� �������� 
void pole() {
	system("cls"); //������� �����, ��� � ���� ��� �� �������

	cout << " ����� ������ \n";
	cout << "-" << 1 << "-" << "|" << "-" << 2 << "-" << "|" << "-" << 3 << "-" << "\n";
	cout << "-" << 4 << "-" << "|" << "-" << 5 << "-" << "|" << "-" << 6 << "-" << "\n";
	cout << "-" << 7 << "-" << "|" << "-" << 8 << "-" << "|" << "-" << 9 << "-" << "\n";

	cout << "��� ��� �� ����� ������ (--������): \n";

	cout << "-" << cells[0] << "-" << "|" << "-" << cells[1] << "-" << "|" << "-" << cells[2] << "-" << "\n";
	cout << "-" << cells[3] << "-" << "|" << "-" << cells[4] << "-" << "|" << "-" << cells[5] << "-" << "\n";
	cout << "-" << cells[6] << "-" << "|" << "-" << cells[7] << "-" << "|" << "-" << cells[8] << "-" << "\n";
}

void turn(int number) { //��� ������� ������ �� ����������. � ��� ���� �������� - ����� ������, ������� ����� ������ ���
	if (number == 1)
		cout << user1;
	else cout << user2;
	int cell;
	cout << "��� ���! ������� ����� ������ \n";



	while (cell > 9 || cell < 1 || cells[cell - 1] == '0' || cells[cell - 1] == 'X') {
		cout << "������� ����� ������: \n";
		cin >> cell;
		cout << "\n";
	}
	//������ ����� ������ ����������, � ������ �������� 
	if (number == 1) cells[cell - 1] = 'X';
	else cells[cell - 1] = 'O';
}

char check()
{
	for (int i = 0; i < 3; i++) //��� ������ ����� ��� ��������
		if (cells[i * 3] == cells[i * 3 + 1] && cells[i * 3 + 1] == cells[i * 3 + 2])  //�������� �� �����������. ��������� �� 
			return cells[i];
		else if (cells[i] == cells[i + 3] && cells[i + 3] == cells[i + 6]) //�������� �� ���������
			return cells[i];
		else if ((cells[4] && cells[4] == cells[6]) || (cells[4] && cells[4] == cells[8]))//�������� �� ���������  
			return cells[i];
	return '-'; //����� - �����
}

void result() {
	if (win == 'X')
		cout << user1 << "����� 1 - ��� ������������! �� ��������! \n ";
	else if (win == 'O')
		cout << "����� 2 - ��� ������������! �� ��������!\n";
}


int main() {
	setlocale(LC_ALL, "Rus");
	cout << "����� ���������� � ���� ! \n";

	pole();
	for (int turn = 1; turn <= 9; turn++) {
		if (turn % 2)
	}
}

