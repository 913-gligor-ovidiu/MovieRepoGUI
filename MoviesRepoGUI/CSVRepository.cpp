#include "CSVRepository.h"
#include <fstream>

CSVRepository::CSVRepository(const std::string& fileName) {
    this->fileName = fileName;
}


void CSVRepository::writeToFile()
{
    std::ofstream fout(this->fileName);
    if (!this->watchlist.empty()) {
        for (auto m : this->watchlist) {
            fout << m;
        }
    }
    fout.close();
}

std::string& CSVRepository::getFilename()
{
    return this->fileName;
}

CSVRepository::~CSVRepository() = default;
