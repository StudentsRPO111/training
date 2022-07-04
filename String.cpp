#include <iostream>
#include <string>
using namespace std;

class String {
public:
	String() {
		str = new char[80]{ 0 };
	}

	String(int size) {
		str = new char[size] { 0 };
	}

	explicit String(const char symbols[]) {
		size_t size = strlen(symbols) + 1;
		str = new char[size]; 
		strcpy_s(str, size, symbols);
	}

	char* stringOut() {
		return str;
	}

	String(String &copy) : String(copy.str) {}

	~String(){
		delete[] str;
	}
private:
	char *str;
};


int main() {
	String *str = new String("sdadas");
	String str2 = *str;
	cout << str->stringOut() << endl;
	str2 = *new String(str2);
	delete str;
	cout << str2.stringOut();
	return 0;
}