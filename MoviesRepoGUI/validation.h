#pragma once
#include <string>
#include <cstring>
#include "errors.h"

class Movie_Validation {

private:

	static void validate_name(const std::string& name);
	static void validate_genre(const std::string& genre);

public:

	static void validate_trailer(std::string trailer);
	static void validate_movie(const std::string& name, const std::string& genre, std::string trailer);
};