#include <iostream>
#include <conio.h>

using namespace std;

class AreaCalculator
{
public:
	static int squareArea(int side)
	{
		count++;
		return side * side;
	}
	static int triangleArea(int height, int base)
	{
		count++;
		return 0,5 * (height * base);
	}
	static int rectangleArea(int side4, int side5)
	{
		count++;
		return side4 * side5;
	}
	static int rhombArea(int a, int b)
	{
		count++;
		return (a * b) / 2;
	}
	static int const &Count()
	{
		return count;
	}
private:
	static int count;
};

int AreaCalculator::count = 0;

int main()
{
	setlocale(LC_ALL, "rus");
	AreaCalculator area;
	int sideArea;
	cout << "Введите сторону квадрата:\n";
	cin >> sideArea;
	int side1, side2, side3;
	cout << "Введите стороны треугольника:\n";
	cin >> side1;
	cin >> side2;
	cout << "Введите стороны прямоугольника:\n";
	int side4, side5;
	cin >> side3;
	cin >> side4;
	cout << "Введите стороны ромба:\n";
	int a, b;
	cin >> a;
	cin >> b;
	cout << "Площаль квадрата = " << area.squareArea(sideArea) << endl;
	cout << "Площадь треугольника = " << area.triangleArea(side1, side2) << endl;
	cout << "Площадь прямоугольника = " << area.rectangleArea(side3, side4) << endl;
	cout << "Площадь ромба = " << area.rhombArea(a, b) << endl;
	cout << "Кол-во подсчетов площади: " << area.Count();
	_getch();
}
