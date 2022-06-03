#include "ActionUpdate.h"

void ActionUpdate::executeUndo()
{
	this->repo.removeRepo(addedMovie.getTrailer());
	this->repo.addRepo(removedMovie);
}

void ActionUpdate::executeRedo()
{
	this->repo.addRepo(addedMovie);
	this->repo.removeRepo(removedMovie.getTrailer());
}
