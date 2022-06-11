// Work 11.06.2022.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <time.h>
#include <ctime>
using namespace std;

void calkulator(double aa, double bb, char znak)
{


}

double summ(double &a, double &b);
double subt(double &a, double &b);
double mult(double &a, double &b);
double divi(double &a, double &b);

int main()
{
	setlocale(LC_ALL, "RUS");
	double a=0, b=0, result=0;
	int z=0;
	cout << "Введите первое число a :";
	cin >> a;
	cout << endl;
	cout << "Введите первое число b :";
	cin >> b;
	cout << endl;


}

//int main()
//{
//	setlocale(LC_ALL, "RUS");
//	srand(time(NULL));
//	int size;
//	
//	int summ=0;
//	cout << "Введите размер массива :" << endl;
//	cin >> size;
//	int *MassA = new int [size];
//	for (int i = 0; i < size; i++)
//	{
//		MassA[i] = rand() % 25;
//		cout << *(MassA+i) << " ";
//		summ += *(MassA + i);
//	}
//	cout << endl;
//	cout << "Сумма всех чисел массива : " << summ << endl;
//	delete[] MassA;
//}


//int main()
//{
//	setlocale(LC_ALL, "RUS");
//	int *a;
//	int *b;
//	a = new int;
//	b = new int;
//    cout << " Введите первое число a :"<<endl;
//	cin >> *a;
//	cout << " Введите второе число b :" << endl;
//	cin >> *b;
//	if (*a > *b)
//	{
//		cout << "Число а больше !" << endl;
//	}
//	else
//	{
//		cout << "Число b больше !" << endl;
//	}
//
//}



// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
