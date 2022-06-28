#pragma once

#include <iostream>
#include <string_view>
#include <cmath>

static const double PI = acos(-1);
std::string_view listColors[]{ "RED", "GREEN", "BLUE" };
std::string_view listFigures[]{ "triangle", "circle", "square", "rectangle" };

enum Color
{
    RED,
    GREEN,
    BLUE,
    NONE
};

struct Coordinate
{
    double x = 0.0;
    double y = 0.0;
};

class Figure
{
public:

    Figure()
    {
        std::cout << "Enter the coordinates of the center of the shape (x, y): ";
        std::cin >> coord.x >> coord.y;
        std::cout << std::endl << "Enter one of available colors:" << std::endl;
        for (const auto& c : listColors)
        {
            std::cout << "  " << c << ";" << std::endl;
        }
            
        std::cout << std::endl << "Choose the shape color: ";
        std::string tmpColor = "";
        while (color == NONE)
        {
            std::cin >> tmpColor;
            for (int i = 0; i < tmpColor.size(); ++i)
            {
                tmpColor[i] = std::toupper(tmpColor[i]);
            }
      
            if (tmpColor == "RED")
            {
                color = RED;
            }
            else if (tmpColor == "GREEN")
            {
                color = GREEN;
            }
            else if (tmpColor == "BLUE")
            {
                color = BLUE;
            }
            else
            {
                std::cout << "! Incorrect color. Try again !" << std::endl;
            }        
        }
    }

    std::string getColor()
    {
        switch (color)
        {
        case RED: return "red";
        case GREEN: return "green";
        case BLUE: return "blue";
        }
        return "Not found";
    }

    Coordinate getCenterCoordinate()
    {
        return coord;
    }

    double getOutsideRectFirstSide()
    { 
        return outsideRectSide1; 
    }

    double getOutsideRectSecondSide() 
    {
        return outsideRectSide2; 
    }

    virtual double getAreaFigure() = 0;

protected:

    Coordinate coord;
    Color color = NONE;
    double outsideRectSide1 = 0.0;
    double outsideRectSide2 = 0.0;
};

class Circle : public Figure
{
public:

    Circle()
    {
        std::cout << "Enter circle radius: ";
        while (radius <= 0)
        {
            std::cin >> radius;
            if (radius <= 0)
                std::cout << "Incorrect radius. Try again" << std::endl;
        }

        outsideRectSide1 = radius * 2;
        outsideRectSide2 = outsideRectSide1;

        system("cls");
    }

    virtual double getAreaFigure()
    {
        return (PI * radius * radius);
    }

protected:

    double radius = 0;
};

class Triangle : public Figure
{
public:

    Triangle()
    {
        std::cout << "Enter triangle side: ";
        while (side <= 0)
        {
            std::cin >> side;
            if (side <= 0)
                std::cout << "Incorrect side. Try again" << std::endl;
        }

        outsideRectSide1 = sqrt(3) / 3 * side * 2;
        outsideRectSide2 = outsideRectSide1;

        system("cls");
    }
    virtual double getAreaFigure()
    {
        return (side * side * sqrt(3) / 4);
    }

protected:

    double side = 0.0;
};

class Square : public Figure
{
public:

    Square()
    {
        std::cout << "Enter square's side: ";
        while (side <= 0)
        {
            std::cin >> side;
            if (side <= 0)
                std::cout << "Incorrect side. Try again" << std::endl;
        }

        outsideRectSide1 = side;
        outsideRectSide2 = side;

        system("cls");
    }
    virtual double getAreaFigure()
    {
        return (side * side);
    }
protected:

    double side = 0.0;
};

class Rectangle : public Figure
{
public:

    Rectangle()
    {
        std::cout << "Enter the length of the first side of the rectangle: ";
        side1 = enterSide();
        std::cout << "Enter the length of the second side of the rectangle: ";
        side2 = enterSide();

        outsideRectSide1 = side1;
        outsideRectSide2 = side2;

        system("cls");
    }
    virtual double getAreaFigure()
    {
        return side1 * side2;
    }
protected:

    double side1 = 0.0;
    double side2 = 0.0;

    double enterSide()
    {
        double tmp = 0;
        while (tmp <= 0)
        {
            std::cin >> tmp;
            if (tmp <= 0)
                std::cout << "Incorrect side. Try again" << std::endl;
        }

        return tmp;
    }
};