#include <iostream>
#include <filesystem>
#include <fstream>
#include <list>
#include <stdexcept>
#include <chrono>
#include <thread>
#include <string>

#include ".DPAR.hpp"
//----------------------------------
bool DPAR::file_validation(std::string filepath) {
	if (std::filesystem::is_directory(filepath)) {
		return false;
	}
	else if (!std::filesystem::exists(filepath)) {
		return false;
	}
	else {

		return true;

	}
}
//----------------------------------
bool DPAR::folder_validation(std::string folderpath) {
	if (!std::filesystem::is_directory(folderpath)) {
		return false;
	}
	else {
		return true;
	}
}
//----------------------------------
//Class DPAR was initializated in .DPAR.hpp
DPAR::DPAR (std::string filepath, std::string parse_data) : path(filepath) {

	//check
	//------------------
	file_validation(filepath);
	//------------------

	//step 1.1 : extension detecting
	
	//------------------

	/*
	std::string path;
    std::string file_name = "";
    std::string extension = "";

	initialized in DPAR.hpp
	*/
	int cycle = 0;
	cycle = filepath.length();

	while (cycle >= 0) {

		//extension searching..

		if (filepath[cycle] == '.') {
			cycle++;
			extension = filepath.substr(cycle, filepath.length());
			break;

		}

		if (filepath[cycle] == '\\' || filepath[cycle] == '/') {

			extension = "";

		}
		
		if (cycle != 0) {
			cycle--;
		}
	}

	//step 1.2 : file name detecting
	//------------------

	cycle = filepath.length();

	while (cycle >= 0) {

		//File name searching...

		if (filepath[cycle] == '\\' || filepath[cycle] == '/') {
			cycle++;
			file_name = filepath.substr(cycle, filepath.length());
			break;

		}
		else if (cycle == 0 && filepath[cycle] == '.') {

			file_name = "";

		}

		if (cycle != 0) {
			cycle--;
		}
	}

	cycle = 0;

}
//----------------------------------

