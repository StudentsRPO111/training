#include <iostream>
#include <string>
using namespace std;

class Tochka {
public:
	//Tochka(int, int, int);
	//inline static const string CLASS_NAME = "Tochka";
	static const string CLASS_NAME;// = "Tochka";
	static const int STATUS;
	inline void set_x(int value) {
		x = value;
	}
	inline void set_y(int value) {
		y = value;
	}
	inline void set_z(int value) {
		z = value;
	}
	/*const int const &x() {
		return x;
	}*/
	int get_x() {
		return x;
	}
	int get_y() {
		return y;
	}
	int get_z() {
		return z;
	}
	Tochka(int x) : x{ x } {}
	Tochka(int x, int y) : x{ x }, y{ y } {}
	Tochka(int x, int y, int z) : x{ x }, y{ y }, z{z} {}
	Tochka(int x, int y, int z, int w) : Tochka(x, y, z) {
		this->w = w;
	}
	Tochka sum(const Tochka &right) const {
		return Tochka(x + right.x, y + right.y, z + right.z);
	}
	static Tochka summa(const Tochka first, const Tochka second) {
		return Tochka(first.x + second.x, first.y + second.y, first.z + second.z);
	}
	void add(const Tochka &right) {
		x += right.x; 
		y += right.y; 
		z += right.z;
	}
	/*Tochka(int input_x, int input_y, int input_z) {
		this->x = input_x;
		this->y = input_y;
		this->z = input_z;
	}*/
	//void input_data() {
	//	cout << "Введите координату X: ";
	//	cin >> x;
	//	cout << "Введите координату Y: ";
	//	cin >> y;
	//	cout << "Введите координату Z: ";
	//	cin >> z;
	//}
	void output_data() {
		cout << "Координата X: " << x << endl;
		cout << "Координата Y: " << y << endl;
		cout << "Координата Z: " << z << endl;
	}
	/*~Tochka() {
		delete[] name;
	}*/
private:
	int x, y, z, w;
};

//Tochka::Tochka(int input_x, int input_y, int input_z) {
//	this->x = input_x;
//	this->y = input_y;
//	this->z = input_z;
//}

const int Tochka::STATUS = 9;

const string Tochka::CLASS_NAME = "Tochka";

int main() {
	setlocale(LC_ALL, "rus");
	Tochka t{ 5,3,2 };
	Tochka tt{ 5,5,5 };
	int a;
	//Tochka* myTochka = new Tochka(name: new char[] {"Denis"});
	t.output_data();
	cout << "Введите координату X: ";
	cin >> a;
	t.set_x(a);
	cout << "Введите координату Y: ";
	cin >> a;
	t.set_y(a);
	cout << "Введите координату Z: ";
	cin >> a;
	t.set_z(a);
	t.output_data();
	Tochka t2 = t.sum(Tochka(1,1,1));
	t2.output_data();
	cout << Tochka::summa(t, tt).get_x();
	//t.input_data();

	//t.output_data();


	return 0;
}