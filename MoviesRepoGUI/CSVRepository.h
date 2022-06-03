#pragma once
#include "UserRepository.h"

class CSVRepository: public UserRepository{
public:
	CSVRepository(const std::string& fileName);
	void writeToFile()override;
	std::string& getFilename()override;
	~CSVRepository();
};

