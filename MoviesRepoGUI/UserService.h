#pragma once
#include "UserRepository.h"
#include "Repository.h"
#include "validation.h"

class UserService{
private:
	Repository& repository;
	UserRepository* userRepo;
	Movie_Validation movie_validator;

public:

	UserService(Repository& repository, UserRepository* userRepo, Movie_Validation movie_validator) :repository{ repository }, userRepo{ userRepo }, movie_validator{movie_validator}{}
	explicit UserService(Repository& repository, Movie_Validation movie_validator):repository{ repository }, movie_validator{ movie_validator }{}
	const std::vector<Movie> getAllSrv() { return this->userRepo->getAll(); }
	void addService(std::string name, std::string genre, int year, int nrLikes, std::string trailer);
	void removeService(const std::string& trailer);
	void likeService(std::string& trailer) {this->movie_validator.validate_trailer(trailer); this->repository.like(trailer);}
	void repositoryType(const std::string& fileType);
	int getRepoSize() { return this->userRepo->getSize(); }

	std::string& getFileService();
	~UserService();
};

