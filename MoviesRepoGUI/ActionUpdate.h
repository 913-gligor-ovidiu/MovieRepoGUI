#pragma once
#include "Repository.h"
#include "movie.h"
#include "Action.h"

class ActionUpdate: public Action
{
private:
	Repository& repo;
	Movie addedMovie;
	Movie removedMovie;

public:
	ActionUpdate(Movie addedMovie, Movie removedMovie, Repository& repo): addedMovie(addedMovie), removedMovie(removedMovie), repo(repo){}
	void executeUndo() override;
	void executeRedo() override;
};

