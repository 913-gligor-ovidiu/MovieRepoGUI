#include "ActionAdd.h"

ActionAdd::ActionAdd(Movie addedMovie, Repository& repo): addedMovie(addedMovie), repo(repo) {}

void ActionAdd::executeUndo()
{
	repo.removeRepo(addedMovie.getTrailer());
}

void ActionAdd::executeRedo()
{
	repo.addRepo(addedMovie);
}
