#include <iostream>

using namespace std;

void Square(int a, int b) {
	int square = pow(a, b);
	cout << square;
}

void ShowArray(int arr[], int size){
    for(int i = 0; i < size; i++){
        cout << arr[i] << "  ";
    }
}

int main() {
	setlocale(LC_ALL, "rus");
	return 0;
}