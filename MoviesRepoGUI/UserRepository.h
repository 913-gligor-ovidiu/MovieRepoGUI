#pragma once
#include <vector>
#include "movie.h"

class UserRepository{
protected:
	std::vector<Movie> watchlist;
	std::string fileName;

public:
	std::vector<Movie> const getAll();
	int getSize();;
	void addUserRepo(const Movie& movie);
	void removeUserRepo(const std::string& trailer);
	std::vector<Movie>::iterator find(const std::string& trailer);

	virtual void writeToFile() = 0;
	virtual std::string& getFilename() = 0;
	
};

