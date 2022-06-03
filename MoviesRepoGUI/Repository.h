#pragma once
#include <vector>
#include "movie.h"
#include "errors.h"

class Repository {
private:
	std::vector<Movie> adminVector;
	std::string fileName;

public:
	void loadMoviesFromFile();

	void writeMoviesToFile();
	
	Repository(const std::string& filename);
	
	void intialiseRepo();

	const std::vector<Movie> getAll() const { return this->adminVector; }

	int getSize()const { return this->adminVector.size(); }

	void addRepo(const Movie& elem);

	void removeRepo(const std::string& trailer);

	int update(const std::string& trailer, const std::string& field, const std::string& new_info);

	std::vector<Movie>::iterator find(const std::string& trailer);

	Movie findMovie(const std::string& trailer);

	void like(const std::string& trailer);

	Movie& operator[](int index) { return adminVector[index]; }

	~Repository();
};

