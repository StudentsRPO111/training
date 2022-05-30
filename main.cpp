#include <iostream>

using namespace std;

void Square(int a, int b) {
	int square = pow(a, b);
	cout << square;
}

void increment(int *a)
{
	(*a)++;
}

int main() {
	setlocale(LC_ALL, "rus");
	return 0;
}