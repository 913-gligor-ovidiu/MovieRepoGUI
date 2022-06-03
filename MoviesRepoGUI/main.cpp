#include <QtWidgets/QApplication>
#include "StartWindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

	std::string filename = "Movies.txt.txt";
	Repository adminRepo(filename);
	adminRepo.intialiseRepo();

	Movie_Validation movieValidator;

	Service adminService(adminRepo, movieValidator);
	UserService userService(adminRepo, movieValidator);

    StartWindow w(-1);
    w.exec();
	int t = w.getRepoType();
	if (t == 0) {
		Mode m(adminService, userService, t);
		m.show();
		return a.exec();
	}
	else {
		Mode m(adminService, userService, t);
		m.show();
		return a.exec();
	}
    //return a.exec();
}
