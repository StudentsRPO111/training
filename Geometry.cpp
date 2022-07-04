// ConsoleApplication56.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

class Geometry {
public:
	static float triangle(int a, int h) {
		count++;
		return 0.5 * a * h;
	}


	static int rectangle(int a, int b) {
		count++;
		return a * b;
	}

	static int square(int a) {
		count++;
		return a * a;
	}

	static int rhombus(int a) {
		count++;
		return a * a;
	}

	static int const  &Count() {
		return count;
	}

private:
	static int count;
};

int Geometry::count = 0;

int main()
{
	setlocale(LC_ALL, "rus");
	Geometry Figure;
	std::cout << "Площадь треугольника: "<< Figure.triangle(5, 20);
	std::cout << "\nПлощадь прямоугольника: " << Figure.rectangle(4, 7);
	std::cout << "\nПлощадь квадрата: " << Figure.square(6);
	std::cout << "\nПлощадь ромба: " << Figure.rhombus(8);
	std::cout << "\nКоличество вычислений площади: "<<  Figure.Count();
	

}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
