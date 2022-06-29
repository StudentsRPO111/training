#include <iostream>
#include <string>
using namespace std;

class AbonentRecord {
public:
	// конструктор
	AbonentRecord() {	}
	AbonentRecord(char* value_name) {
		this->name = value_name;
	}
	AbonentRecord(char* value_name, string number) {
		this->name = value_name;
		this->phone_number = number;
	}
	AbonentRecord(string work_phone, string mobile_phone, string addition_info) {
		this->work_phone = work_phone;
		this->mobile_phone = mobile_phone;
		this->addition_info = addition_info;
	}
	AbonentRecord const *copy() {
		auto record_copy  = &AbonentRecord(*this);
		int size = 0;
		while (name[size] != '\0')
			size++;
		if (size)
			size++;
		record_copy->name = new char[size];
		std::copy(name, name + size, record_copy->name);
		return record_copy;
	}
	inline void info() {
		cout << name << '\n' << phone_number << endl;
	}
	inline string get_name() {
		return name;
	}
	// деструктор
	~AbonentRecord() { 
		delete[] name;
	};
	string phone_number, work_phone, mobile_phone, addition_info;
private:
	char* name;
};

class PhoneBook {
public:
	void set(AbonentRecord *abonents, size_t size) {
		this->abonents = abonents;
		this->size = size;
	}
	void get() {
		abonents[0].info();
	}
	~PhoneBook() {
		delete[] abonents;
	}
	inline AbonentRecord *find(const char *name) {
		for (int i = 0; i < size; i++) {
			if (string(name) == string(abonents[i].get_name()))
				return &abonents[i];
		}
	}
	void addAbonent(AbonentRecord abonent) {
		AbonentRecord *new_abonents = new AbonentRecord[size+1];
		for (size_t i = 0; i < size; i++) {
			new_abonents[i] = *abonents[i].copy();
		}
		new_abonents[size] = abonent;
		delete[] abonents;
		abonents = new_abonents;
		size++;
	}
private:
	size_t size;
	AbonentRecord *abonents;
};


int main() {
	setlocale(LC_ALL, "rus");
	/*int choise;
	cout << "Сколько абонентов хотите ввести: ";
	cin >> choise;*/
	PhoneBook book;
	book.set(new AbonentRecord[1]{ AbonentRecord(new char[6] {"Denis"} , "12312312312") }, 1);
	book.find("Denis")->info();
	book.find("Denis")->info();
	book.addAbonent(AbonentRecord(new char[7]{ "Artyom" }, "12312312312"));
	book.find("Artyom")->info();
	return 0;
}