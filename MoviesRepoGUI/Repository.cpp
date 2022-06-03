#include "Repository.h"
#include <fstream>

Repository::Repository(const std::string& filename) :fileName{ filename }{}

void Repository::loadMoviesFromFile(){
	std::ifstream file(this->fileName);
	Movie m;

	if (!file.is_open())
		throw RepoError("The file could not be opened!");
	
	while (file >> m)
		this->adminVector.push_back(m);

	file.close();
}

void Repository::writeMoviesToFile(){
	std::ofstream file(this->fileName);
	if (!file.is_open())
		throw RepoError("The file could not be opened!");

	for (auto m : this->adminVector)
		file << m;

	file.close();
}

void Repository::intialiseRepo()
{
	this->loadMoviesFromFile();
}

void Repository::addRepo(const Movie& elem)
{
	if (find(elem.getTrailer()) != this->adminVector.end())
		throw RepoError("Movie already exists!");

	this->adminVector.push_back(elem);
	this->writeMoviesToFile();
}

void Repository::removeRepo(const std::string& trailer)
{
	std::vector<Movie>::iterator it = find(trailer);
	if (it == this->adminVector.end())
		throw RepoError("Movie doesnt exists!");

	this->adminVector.erase(it);
	this->writeMoviesToFile();
}

int Repository::update(const std::string& trailer, const std::string& field, const std::string& new_info)
{
	std::vector<Movie>::iterator it;
	it = find(trailer);
	if (it == this->adminVector.end())
		throw RepoError("Movie doesnt exists!");

	int index = it - this->adminVector.begin();
	if (field == "name")
		this->adminVector[index].setName(new_info);

	if (field == "genre")
		this->adminVector[index].setGenre(new_info);

	if (field == "year")
	{
		int year;
		year = stoi(new_info);
		this->adminVector[index].setYear(year);
	}
	this->writeMoviesToFile();
}

std::vector<Movie>::iterator Repository::find(const std::string& trailer)
{
	std::vector<Movie>::iterator it;
	it = std::find_if(this->adminVector.begin(), this->adminVector.end(), [&trailer](const Movie& obj) {return obj.getTrailer() == trailer; });
	return it;
}

Movie Repository::findMovie(const std::string& trailer)
{
	for (auto m : this->adminVector)
	{
		if (m.getTrailer() == trailer)
			return m;
	}
}

void Repository::like(const std::string& trailer)
{
	std::vector<Movie>::iterator it = find(trailer);
	int pos = it - this->adminVector.begin();
	this->adminVector[pos].setNrLikes();
	this->writeMoviesToFile();
}


Repository::~Repository() = default;
