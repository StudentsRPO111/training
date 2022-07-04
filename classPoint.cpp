#include <iostream>

using namespace std;

class Tochka
{
public:
	int x;
	int y;
	Tochka(int x, int y) : Tochka() {

	}
	~Tochka() {
		objects_count--;
	}
	static int const &ObjectsCount() {
		return objects_count;
	};
private:
	static int objects_count;
	Tochka() {
		objects_count++;
	}

};

int Tochka::objects_count = 0;

int main()
{
	Tochka *p = new Tochka(5,6);
	cout << p->ObjectsCount();
	delete p;
	cout << endl << p->ObjectsCount();
}