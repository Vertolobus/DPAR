#include <list>
#include <stdexcept>
#include <chrono>
#include <thread>
#include <string>

#include ".DPAR.hpp"

// Cout\Cerr LOG FORMAT: (class-modifier [optional])[full_funcname] title : value[optional] << std::endl
//EXAMPLE - "[DPAR::read] FILE-EXISTS : \"" << path << "\""

std::string DPAR::JSON(std::string raw_parse_data)
{
	/*
	
	Available class variables

	std::string path = "-";
	std::string file_name = "-";
	std::string extension = "-";
	int pause = 0; //variable for destructor only
	DPAR::TYPE requesttype = DPAR::TYPE::NONE;
	*/

	if (requesttype == DPAR::TYPE::NONE || path == "-") {

		std::cerr << "[DPAR::JSON] UNKNOWN ERROR!" << std::endl;
		return std::string();

	}

	if (requesttype == DPAR::TYPE::READ) {

		return Fileread(path);
		
	}

	return std::string();
}