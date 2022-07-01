#include <iostream>

using namespace std;

class Point {
public:
	//сеттеры
	/*void setX(int value) {
		x = value;
	}
	void setY(int value) {
		y = value;
	}
	void setZ(int value) {
		z = value;
	}*/
	//геттеры
	/*int getX() {
		return x;
	}
	int getY() {
		return y;
	}
	int getZ() {
		return z;
	}*/
	//конструктор
	Point(int x, int y, int z) : x{ x }, y{ y }, z{ z } {}
	//метод
	void outputPoint() {
		cout << "Точка Х: " << x << endl;
		cout << "Точка Y: " << y << endl;
		cout << "Точка Z: " << z << endl;
	}

private:
	int x = 0;
	int y = 0;
	int z = 0;
};

int main()
{ 
	setlocale(LC_ALL, "rus");
	int x, y, z;
	cin >> x;
	cin >> y;
	cin >> z;
	//объект класса
	Point p(x, y, z);
	/*p.setX(x);
	p.setY(y);
	p.setZ(z);
	cout << p.getX() << " " << p.getY() << " " << p.getZ();*/
	p.outputPoint();
}