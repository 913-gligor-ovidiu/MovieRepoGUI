#include "Mode.h"

Mode::Mode(Service& adminService, UserService& userService, int repoType, QWidget *parent)
	: QWidget(parent), repoType(repoType), adminService(adminService), userService(userService)
{	
	ui.setupUi(this);

	if (this->repoType == 0)
		this->userService.repositoryType("csv");
	else
		this->userService.repositoryType("html");
	
	QObject::connect(ui.adminButton, &QPushButton::clicked, this, &Mode::adminHandler);
	QObject::connect(ui.userButton, &QPushButton::clicked, this, &Mode::userHandler);
}

Mode::~Mode()
{
}

void Mode::adminHandler()
{	
	AdminGUI* adminWin = new AdminGUI(this->adminService, this->userService);
	adminWin->show();
	//this->hide();
	//delete adminWin;
}

void Mode::userHandler()
{
	UserGUI* userWin = new UserGUI(this->adminService, this->userService);
	userWin->show();
	//this->hide();
}

