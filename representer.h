#ifndef REPRESENTER_H
#define REPRESENTER_H

#include <QPainter>
#include <QtWidgets/QWidget>

#include <vector>
#include <cstdlib>
#include <iostream>

#include "figures.h"

class Representer
{
public:
    Representer();
    ~Representer();

    void represent(QWidget* widget, std::vector<Figures*>* array);
    void draw(Circle* circ);
    void draw(Rectangle* rect);

private:
    QPainter* painter;
};

#endif // REPRESENTER_H

