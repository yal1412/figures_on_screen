#include <QMouseEvent>

#include "mainwindow.h"
#include "ui_mainwindow.h"

Coordinates To_Coordinates(QPointF point)
{
    Coordinates coord;
    coord.x = point.x();
    coord.y = point.y();
    return coord;
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    representer = new Representer();
    pencil = new Pencil_Eraser();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete representer;
    delete pencil;
}


void MainWindow::paintEvent(QPaintEvent* paint_event)
{
    representer->represent(this, pencil->get());
    QMainWindow::paintEvent(paint_event);
}

void MainWindow::mousePressEvent(QMouseEvent* mouse_event)
{

    if (mouse_event->button() == Qt::LeftButton)
    {
        pencil->draw(To_Coordinates(mouse_event->windowPos()));
    }
    else if (mouse_event->button() == Qt::RightButton)
    {
        pencil->erase(To_Coordinates(mouse_event->windowPos()));
    }

    repaint();

    QMainWindow::mousePressEvent(mouse_event);
}
