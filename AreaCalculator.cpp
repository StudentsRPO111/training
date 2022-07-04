#include <iostream>
using namespace std;

class AreaCalculator {
public:
	static int getSquareArea(int a) {
		count++;
		return a * a;
	}
	static int getTriangleArea(int side, int height) {
		count++;
		return 0.5*side*height;
	}
	static int countCalculations() {
		return count;
	}
private:
	static int count;
};

int AreaCalculator::count = 0;

int main() {
	setlocale(LC_ALL, "rus");
	int side, height;
	cout << "Square:\ninput side: ";
	cin >> side;
	cout << "square's area: " << AreaCalculator::getSquareArea(side) << endl;
	cout << "Triangle:\ninput side: ";
	cin >> side;
	cout << "input height: ";
	cin >> height;
	cout << "triangle's area: " << AreaCalculator::getTriangleArea(side, height) << endl;
	cout << "count: " << AreaCalculator::countCalculations() << endl;
	
	return 0;
}