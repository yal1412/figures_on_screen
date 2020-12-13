#ifndef PENCIL_ERASER_H
#define PENCIL_ERASER_H

#include "representer.h"

class Pencil_Eraser
{
public:
    Pencil_Eraser();
    ~Pencil_Eraser();

    std::vector<Figures*>* get();

    void draw(Coordinates point);
    void erase(Coordinates point);

    Figures* Create_New(Coordinates point);

    std::vector<Figures*>* array;
};

#endif // PENCIL_ERASER_H
