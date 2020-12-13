#include "pencil_eraser.h"

Pencil_Eraser::Pencil_Eraser()
{
    array = new std::vector<Figures*>();
}

Pencil_Eraser::~Pencil_Eraser()
{
    for (auto ptr : *array)
    {
        delete ptr;
    }
    delete array;
}

std::vector<Figures*>* Pencil_Eraser::get()
{
    return array;
}

void Pencil_Eraser::draw(Coordinates point)
{
    Figures* newFigure = Create_New(point);
    array->push_back(newFigure);
}

void Pencil_Eraser::erase(Coordinates point)
{
    std::vector<Figures*>::iterator iter;
    iter = array->begin();

    while(iter != array->end())
    {
        Figures* figure = *iter;

        if (figure->is_Point_In_Figure(point))
        {
            array->erase(iter);
        }
        else
        {
            ++iter;
        }
    }

}

Figures* Pencil_Eraser::Create_New(Coordinates point)
{
    int t = rand() % 2;
    Figures* newFigure;

    if (t == 0)
    {
        int w = rand() % 250;
        int h = rand() % 250;

        while ((w < 10) || (h < 10))
        {
            w = rand() % 250;
            h = rand() % 250;
        }
        newFigure = new Rectangle(point, w, h);
    }
    else
    {
        int r = rand() % 250;

        while (r < 10)
            r = rand() % 250;

        newFigure = Circle::Create_Circle(point, r);
    }
    return newFigure;
}
