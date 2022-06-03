#pragma once
#include "Action.h"
#include "movie.h"
#include "Repository.h"


class ActionAdd : public Action
{
private:
	Movie addedMovie;
	Repository& repo;

public:
	ActionAdd(Movie addedMovie, Repository& repo);

	void executeUndo() override;

	void executeRedo() override;
};



