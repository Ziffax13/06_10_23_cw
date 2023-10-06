#include"Mylibrary.h"
/*дз:
* 1.Создать класс Попугай на основе Animal, реализовать нужные интерфейсы
* 2. Создать класс Самолет, и реализовать нужный интерфейс.
* 3. Создать функцию, который может работать и с объектом класса самолет, и с объектом класса попугай!!

*/

class Ship :public iSwim {
public:
    virtual void Swim() {
        cout << "Корабль - водный транспорт\n";
    }
};

class Airplane :public iFly {
public:
    virtual void Fly() {
        cout << "Самолет летит\n";
    }
};


void Func(iFly* ptr) {
    ptr->Fly();
}

int main()
{
    setlocale(0, "ru");
    Parrot obj("Попугай", 100, "Континент");

    Airplane pl;
    Func(&obj);
    Func(&pl);
}