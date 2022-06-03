#include "UserGUI.h"

UserGUI::UserGUI(Service& adminService, UserService& userService, QWidget *parent)
	: QWidget(parent) , userService(userService), adminService(adminService)
{
	ui.setupUi(this);
	this->populate();
	this->connectAll();
}

UserGUI::~UserGUI()
{
}

void UserGUI::addHandler()
{
	QString name = ui.nameLine->text();
	QString genre = ui.genreLine->text();
	QString year = ui.yearLine->text();
	QString nrLikes = ui.likesLine->text();
	QString trailer = ui.trailerLine->text();

	try {
		this->userService.addService(name.toStdString(), genre.toStdString(), year.toInt(), nrLikes.toInt(), trailer.toStdString());
	}
	catch (RepoError& re) {
		return;
	}
	this->populate();

	ui.nameLine->clear();
	ui.genreLine->clear();
	ui.yearLine->clear();
	ui.likesLine->clear();
	ui.trailerLine->clear();
}

void UserGUI::removeHandler()
{
	if (!ui.watchlist->currentItem()->text().isEmpty()) {
		QString movie = ui.watchlist->currentItem()->text();
		auto movies = this->userService.getAllSrv();
		for (auto elem : movies)
		{
			QString itemInList = QString::fromStdString(elem.getName() + "|" + elem.getGenre() +
				"|" + std::to_string(elem.getYear()) + "|" + std::to_string(elem.getNrLikes()) +
				"|" + elem.getTrailer());
			if (movie == itemInList)
				this->userService.removeService(elem.getTrailer());
		}
		this->populate();
		ui.nameLine->clear();
		ui.genreLine->clear();
		ui.yearLine->clear();
		ui.likesLine->clear();
		ui.trailerLine->clear();
	}
	return;
}

void UserGUI::nextHandler()
{	
	int pos = 0;
	if (!ui.filterLine->text().isEmpty())
	{
		auto movies = this->adminService.getAllSrv();
		for( int i = 0; i < this->adminService.getRepoSize(); i++) {
			QString gen = QString::fromStdString(movies[i].getGenre());
			if ((gen == ui.filterLine->text()|| ui.filterLine->text() == "all") && this->index == pos)
			{
				this->ui.nameLine->setText(QString::fromStdString(movies[i].getName()));
				this->ui.genreLine->setText(QString::fromStdString(movies[i].getGenre()));
				this->ui.yearLine->setText(QString::number(movies[i].getYear()));
				this->ui.likesLine->setText(QString::number(movies[i].getNrLikes()));
				this->ui.trailerLine->setText(QString::fromStdString(movies[i].getTrailer()));
				this->index++;
				break;
			}
			else if ((ui.filterLine->text() == "all" || gen == ui.filterLine->text()) && this->index > pos)
				pos++;
			if(i == this->adminService.getRepoSize() - 1)
				i = -1;
		}
	}
}

void UserGUI::listItemSelected()
{
	QString movie = ui.watchlist->currentItem()->text();
	auto movies = this->userService.getAllSrv();
	for (auto elem : movies)
	{
		QString itemInList = QString::fromStdString(elem.getName() + "|" + elem.getGenre() +
			"|" + std::to_string(elem.getYear()) + "|" + std::to_string(elem.getNrLikes()) +
			"|" + elem.getTrailer());
		if (movie == itemInList)
		{
			this->ui.nameLine->setText(QString::fromStdString(elem.getName()));
			this->ui.genreLine->setText(QString::fromStdString(elem.getGenre()));
			this->ui.yearLine->setText(QString::number(elem.getYear()));
			this->ui.likesLine->setText(QString::number(elem.getNrLikes()));
			this->ui.trailerLine->setText(QString::fromStdString(elem.getTrailer()));
		}
	}
}

void UserGUI::openInFile()
{
	std::string link = std::string("start ").append(this->userService.getFileService());
	system(link.c_str());
}

void UserGUI::populate()
{
	ui.watchlist->clear();
	auto movies = this->userService.getAllSrv();
	for (auto elem : movies)
	{
		QString itemInList = QString::fromStdString(elem.getName() + "|" + elem.getGenre() +
			"|" + std::to_string(elem.getYear()) + "|" + std::to_string(elem.getNrLikes()) +
			"|" + elem.getTrailer());
		QListWidgetItem* item = new QListWidgetItem{ itemInList };
		ui.watchlist->addItem(item);
	}
}

void UserGUI::filterHandler()
{
	this->index = 0;
	if (!ui.filterLine->text().isEmpty())
	{
		auto movies = this->adminService.getAllSrv();
		for (auto elem : movies) {
			QString gen = QString::fromStdString(elem.getGenre());
			if (gen == ui.filterLine->text() || ui.filterLine->text() == "all")
			{
				this->ui.nameLine->setText(QString::fromStdString(elem.getName()));
				this->ui.genreLine->setText(QString::fromStdString(elem.getGenre()));
				this->ui.yearLine->setText(QString::number(elem.getYear()));
				this->ui.likesLine->setText(QString::number(elem.getNrLikes()));
				this->ui.trailerLine->setText(QString::fromStdString(elem.getTrailer()));
				this->index++;
				break;
			}
		}
	}
}

void UserGUI::connectAll()
{
	QObject::connect(ui.addButton, &QPushButton::clicked, this, &UserGUI::addHandler);
	QObject::connect(ui.removeButton, &QPushButton::clicked, this, &UserGUI::removeHandler);
	QObject::connect(ui.nextButton, &QPushButton::clicked, this, &UserGUI::nextHandler);
	QObject::connect(ui.filterButton, &QPushButton::clicked, this, &UserGUI::filterHandler);
	QObject::connect(ui.likeButton, &QPushButton::clicked, this, &UserGUI::likeHandler);
	QObject::connect(ui.openButton, &QPushButton::clicked, this, &UserGUI::openInFile);
	QObject::connect(ui.watchlist, &QListWidget::itemSelectionChanged, this, &UserGUI::listItemSelected);
}

void UserGUI::likeHandler()
{	
	if (!ui.watchlist->currentItem()->text().isEmpty()) {
		QString movie = ui.watchlist->currentItem()->text();
		auto movies = this->userService.getAllSrv();
		for (auto elem : movies)
		{
			QString itemInList = QString::fromStdString(elem.getName() + "|" + elem.getGenre() +
				"|" + std::to_string(elem.getYear()) + "|" + std::to_string(elem.getNrLikes()) +
				"|" + elem.getTrailer());
			if (movie == itemInList) {
				std::string t = elem.getTrailer();
				this->userService.likeService(t);
				this->populate();
			}
		}
	}
}
