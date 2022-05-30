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

int main() {
	setlocale(LC_ALL, "rus");
	const int SIZE = 10;
	create_array(SIZE);
	return 0;
}