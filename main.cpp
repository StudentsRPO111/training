#include <iostream>

using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	int x = 5;
	cout << "���������: " << x * x << endl;

	cout << "New ";
	sertlocale(0, "rus");
	std::cout << "���� �� ��� �������, �� ������ � ���� ��������, ������ �������-��������";
    int a;
    cin >> a;
    cout << a;
    for(int i = 0; i < a;i++){
        cout << i;
    }`
    return 0;
}