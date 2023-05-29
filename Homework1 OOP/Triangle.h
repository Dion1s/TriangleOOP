#pragma once
#include <iostream>
#include <cmath>
class CTriangle {
private:
    double side1;
    double side2;
    double side3;

public:
    CTriangle();  // ����������� �� �������������
    CTriangle(double s1, double s2, double s3);  // ����������� � �����������

    ~CTriangle();  // ����������

    // ������-������� ��� ���������� ������� ����
    double GetSide1() const;
    double GetSide2() const;
    double GetSide3() const;

    // ������-������� ��� ��������� ������� ����
    void SetSide1(double s1);
    void SetSide2(double s2);
    void SetSide3(double s3);

    // ������ ��� ������ �� ����� �����
    void console_input();
    void console_output() const;

    double CalculateArea() const;  // ����������� ����� ����������
    double CalculatePerimeter() const;  // ����������� ��������� ����������
    void IncreaseSides(); // ��������� ��� ����� ����� �� ���������
    bool IsRightTriangle() const;  // �������� �� ��������� � �����������
    bool IsIsoscelesTriangle() const;  // �������� �� ��������� � ������������
    bool IsEquilateralTriangle() const;  // �������� �� ��������� � ������������
    void CalculateAngles(double& angle1, double& angle2, double& angle3) const;  // ����������� ����� ���� ����������
};