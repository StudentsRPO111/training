#include <iostream>

using namespace std;


using namespace std;
int func1(int a){
    cout << a;
}
int main() {
	setlocale(LC_ALL, "rus");
	int x = 5;
	cout << "Результат: " << x * x << endl;
	cout << "New ";
	setlocale(0, "rus");
	std::cout << "Если ты это читаешь, то значит я стал сеньором, первым казахом-сеньором" << "kto prochitaet, tot sdoxnet";
	cout << "New !!!";
	std::cout << "пїЅпїЅпїЅпїЅ пїЅпїЅ пїЅпїЅпїЅ пїЅпїЅпїЅпїЅпїЅпїЅпїЅ, пїЅпїЅ пїЅпїЅпїЅпїЅпїЅпїЅ пїЅ пїЅпїЅпїЅпїЅ пїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅ, пїЅпїЅпїЅпїЅпїЅпїЅ пїЅпїЅпїЅпїЅпїЅпїЅпїЅ-пїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅ";
    int a;
    cin >> a;
    cout << a;
    for(int i = 0; i < a;i++){
        cout << i;
    }
    func1(a);
    return 0;
}