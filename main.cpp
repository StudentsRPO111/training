#include <iostream>
#include <ctime>

using namespace std;

int* create_array(int SIZE)
{
	int *arr = new int[SIZE];
	for (int i = 0; i < SIZE; i++)
	{
		arr[i] = 0;
	}
	return arr;
}

void Square(int a, int b) {
	int square = pow(a, b);
	cout << square;
}

void increment(int *a)
{
	(*a)++;
}

void ShowArray(int arr[], int size){
    for(int i = 0; i < size; i++){
        cout << arr[i] << "  ";
    }
}

void square_array_elements(int* arr[], int size){
    for(int i = 0; i < size; i++){
        *arr[i] = *arr[i] * *arr[i];
    }
}

int main() {
	setlocale(LC_ALL, "rus");

	return 0;
}