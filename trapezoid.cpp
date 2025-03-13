#include <iostream>
using namespace std;

double Perimeter(double a, double b, double c, double d) {
    return a + b + c + d;
}

double Area(double a, double b, double h) {
    return ((a + b) / 2) * h;
}

double MedianLine(double a, double b) {
    return (a + b) / 2;
}

void input(double& a, double& b, double& c, double& d, double& h) {
    cout << "Введите длину основания a: ";
    cin >> a;
    cout << "Введите длину основания b: ";
    cin >> b;
    cout << "Введите длину боковой стороны c: ";
    cin >> c;
    cout << "Введите длину боковой стороны d: ";
    cin >> d;
    cout << "Введите высоту h: ";
    cin >> h;
}

int main() {
    double a, b, c, d, h;
   
    input(a, b, c, d, h);
   
    double perimeter = Perimeter(a, b, c, d);
    double area = Area(a, b, h);
    double medianLine = MedianLine(a, b);
   
    printf("Периметр трапеции: %.2f\n", perimeter);
    printf("Площадь трапеции: %.2f\n", area);
    printf("Длина средней линии: %.2f\n", medianLine);
    return 0;
}
