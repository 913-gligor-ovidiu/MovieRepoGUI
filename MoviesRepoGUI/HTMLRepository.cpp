#include "HTMLRepository.h"
#include <fstream>

HTMLRepository::HTMLRepository(const std::string& userFilename) {
    this->fileName = userFilename;
}

void HTMLRepository::writeToFile()
{
    std::ofstream fout(this->fileName);
    fout << "<!DOCTYPE html>\n<html><head><title>Wathclist</title></head><body>\n";
    fout << "<table border=\"1\">\n";
    fout << "<tr><td>Name</td><td>Genre</td><td>Year</td><td>Likes</td><td>Trailer</td></tr>\n";
    for (auto m : this->watchlist) {
        fout << "<tr><td>" << m.getName() << "</td>"
            << "<td>" << m.getGenre() << "</td>"
            << "<td>" << m.getYear() << "</td>"
            <<"<td>"<<m.getNrLikes()<<"</td>"
            << "<td>" << m.getTrailer() << "</td>" << '\n';
    }
    fout << "</table></body></html>";
    fout.close();
}


std::string& HTMLRepository::getFilename()
{
    return this->fileName;
}

HTMLRepository::~HTMLRepository() = default;
