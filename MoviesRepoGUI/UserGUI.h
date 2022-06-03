#pragma once

#include <QWidget>
#include "ui_UserGUI.h"
#include "Mode.h"

class UserGUI : public QWidget
{
	Q_OBJECT

public:
	UserGUI(Service& adminService, UserService& userService, QWidget *parent = Q_NULLPTR);
	~UserGUI();

private:
	Ui::UserGUI ui;
	UserService& userService;
	Service& adminService;
	int index;
	void addHandler();
	void removeHandler();
	void nextHandler();
	void listItemSelected();
	void openInFile();
	void populate();
	void likeHandler();
	void filterHandler();
	void connectAll();
};
