#include <iostream>
#include <ctime>

using namespace std;

int main(){
	char field[3][3];
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
		field[i][j] = '0';
		cout << field[i][j];
		}
		cout << endl;
	}




	return 0;
}