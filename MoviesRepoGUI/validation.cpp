#include "validation.h"
#include <utility>

void Movie_Validation::validate_name(const std::string& name)
{
	if (name.empty())
		throw ValidError("Invalid name!");
}

void Movie_Validation::validate_genre(const std::string& genre)
{
	if (genre.empty())
		throw ValidError("Invalid genre!");
}

void Movie_Validation::validate_trailer(std::string trailer)
{
	if (trailer.empty())
		throw ValidError("Invalid trailer!");

}

void Movie_Validation::validate_movie(const std::string& name, const std::string& genre, std::string trailer)
{
	std::string err;

	try {
		validate_trailer(std::move(trailer));
	}
	catch (ValidError& ve) {
		err += ve.get_message();
		err += "\n";
	}

	try {
		validate_name(name);
	}
	catch (ValidError& ve) {
		err += ve.get_message();
		err += "\n";

	}

	try {
		validate_genre(genre);
	}
	catch (ValidError& ve) {
		err += ve.get_message();
		err += "\n";
	}

	if (!err.empty())
		throw ValidError(err);
}	
