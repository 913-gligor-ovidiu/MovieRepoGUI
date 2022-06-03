#pragma once
#include <string>

class Movie {

private:
	std::string name;
	std::string genre;
	int year, nrLikes;
	std::string trailer;

public:

	Movie() :name{ "" }, genre{ "" }, year{ 0 }, nrLikes{ 0 }, trailer{ "" }{}
	Movie(const std::string& name, const std::string& genre, const int year, const int nrLikes, const std::string& trailer);

	std::string getName() const { return this->name; }
	std::string getGenre() const { return this->genre; }
	std::string getTrailer() const { return this->trailer; }
	int getYear() const { return this->year; }
	int getNrLikes() const { return this->nrLikes; }

	void setName(const std::string& name) { this->name = name; }
	void setGenre(const std::string& genre) { this->genre = genre; }
	void setTrailer(const std::string& trailer) { this->trailer = trailer; }
	void setYear(const int year) { this->year = year; }
	void setNrLikes() { this->nrLikes++; }

	Movie& operator=(const Movie& new_movie);
	bool operator==(const Movie& other_movie);
	friend std::ostream& operator<<(std::ostream& writer, const Movie& movie);
	friend std::istream& operator>>(std::istream& is, Movie& m);

};