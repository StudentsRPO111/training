#include <iostream>
#include <stack>
using namespace std;

struct structura //создаем структуру, которая содержит два поля : тип данных и их значения
{
    char type;
    double znacheniye;
};
void Mathematic(stack <structura> & Stack_chisl, stack <structura> & Stack_operations, structura& elem) {
    double n, j, k;
    n = Stack_chisl.top().znacheniye;// функция, которая возвращает самый верхний элемент в стеке с числами
    Stack_chisl.pop;
    switch (Stack_operations.top().type) {
    case '+':
        j = Stack_chisl.top().znacheniye;
        Stack_chisl.pop();
        k = n + j;
        elem.type = '0';
        elem.znacheniye = k;
        Stack_chisl.push()
    }
}

int main()
{
    setlocale(0, 'rus');
    stack <structura> Stack_chisl;
    stack <structura> Stack_operations;
    char simbol;
    double znacheniye;
    structura elem;
    while (1) {
        simbol = cin.peek(); // для  записи символа в переменную 
        cout << simbol;
        if (simbol == endl)break;
        if (simbol >= '0' && simbol <= '9') { // считано число
            cin >> znacheniye; // вводим значение, которое будет взято полностью 
            elem.type = '0';
            elem.znacheniye = znacheniye;
            Stack_chisl.push(elem);
            continue;
        }
        if (simbol == '+' || simbol == '-' || simbol == '*' || simbol == '/') { // считана операция
            elem.type = simbol;
            elem.znacheniye = 0;
            Stack_operations.push(elem);
            cin.ignore();
            continue;
        }
    }
    Mathematic(Stack_chisl, Stack_operations, elem);
    cout << "Otvet:" << Stack_chisl.top().znacheniye << endl;
}
