#include "service.h"
#include <vector>
#include <algorithm>

using namespace std;

void Service::addService(std::string name, std::string genre, int year, int nrLikes, std::string trailer)
{
	Movie movie(name, genre, year, nrLikes, trailer);
	this->movie_validator.validate_movie(name, genre, trailer);
	this->movieRepo.addRepo(movie);
	
	
	unique_ptr<Action> ptr = make_unique<ActionAdd>(movie, this->movieRepo);
	while (this->index < this->actions.size())
	{
		this->actions.pop_back();
	}
	this->actions.push_back(move(ptr));
	this->index++;
	
}

void Service::removeService(const std::string& trailer)
{	
	Movie m = this->movieRepo.findMovie(trailer);
	this->movie_validator.validate_trailer(trailer);
	this->movieRepo.removeRepo(trailer);
	
	unique_ptr<Action> ptr = make_unique<ActionRemove>(m, this->movieRepo);
	while (this->index < this->actions.size())
	{
		this->actions.pop_back();
	}
	this->actions.push_back(move(ptr));
	this->index++;
	
}

void Service::updateService(const std::string& trailer, const std::string& field, const std::string& new_info)
{
	this->movie_validator.validate_trailer(trailer);
	Movie before = this->movieRepo.findMovie(trailer);
	this->movieRepo.update(trailer, field, new_info);
	Movie after = this->movieRepo.findMovie(trailer);

	
	unique_ptr<Action> ptr = make_unique<ActionUpdate>(after, before, this->movieRepo);
	while (this->index < this->actions.size())
	{
		this->actions.pop_back();
	}
	this->actions.push_back(move(ptr));
	this->index++;
	
}

int Service::getRepoSize()
{
	return this->movieRepo.getSize();
}

void Service::undo()
{
	if (this->index == 0)
	{
		return;
	}
	this->index--;
	this->actions[index]->executeUndo();
}

void Service::redo()
{
	if (this->index == this->actions.size())
	{
		return;
	}
	this->actions[index]->executeRedo();
	this->index++;
}
