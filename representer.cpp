#include "representer.h"
#include "figures.h"

Representer::Representer(){}

Representer::~Representer()
{
    delete painter;
}

void Representer::draw(Circle* circ)
{
    Coordinates center = circ->Get_Center_Point();
    painter->drawEllipse(center.x, center.y, circ->Get_H_and_W().first , circ->Get_H_and_W().second);
}

void  Representer::draw(Rectangle* rect)
{
    Coordinates left_top = rect->Get_Center_Point();
    painter->drawRect(left_top.x, left_top.y, rect->Get_H_and_W().first, rect->Get_H_and_W().second);
}

void Representer::represent(QWidget* widget, std::vector<Figures*>* array)
{
    painter = new QPainter(widget);
    painter->setRenderHint(QPainter::Antialiasing, true);
    painter->setPen(QPen(Qt::white));

    for(auto fig : *array)
    {
        painter->setBrush(QBrush(QColor(0, 150, 100)));
        fig->Draw_Figure(this);
    }

    painter->end();
}
