#include <iostream>
using namespace std;

class Array {
public:
	explicit Array(int value) {
		size = value;
		arr = new int[size];
	}
	void reallocate(int size) {
		this->size = size;
		delete[] arr;
		arr = new int[this->size];
	}
	void arrElem() {
		int elem;
		for (int i = 0; i < size; i++) {
			cout << "Введите " << i << " элемент: ";
			cin >> elem;
			arr[i] = elem;
		}
	}
	void arrOut() {
		for (int i = 0; i < size; i++) {
			cout << arr[i] << " ";
		}
	}
	static int *copyArray(int *array, int old_size, int size = 0) {
		if (size == 0)
			size = old_size;
		int *new_array = new int[size] {0};
		for (int i = 0; i < old_size; i++) {
			new_array[i] = array[i];
		}
		return new_array;
	}
	void setArraySafe(int *new_array, int newsize, int old_size = 0) {
		if (old_size == 0)
			old_size = size;
		auto array = copyArray(new_array, old_size, newsize);
		delete arr;
		setArrayUnsafe(array, newsize);
	}
	void setArrayUnsafe(int *new_array, int newsize) {
		size = newsize;
		arr = new int[size];
		arr = new_array;
	}
	void changeSize(int newsize) {
		setArraySafe(arr, newsize);
	}
	void changeSizeByInput() {
		int newsize;
		cout << "Введите сколько элементов хотите сделать: ";
		cin >> newsize;
		changeSize(newsize);
	}
	void sortArray() {
		for (int i = 0; i < size; i++) {
			for (int i = 0; i < size - 1; i++) {
				if (arr[i] > arr[i + 1]) swap(arr[i], arr[i + 1]);
			}
		}
	}
	int min(){
		int min_elem = arr[0];
		for (int i = 0; i < size; i++) {
			if (arr[i] < min_elem) min_elem = arr[i];
		}
		return min_elem;
	}
	int max() {
		int max_elem = arr[0];
		for (int i = 0; i < size; i++) {
			if (arr[i] > max_elem) max_elem = arr[i];
		}
		return max_elem;
	}
	Array(int *arr) {
		this->arr = arr;
	}
	Array(int *arr, int size){
		setArraySafe(arr, size);
	}
	Array(Array &copy) : Array(copy.arr, copy.size) {}

	~Array() {
		delete[] arr;
		arr = nullptr;
	}
private:
	int *arr;
	int size = 0;
};


int main() {
	setlocale(LC_ALL, "rus");
	Array arr = new int[4]{ 1,2,3,4 };
//	arr.reallocate(5);
	arr.arrElem();
	arr.arrOut();
	arr.changeSizeByInput();
	cout << endl;
	arr.arrOut();
	arr.sortArray();
	cout << endl;
	arr.arrOut();
	Array arr2 = arr;
	cout << endl;
	arr.arrOut();
	cout << "Min: " << arr.min() << " Max: " << arr.max() << endl;
	return 0;
}