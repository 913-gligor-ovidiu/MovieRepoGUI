#pragma once

#include <QWidget>
#include "ui_AdminGUI.h"
#include "Mode.h"
#include "MoviesModel.h"
#include "ModelViewWindow.h"
#include <QKeyEvent>

class AdminGUI : public QWidget
{
	Q_OBJECT

public:
	AdminGUI(Service& adminService, UserService& userService, QWidget *parent = Q_NULLPTR);
	~AdminGUI();

private:
	Ui::AdminGUI ui;
	void addHandler();
	void removeHandler();
	void updateHandler();
	void undoHandler();
	void redoHandler();
	void keyPressEvent(QKeyEvent* _event)override;
	void openTableHandler();
	void listItemSelected();
	void filterHandler();
	void populate();
	void connectAll();
	Service& adminService;
	UserService& userService;
};
