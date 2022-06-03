#pragma once

#include <QWidget>
#include "ui_ModelViewWindow.h"
#include <QAbstractItemModel>
#include <memory>

class ModelViewWindow : public QWidget
{
	Q_OBJECT

public:
	ModelViewWindow(QAbstractItemModel* model ,QWidget *parent = Q_NULLPTR);
	~ModelViewWindow();

private:
	Ui::ModelViewWindow ui;
};
