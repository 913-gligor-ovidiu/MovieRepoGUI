#include "AdminGUI.h"

AdminGUI::AdminGUI(Service& adminService, UserService& userService, QWidget *parent)
	: QWidget(parent), adminService(adminService), userService(userService)
{
	ui.setupUi(this);
	this->populate();
	this->connectAll();
}

AdminGUI::~AdminGUI()
{
}

void AdminGUI::addHandler()
{
	QString name = ui.nameLine->text();
	QString genre = ui.genreLine->text();
	QString year = ui.yearLine->text();
	QString nrLikes = ui.nrLikesLine->text();
	QString trailer = ui.trailerLine->text();
	try {
		this->adminService.addService(name.toStdString(), genre.toStdString(), year.toInt(), nrLikes.toInt(), trailer.toStdString());
	}
	catch (RepoError& re) {
		return;
	}
	catch (ValidError& ve) {
		return;
	}
	this->populate();

	ui.nameLine->clear();
	ui.genreLine->clear();
	ui.yearLine->clear();
	ui.nrLikesLine->clear();
	ui.trailerLine->clear();
}

void AdminGUI::removeHandler()
{
	if (!this->ui.trailerLine->text().isEmpty()) {
		QString movie = ui.movieList->currentItem()->text();
		auto movies = this->adminService.getAllSrv();
		for (auto elem : movies)
		{
			QString itemInList = QString::fromStdString(elem.getName() + "|" + elem.getGenre() +
				"|" + std::to_string(elem.getYear()) + "|" + std::to_string(elem.getNrLikes()) +
				"|" + elem.getTrailer());
			if (movie == itemInList)
				this->adminService.removeService(elem.getTrailer());
		}
		this->populate();
		ui.nameLine->clear();
		ui.genreLine->clear();
		ui.yearLine->clear();
		ui.nrLikesLine->clear();
		ui.trailerLine->clear();
	}
	return;
}

void AdminGUI::updateHandler()
{
	QString movie = ui.movieList->currentItem()->text();
	auto movies = this->adminService.getAllSrv();
	for (auto elem : movies)
	{
		QString itemInList = QString::fromStdString(elem.getName() + "|" + elem.getGenre() +
			"|" + std::to_string(elem.getYear()) + "|" + std::to_string(elem.getNrLikes()) +
			"|" + elem.getTrailer());
		if (movie == itemInList)
		{
			this->adminService.removeService(elem.getTrailer());
		}
	}
	QString name = ui.nameLine->text();
	QString genre = ui.genreLine->text();
	QString year = ui.yearLine->text();
	QString nrLikes = ui.nrLikesLine->text();
	QString trailer = ui.trailerLine->text();
	this->adminService.addService(name.toStdString(), genre.toStdString(), year.toInt(), nrLikes.toInt(), trailer.toStdString());
	this->populate();
	ui.nameLine->clear();
	ui.genreLine->clear();
	ui.yearLine->clear();
	ui.nrLikesLine->clear();
	ui.trailerLine->clear();
}

void AdminGUI::undoHandler()
{
	this->adminService.undo();
	this->populate();
}

void AdminGUI::redoHandler()
{
	this->adminService.redo();
	this->populate();
}

void AdminGUI::keyPressEvent(QKeyEvent* _event)
{
	if (!(_event->modifiers() && Qt::ControlModifier))
		return;

	if (_event->key() == Qt::Key_Z)
	{
		this->undoHandler();
		return;
	}
	if (_event->key() == Qt::Key_Y)
	{
		this->redoHandler();
	}

}

void AdminGUI::openTableHandler()
{
	auto model = new MoviesModel{ this->adminService };

	ModelViewWindow* tableWin = new ModelViewWindow(model);
	tableWin->show();
}

void AdminGUI::filterHandler()
{
	this->ui.movieList->clear();
	
	std::string editText = this->ui.filterLine->text().toStdString();
	while (!editText.empty()&& editText[editText.size()-1]==' ')
		editText.pop_back();
	std::reverse(editText.begin(), editText.end());
	while (!editText.empty() && editText[editText.size() - 1] == ' ')
		editText.pop_back();
	std::reverse(editText.begin(), editText.end());

	if (editText.empty())
	{
		std::vector<Movie> movies = this->adminService.getAllSrv();
		for (auto m : movies)
		{
			QString text = QString::fromStdString(m.getName() + "," + m.getGenre() + "," +
				std::to_string(m.getYear()) + "," +
				std::to_string(m.getNrLikes()) + "," +
				m.getTrailer());
			QListWidgetItem* item = new QListWidgetItem{ text };
			this->ui.movieList->addItem(item);
		}
		return;
	}
	std::vector<Movie> movies = this->adminService.getAllSrv();
	for (auto m : movies)
	{
		QString text = QString::fromStdString(m.getName() + "," + m.getGenre() + "," +
			std::to_string(m.getYear()) + "," +
			std::to_string(m.getNrLikes()) + "," +
			m.getTrailer());
		std::string stringItem = text.toStdString();
		if (stringItem.find(editText) != std::string::npos)
		{
			QListWidgetItem* item = new QListWidgetItem{ text };
			this->ui.movieList->addItem(item);
		}
	}
}



void AdminGUI::listItemSelected()
{
	QString movie = ui.movieList->currentItem()->text();
	auto movies = this->adminService.getAllSrv();
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
			this->ui.nrLikesLine->setText(QString::number(elem.getNrLikes()));
			this->ui.trailerLine->setText(QString::fromStdString(elem.getTrailer()));
		}
	}
}

void AdminGUI::populate()
{
	ui.movieList->clear();
	auto movies = this->adminService.getAllSrv();
	for (auto elem : movies)
	{
		QString itemInList = QString::fromStdString(elem.getName() + "|" + elem.getGenre() +
			"|" + std::to_string(elem.getYear()) + "|" + std::to_string(elem.getNrLikes()) +
			"|" + elem.getTrailer());
		QListWidgetItem* item = new QListWidgetItem{ itemInList };
		ui.movieList->addItem(item);
	}
}

void AdminGUI::connectAll()
{
	QObject::connect(ui.addButton, &QPushButton::clicked, this, &AdminGUI::addHandler);
	QObject::connect(ui.removeButton, &QPushButton::clicked, this, &AdminGUI::removeHandler);
	QObject::connect(ui.updateButton, &QPushButton::clicked, this, &AdminGUI::updateHandler);
	QObject::connect(ui.movieList, &QListWidget::itemSelectionChanged, this, &AdminGUI::listItemSelected);
	QObject::connect(ui.filterLine, &QLineEdit::textChanged, this, &AdminGUI::filterHandler);
	QObject::connect(ui.undoButton, &QPushButton::clicked, this, &AdminGUI::undoHandler);
	QObject::connect(ui.redoButton, &QPushButton::clicked, this, &AdminGUI::redoHandler);
	QObject::connect(ui.openTableButton, &QPushButton::clicked, this, &AdminGUI::openTableHandler);
}
