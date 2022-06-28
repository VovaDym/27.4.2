#include <iostream>
#include <string>
#include "figure.h"


bool isCorrectFigure(std::string& entered)
{
    for (int i = 0; i < entered.size(); ++i)
    {
        entered[i] = std::tolower(entered[i]);
    }
        
    for (const auto& f : listFigures)
    {
        if (entered == f)
        {
            return true;
        }       
    }   

    std::cout << "Incorrect figure. Try again" << std::endl;
    return false;
}

int main()
{
    system ("cls");

    std::cout << "List of geometric shapes: " << std::endl;
    for (const auto& f : listFigures)
    {
        std::cout << " -" << f << ";" << std::endl;
    }
    std::cout << std::endl;

    std::string answer = "";
    do
    {
        std::cin >> answer;
    } 
    while (!isCorrectFigure(answer));

    int option = 0;
    while (answer != listFigures[option])
    {
        ++option;
    }
       
    system("cls");

    Figure* figure;
    switch (option)
    {
    case 0:
        figure = new Triangle();
        std::cout << "An isosceles triangle is constructed!" << std::endl;
        break;

    case 1:
        figure = new Circle();
        std::cout << "The circle is built!" << std::endl;
        break;

    case 2:
        figure = new Square();
        std::cout << "The square is built!" << std::endl;
        break;

    case 3:
        figure = new Rectangle();
        std::cout << "The rectangle is built!" << std::endl;
        break;
    default:
        std::cout << "Figure wasn't built!" << std::endl;
        break;
    }
    std::cout << "Color: " << figure->getColor() << std::endl;
    std::cout << "Square: " << figure->getAreaFigure() << std::endl;
    std::cout << "The first outer side of the rectangle: " << figure->getOutsideRectFirstSide() << std::endl;
    std::cout << "The second outer side of the rectangle: " << figure->getOutsideRectSecondSide() << std::endl;
}