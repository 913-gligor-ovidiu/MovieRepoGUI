#pragma once

#include <QWidget>
#include "ui_StartWindow.h"
#include "Mode.h"
#include "UserService.h"
#include <QtWidgets/QDialog>
#include "service.h"

class StartWindow : public QDialog
{
	Q_OBJECT

public:
	StartWindow(int repoType);
	~StartWindow();

private:
	Ui::Form ui;
	int repoType;

public:
	void csvHandler();
	void htmlHandler();
	int getRepoType() { return this->repoType; }
};
