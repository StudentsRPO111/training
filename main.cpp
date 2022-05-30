#include <iostream>

int main() {
	cout << "New ";
	sertlocale(0, "rus");
	std::cout << "���� �� ��� �������, �� ������ � ���� ��������, ������ �������-��������";
    int a;
    cin >> a;
    cout << a;
    for(int i = 0; i < a;i++){
        cout << i;
    }
    return 0;
}