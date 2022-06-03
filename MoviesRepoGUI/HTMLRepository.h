#pragma once
#include "UserRepository.h"


class HTMLRepository: public UserRepository{
public:
	HTMLRepository(const std::string& userFilename);
	
	void writeToFile()override;
	std::string& getFilename()override;
	
	~HTMLRepository();
};

