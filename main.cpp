#include <iostream>
using namespace std;
int func1(int a){
    cout << a;
}
int main() {
	setlocale(0, "rus");
	std::cout << "���� �� ��� �������, �� ������ � ���� ��������, ������ �������-��������" << "kto prochitaet, tot sdoxnet";
	cout << "New !!!";
	sertlocale(0, "rus");
	std::cout << "���� �� ��� �������, �� ������ � ���� ��������, ������ �������-��������";
    int a;
    cin >> a;
    cout << a;
    func1(a);
    return 0;
}