#pragma once
#include <iostream>
#include <cmath>
class CTriangle {
private:
    double side1;
    double side2;
    double side3;

public:
    CTriangle();  // конструктор за замовчуванням
    CTriangle(double s1, double s2, double s3);  // конструктор з параметрами

    ~CTriangle();  // деструктор

    // Методи-геттери для зчитування значень полів
    double GetSide1() const;
    double GetSide2() const;
    double GetSide3() const;

    // Методи-сеттери для задавання значень полів
    void SetSide1(double s1);
    void SetSide2(double s2);
    void SetSide3(double s3);

    // методи для виводу та вводу даних
    void console_input();
    void console_output() const;

    double CalculateArea() const;  // Знаходження площі трикутника
    double CalculatePerimeter() const;  // Знаходження периметра трикутника
    void IncreaseSides(); // Збільшення всіх трьох сторін на константу
    bool IsRightTriangle() const;  // Перевірка чи трикутник є прямокутним
    bool IsIsoscelesTriangle() const;  // Перевірка чи трикутник є рівнобедреним
    bool IsEquilateralTriangle() const;  // Перевірка чи трикутник є рівностороннім
    void CalculateAngles(double& angle1, double& angle2, double& angle3) const;  // Знаходження трьох кутів трикутника
};