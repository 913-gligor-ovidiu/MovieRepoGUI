#include "UserService.h"
#include "CSVRepository.h"
#include "HTMLRepository.h"

void UserService::addService(std::string name, std::string genre, int year, int nrLikes, std::string trailer)
{
    Movie movie(name, genre, year, nrLikes, trailer);
    this->userRepo->addUserRepo(movie);
}

void UserService::removeService(const std::string& trailer)
{
    this->userRepo->removeUserRepo(trailer);
}

void UserService::repositoryType(const std::string& fileType)
{
    if (fileType == "csv") {
        std::string userFile = "Watchlist.csv";
        auto* repo = new CSVRepository(userFile);
        this->userRepo = repo;
    }
    else if (fileType == "html") {
        std::string userFile = "Watchlist.html";
        auto* repo = new HTMLRepository(userFile);
        this->userRepo = repo;
    }
}

std::string& UserService::getFileService(){
    return this->userRepo->getFilename();
}

UserService::~UserService()
{
    delete this->userRepo;
}
