#include <iostream>
#include <cmath>
#include <locale> // Для локализации

const double PI = 3.141592653589793;

// Длина окружности
double circumference(double r) {
    return 2 * PI * r;
}

// Площадь круга
double circle_area(double r) {
    return PI * r * r;
}

// Площадь кругового сектора
double sector_area(double r, double angle) {
    return (PI * r * r * angle) / 360.0;
}

int main() {
    // Установка локали для поддержки русского языка
    setlocale(LC_ALL, "Russian");

    double r, angle;
    std::cout << "Введите радиус окружности: ";
    std::cin >> r;

    std::cout << "Введите угол сектора (в градусах): ";
    std::cin >> angle;

    std::cout << "Длина окружности: " << circumference(r) << std::endl;
    std::cout << "Площадь круга: " << circle_area(r) << std::endl;
    std::cout << "Площадь кругового сектора: " << sector_area(r, angle) << std::endl;

    return 0;
}
