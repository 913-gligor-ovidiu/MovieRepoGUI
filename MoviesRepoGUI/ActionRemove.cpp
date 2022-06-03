#include "ActionRemove.h"

ActionRemove::ActionRemove(Movie removedMovie, Repository& repo): removedMovie(removedMovie), repo(repo){}

void ActionRemove::executeUndo()
{
	this->repo.addRepo(removedMovie);
}

void ActionRemove::executeRedo()
{	
	this->repo.removeRepo(removedMovie.getTrailer());
}
