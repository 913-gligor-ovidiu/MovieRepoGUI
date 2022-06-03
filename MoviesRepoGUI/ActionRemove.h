#pragma once
#pragma once
#include "Action.h"
#include "movie.h"
#include "Repository.h"


class ActionRemove : public Action
{
private:
	Movie removedMovie;
	Repository& repo;

public:
	ActionRemove(Movie removedMovie, Repository& repo);

	void executeUndo() override;

	void executeRedo() override;
};
