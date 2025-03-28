#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

// Функция для проверки существования трапеции
bool isValidTrapezoid(double a, double b, double c, double d) {
    // Проверка на равенство оснований
    if (a == b) {
        cout << "Ошибка: основания трапеции не должны быть одинаковыми." << endl;
        return false;
    }

    // Проверка на слишком короткие боковые стороны
    if (c <= 0 || d <= 0) {
        cout << "Ошибка: длины боковых сторон должны быть положительными." << endl;
        return false;
    }

    // Проверка неравенства треугольника для боковых сторон
    if (c + d <= fabs(a - b)) {
        cout << "Ошибка: не выполняется неравенство треугольника." << endl;
        return false;
    }

    return true;
}

// Функция для вычисления высоты трапеции
double calculateHeight(double a, double b, double c, double d) {
    double s = (a + b + c + d) / 2; // Полупериметр
    double height = (2 * sqrt(s * (s - a) * (s - b) * (s - c) * (s - d))) / (a + b);
    return height;
}

// Функция для вычисления периметра
double calculatePerimeter(double a, double b, double c, double d) {
    return a + b + c + d;
}

// Функция для вычисления площади
double calculateArea(double a, double b, double height) {
    return ((a + b) / 2) * height;
}

// Функция для вычисления длины средней линии
double calculateMidline(double a, double b) {
    return (a + b) / 2;
}

// Функция для проверки на inf и NaN
bool isInvalid(double value) {
    return std::isnan(value) || std::isinf(value);
}

int main() {
    double a, b, c, d;

    cout << "Введите длины оснований (a, b) и боковых сторон (c, d) трапеции:" << endl;

    // Ввод данных с проверкой на ошибки
    while (true) {
        cout << "a: ";
        cin >> a;
        cout << "b: ";
        cin >> b;
        cout << "c: ";
        cin >> c;
        cout << "d: ";
        cin >> d;

        // Проверка на ввод некорректных значений
        if (cin.fail()|| a<=0 ||b <= 0|| c<=0 || d <= 0) {
            cin.clear(); // Сброс состояния потока
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Игнорирование неправильного ввода
            cout << "Ошибка: введите положительные числа." << endl;
            continue; // Повторный ввод
        }
        break; // Выход из цикла при корректном вводе
    }

    // Проверка на существование трапеции
    if (!isValidTrapezoid(a, b, c, d)) {
        cout << "Такой трапеции не существует." << endl;
        return 0;
    }

    // Вычисление параметров трапеции
    double height = calculateHeight(a, b, c, d);
    double perimeter = calculatePerimeter(a, b, c, d);
    double area = calculateArea(a, b, height);
    double midline = calculateMidline(a, b);

    // Проверка на корректность значений
    if (isInvalid(height) || isInvalid(area)) {
        cout << "Такой трапеции не существует." << endl;
        return 0;
    }

    // Вывод результатов
    cout << "Высота трапеции: " << height << endl;
    cout << "Периметр трапеции: " << perimeter << endl;
    cout << "Площадь трапеции: " << area << endl;
    cout << "Длина средней линии: " << midline << endl;
//trapezoid
    return 0;
}