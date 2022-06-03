#pragma once

#include <QWidget>
#include "ui_Mode.h"
#include "service.h"
#include "UserService.h"
#include "AdminGUI.h"
#include "UserGUI.h"

class Mode : public QWidget
{
	Q_OBJECT

public:
	Mode(Service& adminService, UserService& userService, int repoType,QWidget *parent = Q_NULLPTR);
	~Mode();

private:
	Ui::Mode ui;
	int repoType;
	Service& adminService;
	UserService& userService;

public:
	void adminHandler();
	void userHandler();
};
