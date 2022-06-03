#include "UserRepository.h"
#include "errors.h"

std::vector<Movie> const UserRepository::getAll()
{
    return this->watchlist;
}

int UserRepository::getSize()
{
    return this->watchlist.size();
}

void UserRepository::addUserRepo(const Movie& movie)
{   
    if (find(movie.getTrailer()) != this->watchlist.end())
        throw RepoError("Movie already exists!");
    this->watchlist.push_back(movie);
    this->writeToFile();
}

void UserRepository::removeUserRepo(const std::string& trailer)
{
    std::vector<Movie>::iterator it = find(trailer);
    this->watchlist.erase(it);
    this->writeToFile();
}

std::vector<Movie>::iterator UserRepository::find(const std::string& trailer)
{
    std::vector<Movie>::iterator it;
    it = std::find_if(this->watchlist.begin(), this->watchlist.end(), [&trailer](const Movie& obj) {return obj.getTrailer() == trailer; });
    return it;
}
