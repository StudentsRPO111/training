#include <iostream>
#include <string>
using namespace std;

class Point {
public:
	Point(int x) : Point() {}
	Point(int x, int y) : Point() {}
	static int const &ObjCount() {
	return obj_count;
	}
~Point() {
	obj_count--;
}
private:
	int x, y;
	static int obj_count;
	Point() {
		obj_count++;
	}
};

int Point::obj_count = 0;

int main() {
	setlocale(LC_ALL, "rus");
	Point *p = new Point{ 5,3 };
	Point *p2 = new Point{ 5,5};
	cout << p->ObjCount() << endl;
	delete p;
	p = nullptr;
	cout << p->ObjCount() << endl;
	delete p2;
	p2 = nullptr;
	cout << p2->ObjCount() << endl;

	return 0;
}