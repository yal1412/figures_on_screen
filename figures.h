#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>

class Representer;

struct Coordinates
{
    int x;
    int y;
};

class Figures // Родительский класс фигуры
{
public:

    Coordinates center_point;
    int width;
    int height;

    Figures() {}
    ~Figures() {}

    virtual Coordinates Get_Center_Point()=0;
    virtual void Draw_Figure(Representer* representer)=0;

    std::pair<double, double> Get_H_and_W()
    {
        return std::make_pair(height, width);
    }

    virtual bool is_Point_In_Figure(Coordinates point)=0;

};
#endif // FIGURE_H


#ifndef CIRCLE_H
#define CIRCLE_H

class Circle : public Figures // Класс круг - наследуется от фигур
{
public:

    Circle(Coordinates center, int height, int width);
    static Circle* Create_Circle(Coordinates center, int radius);

    //то что унаследовали
    Coordinates Get_Center_Point();
    void Draw_Figure(Representer *representer);
    bool is_Point_In_Figure(Coordinates point);
};

#endif // CIRCLE_H


#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle : public Figures //Класс прямоугольник - наследуется от фигур
{
public:
    Rectangle(Coordinates center, int width, int height);

    Coordinates Get_Center_Point();
    void Draw_Figure(Representer* representer);
    bool is_Point_In_Figure(Coordinates point);
};

#endif // RECTANGLE_H
