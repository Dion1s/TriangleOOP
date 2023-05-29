#include "Triangle.h"
#include <iostream>

int main() {
    CTriangle triangle{};
    int choice = 0;
    char operation;

    do {
        std::cout << "------------------------------------\n";
        std::cout << "Enter the value to select" << '\n';
        std::cout << "1 - input sides: \n";
        std::cout << "2 - output all informations\n";
        std::cout << "3 - if you want to increase the value of all sides\n";
        std::cout << "4 - if you want to erase previous data\n";
        std::cout << "0 - exit\n";
        std::cout << "------------------------------------\n";
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            triangle.console_input();
            break;
        case 2:
            triangle.console_output();
            break;
        case 3:
            triangle.IncreaseSides();
            break;
        case 4:
            triangle = CTriangle();  // Створюємо новий об'єкт CTriangle, що замінює попередні дані
            std::cout << "The operation is successful\n";
            break;
        default:
            std::cout << "Incorrect value entered, try again\n";
            break;
        }
    } while (choice != 0);
    
    return 0;
}
