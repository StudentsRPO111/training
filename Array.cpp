// ConsoleApplication59.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

using namespace std;


class Array {
public:
	int size;
	int *array;

	explicit Array(int size) {
		this->size = size;
		array = new int[size];
	}

	void fill_array() {
		for (int i = 0; i < size; i++) {
			array[i] = i;
		}
	}
	
	void print_array() {
		for (int i = 0; i < size; i++) {
			cout << array[i] << " ";
		}
	}

	int max() const {
		int max = array[0];
		for (int i = 1; i < size; i++) {
			if (array[i] > max) {
				max = array[i];
			}
		}
		return max;
	}

	int min() {
		int min = array[0];
		for (int i = 0; i < 5; ++i)
		{
			if (array[i] < min)
			{
				min = array[i];
			}
		}
		return min;
	}

	void sort() {
		int temp;
		for (int i = 0; i < size - 1; i++) {
			for (int j = 0; j < size - i - 1; j++) {
				if (array[j] > array[j + 1]) {
					temp = array[j];
					array[j] = array[j + 1];
					array[j + 1] = temp;
				}
			}
		}
		cout << " Отсортированный массив: ";
		for (int i = 0; i < size; i++) {
			cout  << array[i] << " ";
		}
		cout << endl;

	}

	~Array() {
		delete[] array;
	}
};

int main()
{
	setlocale(LC_ALL, "rus");
	Array Arr(10);
	Arr.fill_array();
	Arr.print_array();
	cout << " \nМаксимальный элемент массива: "<< Arr.max();
	cout << "\nМинимальный элемент массива: " << Arr.min();
	Arr.sort();

}

 