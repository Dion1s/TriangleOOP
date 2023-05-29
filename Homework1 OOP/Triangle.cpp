#include "triangle.h"

#define M_PI 3.14
CTriangle::CTriangle() : side1(0), side2(0), side3(0) {}

CTriangle::CTriangle(double s1, double s2, double s3) : side1(s1), side2(s2), side3(s3) {}

CTriangle::~CTriangle() {
    // Порожнє тіло деструктора
}
double CTriangle::GetSide1() const {
    return side1;
}

double CTriangle::GetSide2() const {
    return side2;
}

double CTriangle::GetSide3() const {
    return side3;
}

void CTriangle::SetSide1(double s1) {
    side1 = s1;
}

void CTriangle::SetSide2(double s2) {
    side2 = s2;
}

void CTriangle::SetSide3(double s3) {
    side3 = s3;
}

void CTriangle::console_input() {
    double s1, s2, s3;
    do {
        std::cout << "Enter the side 1: ";
        std::cin >> s1;
        if (s1 <= 0)
            std::cout << "Invalid input! Side length must be a positive number." << std::endl;
    } while (s1 <= 0);
    SetSide1(s1);

    do {
        std::cout << "Enter the side 2: ";
        std::cin >> s2;
        if (s2 <= 0)
            std::cout << "Invalid input! Side length must be a positive number." << std::endl;
    } while (s2 <= 0);
    SetSide2(s2);

    do {
        std::cout << "Enter the side 3: ";
        std::cin >> s3;
        if (s3 <= 0)
            std::cout << "Invalid input! Side length must be a positive number." << std::endl;
        else if (s1 + s2 <= s3 || s1 + s3 <= s2 || s2 + s3 <= s1)
            std::cout << "Invalid input! The sum of any two sides should be greater than the third side." << std::endl;
    } while (s3 <= 0 || s1 + s2 <= s3 || s1 + s3 <= s2 || s2 + s3 <= s1);
    SetSide3(s3);
}



void CTriangle::console_output() const {
    std::cout << "Triangle sides: " << GetSide1() << ", " << GetSide2() << ", " << GetSide3() << std::endl;

    try {
        if (GetSide1() <= 0 || GetSide2() <= 0 || GetSide3() <= 0) {
            throw std::invalid_argument("Invalid side lengths. Cannot calculate area, perimeter, and angles.");
        }

        std::cout << "Area: " << CalculateArea() << std::endl;
        std::cout << "Perimeter: " << CalculatePerimeter() << std::endl;
        double angle1, angle2, angle3;
        CalculateAngles(angle1, angle2, angle3);
        std::cout << "Angles: " << angle1 << ", " << angle2 << ", " << angle3 << std::endl;

        if (IsRightTriangle()) {
            std::cout << "The triangle is a right triangle." << std::endl;
        }
        else if (IsIsoscelesTriangle()) {
            std::cout << "The triangle is an isosceles triangle." << std::endl;
        }
        else if (IsEquilateralTriangle()) {
            std::cout << "The triangle is an equilateral triangle." << std::endl;
        }
        else {
            std::cout << "The triangle does not have any specific type." << std::endl;
        }
    }
    catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}



double CTriangle::CalculateArea() const {
    // Використовуємо формулу Герона для знаходження площі трикутника
    double p = CalculatePerimeter() / 2;  // Півпериметр
    return sqrt(p * (p - side1) * (p - side2) * (p - side3));
}

double CTriangle::CalculatePerimeter() const {
    return side1 + side2 + side3;
}


void CTriangle::IncreaseSides() {
    double increaseValue;
    std::cout << "Enter the value to increase the sides: ";
    std::cin >> increaseValue;

    try {
        SetSide1(GetSide1() + increaseValue);
        SetSide2(GetSide2() + increaseValue);
        SetSide3(GetSide3() + increaseValue);
        std::cout << "Triangle sides increased by " << increaseValue << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}


void CTriangle::CalculateAngles(double& angle1, double& angle2, double& angle3) const {
    // Знаходимо косинуси кутів за допомогою формули косинуса
    double cosAngle1 = (side2 * side2 + side3 * side3 - side1 * side1) / (2 * side2 * side3);
    double cosAngle2 = (side1 * side1 + side3 * side3 - side2 * side2) / (2 * side1 * side3);
    double cosAngle3 = (side1 * side1 + side2 * side2 - side3 * side3) / (2 * side1 * side2);

    // Знаходимо кути за допомогою арккосинуса
    angle1 = acos(cosAngle1) * 180 / M_PI;
    angle2 = acos(cosAngle2) * 180 / M_PI;
    angle3 = acos(cosAngle3) * 180 / M_PI;
}

bool CTriangle::IsRightTriangle() const {
    // Використовуємо теорему Піфагора для перевірки, чи трикутник є прямокутним
    return (side1 * side1 + side2 * side2 == side3 * side3) ||
        (side1 * side1 + side3 * side3 == side2 * side2) ||
        (side2 * side2 + side3 * side3 == side1 * side1);
}

bool CTriangle::IsIsoscelesTriangle() const {
    // Перевіряємо чи дві сторони трикутника мають однакову довжину
    return (side1 == side2) || (side1 == side3) || (side2 == side3);
}

bool CTriangle::IsEquilateralTriangle() const {
    // Перевіряємо чи всі три сторони трикутника мають однакову довжину
    return (side1 == side2) && (side1 == side3);
}


