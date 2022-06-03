#include "StartWindow.h"

StartWindow::StartWindow(int repoType)
	: repoType(repoType)
{
	ui.setupUi(this);
	QObject::connect(ui.csvButton, &QPushButton::clicked, this, &StartWindow::csvHandler);
	QObject::connect(ui.htmlButton, &QPushButton::clicked, this, &StartWindow::htmlHandler);
}

StartWindow::~StartWindow()
{
}

void StartWindow::csvHandler()
{
	this->repoType = 0;
	this->close();
}

void StartWindow::htmlHandler()
{
	this->repoType = 1;
	this->close();
}
