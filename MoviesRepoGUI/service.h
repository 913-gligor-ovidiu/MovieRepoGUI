#pragma once
#include "Action.h"
#include "ActionAdd.h"
#include "ActionRemove.h"
#include "ActionUpdate.h"
#include <memory>
#include <vector>
#include <algorithm>
#include <utility>
#include "validation.h"
#include "Repository.h"

class Service {

private:
	//repo& movieRepo;
	Repository& movieRepo;
	Movie_Validation movie_validator;
	std::vector<std::unique_ptr<Action> > actions;
	int index;
	
public:
	//Service(repo& movieRepo, Movie_Validation movie_validator): movieRepo{ movieRepo }, movie_validator{ movie_validator } {}
	Service(Repository& movieRepo, Movie_Validation movie_validator) : movieRepo{ movieRepo }, movie_validator{ movie_validator }, index{ 0 } {}
	void addService(std::string name, std::string genre, int year, int nrLikes, std::string trailer);
	void removeService(const std::string& trailer);
	void updateService(const std::string& trailer, const std::string& field, const std::string& new_info);
	int getRepoSize();
	void likeService(std::string& trailer) { this->movie_validator.validate_trailer(trailer); this->movieRepo.like(trailer); }
	const std::vector<Movie> getAllSrv() { return this->movieRepo.getAll(); }

	void undo();
	void redo();
};