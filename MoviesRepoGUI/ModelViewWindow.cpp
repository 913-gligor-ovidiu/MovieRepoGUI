#include "ModelViewWindow.h"

ModelViewWindow::ModelViewWindow(QAbstractItemModel* model, QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	ui.moviesTable->setModel(model);
}

ModelViewWindow::~ModelViewWindow()
{
}
