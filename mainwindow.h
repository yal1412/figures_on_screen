#pragma once

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>

#include <vector>

#include "pencil_eraser.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    Pencil_Eraser* pencil;
    Representer* representer;

    void paintEvent(QPaintEvent* paint_event);
    void mousePressEvent(QMouseEvent* mouse_event);
};
#endif // MAINWINDOW_H
