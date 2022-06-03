#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MoviesRepoGUI.h"

class MoviesRepoGUI : public QMainWindow
{
    Q_OBJECT

public:
    MoviesRepoGUI(QWidget *parent = Q_NULLPTR);

private:
    Ui::MoviesRepoGUIClass ui;
};
