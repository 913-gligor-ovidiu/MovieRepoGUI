#include <iostream>
#include <string.h>
#include <vector>
#include "movie.h"

Movie::Movie(const std::string& name, const std::string& genre, const int year, const int nrLikes, const std::string& trailer)
	:name{ name }, genre{ genre }, year{ year }, nrLikes{ nrLikes }, trailer{ trailer }{}

Movie& Movie::operator=(const Movie& new_movie)
{
	if (this == &new_movie)
		return *this;

	this->name = new_movie.name;
	this->genre = new_movie.genre;
	this->trailer = new_movie.trailer;
	this->nrLikes = new_movie.nrLikes;
	this->year = new_movie.year;

	return *this;
}

bool Movie::operator==(const Movie& other_movie)
{
	return trailer == other_movie.trailer;
}


std::ostream& operator<<(std::ostream& writer, const Movie& movie)
{
	writer << movie.getName() << "|";
	writer << movie.getGenre() << "|";
	writer << movie.getYear() << "|";
	writer << movie.getNrLikes() << "|";
	writer << movie.getTrailer() << "\n";
	return writer;
}

std::istream& operator>>(std::istream& is, Movie& m)
{	
	
	if (is.eof())
		is.setstate(std::ios_base::failbit);
	else {
		getline(is, m.name, '|');
		getline(is, m.genre, '|');
		is >> m.year;
		std::string k = "";
		getline(is, k, '|');
		is >> m.nrLikes;
		getline(is, k, '|');
		getline(is, m.trailer, '\n');
	}
	
	return is;
	
}
