#include "figures.h"
#include "representer.h"

Circle::Circle(Coordinates center, int width, int height)
{

    this->center_point = center;
    this->width = width;
    this->height = height;
}

Circle* Circle::Create_Circle(Coordinates center, int radius) // рисуем круг
{
    Circle* newCircle = new Circle(center, radius * 2, radius * 2);
    return newCircle;
}

void Circle::Draw_Figure(Representer *representer)
{
    representer->draw(this);
}

Coordinates Circle::Get_Center_Point()
{
    Coordinates cp;
    cp.x = center_point.x - width / 2;
    cp.y = center_point.y - height / 2;

    return cp;
}

bool Circle::is_Point_In_Figure(Coordinates point)
{
    int radius = width / 2;
    int delta_x = point.x - center_point.x;
    int delta_y = point.y - center_point.y;
    int squared_dist = delta_x * delta_x + delta_y * delta_y;

    return (squared_dist <= radius * radius);
}

Coordinates Rectangle::Get_Center_Point()
{
    Coordinates cp;
    cp.x = center_point.x - width / 2;
    cp.y = center_point.y - height / 2;

    return cp;
}

Rectangle::Rectangle(Coordinates center, int width, int height)
{
    this->center_point = center;
    this->width = width;
    this->height = height;

}

void Rectangle::Draw_Figure(Representer* representer)
{
    representer->draw(this);
}

bool Rectangle::is_Point_In_Figure(Coordinates point)
{
    int half_height = height / 2;
    int half_width = width / 2;
    return (point.x >= center_point.x - half_width) and (point.x <= center_point.x + half_width) and
           (point.y >= center_point.y - half_height) and (point.y <= center_point.y + half_height);
}
