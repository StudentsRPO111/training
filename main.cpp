#include <iostream>

using namespace std;

int Create_Array(const int SIZE)
{
	int arr[SIZE];
	for (int i = 0; i < SIZE; i++)
	{
		arr[i] = rand() % 11;
		return arr[i];
	}
}

int main() {
	setlocale(LC_ALL, "rus");
	const int SIZE = 10;
	Create_Array(SIZE);
    return 0;
}