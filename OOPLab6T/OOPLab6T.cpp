#include <iostream>

/*Завдання 1. Варіанти задач.Віртуальне успадкування класів класи.
Задача. Створити дві ієрархії класів з віртуальним та без віртуального успадкуванням з
елементами даних класів у кожному класі. Схема успадкування на рисунку за варіантами.
Створити об’єкти похідних класів з віртуальним та без віртуального успадкуванням. Вивести
розміри об’єктів даних класів.
*/ 

#include <iostream>

// Клас Базовий клас без віртуального успадкування

class Base {
protected:
    int dat;
    double a[5] = { 10, 1, 7, 1, 9 }; // Масив поданих

public:
    Base() : dat(1) {} // Конструктор за замовчуванням, ініціалізує dat значенням 1
    Base(int d) : dat(d) {} // Конструктор, який ініціалізує dat переданим значенням
};

// Клас D1, успадковується від Base
class D1 : protected Base {
protected:
    int d1;

public:
    D1() : d1(1) {} // Конструктор за замовчуванням, ініціалізує d1 значенням 1
    D1(int d) : d1(d) {} // Конструктор, який ініціалізує d1 переданим значенням
    D1(int d, int dt) : Base(dt), d1(d) {} // Конструктор, який ініціалізує Base та d1 переданими значеннями
};

// Клас D2, успадковується від Base
class D2 : protected Base {
protected:
    double d2;

public:
    D2() : d2(1) {} // Конструктор за замовчуванням, ініціалізує d2 значенням 1
    D2(int d) : d2(d) {} // Конструктор, який ініціалізує d2 переданим значенням
    D2(int d, double dt) : Base(d), d2(dt) {} // Конструктор, який ініціалізує Base та d2 переданими значеннями
};

// Клас D12, успадковується від D1 та D2
class D12 : protected D1, protected D2 {
protected:
    double dt;

public:
    D12() : dt(1) {} // Конструктор за замовчуванням, ініціалізує dt значенням 1
    D12(int d) : dt(d) {} // Конструктор, який ініціалізує dt переданим значенням
    D12(int a, int b, int c, double d, int e) : D1(a, b), D2(c, d), dt(e) {} // Конструктор, який ініціалізує D1, D2 та dt переданими значеннями
};

// Клас R, успадковується від D12 та Base
class R : protected D12, protected Base {
protected:
    double dt;

public:
    R() : dt(1) {} // Конструктор за замовчуванням, ініціалізує dt значенням 1
    R(int d) : dt(d) {} // Конструктор, який ініціалізує dt переданим значенням
    R(int a, int b, int c, double d, int e) : D12(a, b, c, d, e), Base::Base(a), dt(e + 1.0) {} // Конструктор, який ініціалізує D12, Base та dt переданими значеннями

    // Метод для виведення значення dat з класу Base
    void showDat() {
        std::cout << "dat = " << Base::dat << std::endl;
    }
};

// Клас Базовий клас з віртуальним успадкуванням
class BaseV {
protected:
    int dat;
    double a[5] = { 10, 1, 7, 1, 9 };

public:
    BaseV() : dat(1) {} // Конструктор за замовчуванням, ініціалізує dat значенням 1
    BaseV(int d) : dat(d) {} // Конструктор, який ініціалізує dat переданим значенням
};

// Клас D1V, успадковується від BaseV з віртуальним успадкуванням
class D1V : virtual protected BaseV {
protected:
    int d1;

public:
    D1V() : d1(1) {} // Конструктор за замовчуванням, ініціалізує d1 значенням 1
    D1V(int d) : d1(d) {} // Конструктор, який ініціалізує d1 переданим значенням
    D1V(int d, int dt) : BaseV(dt), d1(d) {} // Конструктор, який ініціалізує BaseV та d1 переданими значеннями
};

// Клас D2V, успадковується від BaseV з віртуальним успадкуванням
class D2V : virtual protected BaseV {
protected:
    double d2;

public:
    D2V() : d2(1) {} // Конструктор за замовчуванням, ініціалізує d2 значенням 1
    D2V(int d) : d2(d) {} // Конструктор, який ініціалізує d2 переданим значенням
    D2V(int d, double dt) : BaseV(d), d2(dt) {} // Конструктор, який ініціалізує BaseV та d2 переданими значеннями
};

