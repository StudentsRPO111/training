#include <iostream>



using namespace std;
int func1(int a){
    cout << a;
	return a;
}
int main() {
	setlocale(LC_ALL, "rus");
	int x = 5;
	cout << "���������: " << x * x << endl;
	cout << "New ";
	std::cout << "���� �� ��� �������, �� ������ � ���� ��������, ������ �������-��������" << "kto prochitaet, tot sdoxnet";
	cout << "New !!!";
	cout << " *^.^* ";
	std::cout << "���� �� ��� �������, �� ������ � ���� ��������, ������ �������-��������" << "kto prochitaet, tot sdoxnet";
	std::cout << "���� �� ��� �������, �� ������ � ���� ��������, ������ �������-��������";
    int a;
    cin >> a;
    cout << a;
    for(int i = 0; i < a;i++){
        cout << i;
    }
    func1(a);
    return 0;
}