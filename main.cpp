#include <iostream>

using namespace std;

void ShowArray(int arr[], int size){
    for(int i = 0; i < size; i++){
        cout << arr[i] << "  ";
    }
}

int main() {
	setlocale(LC_ALL, "rus");
    
    return 0;
}