// Клас D12VV, успадковується від D1V та D2V з віртуальним успадкуванням
class D12VV : virtual protected D1V, virtual public D2V {
protected:
    double dt;

public:
    D12VV() : dt(1) {} // Конструктор за замовчуванням, ініціалізує dt значенням 1
    D12VV(int d) : dt(d) {} // Конструктор, який ініціалізує dt переданим значенням
    D12VV(int a, int b, int c, double d, int e) : D1V(a, b), D2V(c, d), dt(e) {} // Конструктор, який ініціалізує D1V, D2V та dt переданими значеннями
};

// Клас RV3, успадковується від D12VV та BaseV з віртуальним успадкуванням
class RV3 : virtual protected D12VV, virtual public BaseV {
protected:
    double dt;

public:
    RV3() : dt(1) {} // Конструктор за замовчуванням, ініціалізує dt значенням 1
    RV3(int d) : dt(d) {} // Конструктор, який ініціалізує dt переданим значенням
    RV3(int a, int b, int c, double d, int e) : D12VV(a, b, c, d, e), BaseV::BaseV(a), dt(e + 1.0) {} // Конструктор, який ініціалізує D12VV, BaseV та dt переданими значеннями

    // Метод для виведення значення dat з класу BaseV
    void showDat() {
        std::cout << "dat = " << BaseV::dat << std::endl;
    }
};

int main1() {
    // Створення об'єкта R
    R r;
    // Виведення значення dat з класу Base
    r.showDat();

    // Створення об'єкта RV3
    RV3 rv3;
    // Виведення значення dat з класу BaseV
    rv3.showDat();

    return 0;
}

   
 /*Задача 2.3. Створити абстрактний клас набір дані із віртуальною функцією норма.
Створити похідні класи: комплексне число, вектор з 10 елементів, матриця (2х2).
Визначити функцію норми: для комплексних чисел - модуль у квадраті, для вектора -
корінь */

#include <iostream>
#include <cmath>

// Абстрактний клас "Набір Даних"
class DataSet {
public:
    // Віртуальна функція "Норма"
    virtual double norm() const = 0;
};

// Похідний клас "Комплексне Число"
class ComplexNumber : public DataSet {
private:
    double real;
    double imaginary;

public:
    // Конструктор
    ComplexNumber(double r, double i) : real(r), imaginary(i) {}

    // Функція норми для комплексних чисел (модуль у квадраті)
    virtual double norm() const override {
        return real * real + imaginary * imaginary;
    }
};

// Похідний клас "Вектор з 10 елементів"
class Vector : public DataSet {
private:
    double elements[10];

public:
    // Конструктор
    Vector(const double arr[10]) {
        for (int i = 0; i < 10; ++i) {
            elements[i] = arr[i];
        }
    }

    // Функція норми для вектора (корінь з суми квадратів елементів)
    virtual double norm() const override {
        double sum = 0;
        for (int i = 0; i < 10; ++i) {
            sum += elements[i] * elements[i];
        }
        return sqrt(sum);
    }
};

// Похідний клас "Матриця (2x2)"
class Matrix : public DataSet {
private:
    double elements[2][2];

public:
    // Конструктор
    Matrix(const double arr[2][2]) {
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                elements[i][j] = arr[i][j];
            }
        }
    }

    // Функція норми для матриці (сума квадратів елементів)
    virtual double norm() const override {
        double sum = 0;
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                sum += elements[i][j] * elements[i][j];
            }
        }
        return sqrt(sum);
    }
};

int main() {
    // Приклад використання класів

    // Створення комплексного числа
    ComplexNumber c(3, 4);
    std::cout << "Norm of Complex Number: " << c.norm() << std::endl;

    // Створення вектора
    double arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    Vector v(arr);
    std::cout << "Norm of Vector: " << v.norm() << std::endl;

    // Створення матриці
    double mat[2][2] = { {1, 2}, {3, 4} };
    Matrix m(mat);
    std::cout << "Norm of Matrix: " << m.norm() << std::endl;

    return 0;
}

