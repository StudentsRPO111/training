#include <iostream>
using namespace std;
int func1(int a){
    cout << a;
}
int main() {
<<<<<<< HEAD
	cout << " *^.^* ";
=======
	setlocale(0, "rus");
	std::cout << "���� �� ��� �������, �� ������ � ���� ��������, ������ �������-��������" << "kto prochitaet, tot sdoxnet";
	cout << "New !!!";
>>>>>>> c89cffe15656d43a766e90c32ef2f3fe59617569
	sertlocale(0, "rus");
	std::cout << "���� �� ��� �������, �� ������ � ���� ��������, ������ �������-��������";
    int a;
    cin >> a;
    cout << a;
    func1(a);
    return 0;
}