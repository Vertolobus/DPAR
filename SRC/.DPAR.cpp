#include <iostream>
#include <filesystem>
#include <fstream>
#include <list>
#include <stdexcept>
#include <chrono>
#include <thread>
#include <string>

#include ".DPAR.hpp"

// Cout\Cerr LOG FORMAT: (class-modifier [optional])[full_funcname] title : value[optional] << std::endl
//EXAMPLE - "[DPAR::read] FILE-EXISTS : \"" << path << "\""


std::string DPAR::Fileread(std::string full_filepath) {

	if (std::filesystem::exists(full_filepath)) { //func argument

		std::cout << "(private)[DPAR::Fileread] EXISTS(path) : " << "\"" << full_filepath << "\"" << std::endl;

		std::ifstream readfile(full_filepath, std::ios::in);
		if (!readfile.is_open()) {

			std::cerr << "(private)[DPAR::Fileread] File open ERROR! : " << "\"" << full_filepath << "\"" << std::endl;
			return std::string();

		}

		std::string text = "";
		std::string line = "";
		while (std::getline(readfile, line)) {

			std::cout << "(private)[DPAR::Fileread] Reading... : " << "\"" << line << "\"" << std::endl;
			text += line + "\n";

		}

		std::cout << "(private)[DPAR::Fileread] Read complete successful : " << "\"" << line << "\"" << std::endl;
		return text;

	}
	else if (std::filesystem::exists(path)) { //constructor argument

		std::cout << "(private)[DPAR::Fileread] EXISTS(path) : " << "\"" << path << "\"" << std::endl;

		std::ifstream readfile(path, std::ios::in);
		if (!readfile.is_open()) {

			std::cerr << "(private)[DPAR::Fileread] File open ERROR! : " << "\"" << path << "\"" << std::endl;
			return std::string();

		}

		std::string text = "";
		std::string line = "";
		while (std::getline(readfile, line)) {

			std::cout << "(private)[DPAR::Fileread] Reading... : " << "\"" << line << "\"" << std::endl;
				text += line + "\n";

		}

		std::cout << "(private)[DPAR::Fileread] Read complete successful : " << "\"" << line << "\"" << std::endl;
		return text;
		
	}
	else {

		std::cerr << "(private)[DPAR::Fileread] NOT EXISTS! : " << "\"" << full_filepath << "\"" << " : " << "\"" << path << "\"" << std::endl;
		return std::string();
	}

}

//----------------------------------

DPAR::DPAR(std::string full_filepath, DPAR::TYPE type) : path(full_filepath), requesttype(type) { 
	//pause(endpause) - используется в деструкторе

	/*----------
	// D P A R
	----------*/
	std::cout << R"(
		______________________________________________________________________________
		__________________   ________     ________     _______       ________           
		______/_/______/_/   ___  __ \    ___  __ \    ___    |      ___  __ \          
		____/_/  ____/_/     __  / / /    __  /_/ /    __  /| |      __  /_/ /          
		__/_/    __/_/       _  /_/ /     _  ____/     _  ___ |      _  _, _/           
		/_/      /_/         /_____/      /_/          /_/  |_|      /_/ |_|            
		_________________________________________________________________________

				D | P | A | R - DATA PARSER AND READER 
			This program is licensed under the GNU General Public License (GPL)
					      LOADING IN PROGRESS...
		
	)" << std::endl << std::endl << std::endl;

	std::this_thread::sleep_for(std::chrono::milliseconds(800)); //0.8 second pause...
	/*
	DPAR::TYPE requesttype = DPAR::TYPE::NONE;

	initialized in DPAR.hpp
	*/

	//------------------

	if (type == DPAR::TYPE::READ || type == DPAR::TYPE::PARSE) {

		std::cout << "(public)[DPAR::DPAR] Type identified successful" << std::endl;

	}
	else {

		std::cerr << "(public)[DPAR::DPAR] Type identified ERROR!" << std::endl;
		return;

	}

	//------------------

	if (std::filesystem::exists(full_filepath)) {

		std::cout << "(public)[DPAR::DPAR] EXISTS : " << "\"" << full_filepath << "\"" << std::endl;

	}

	else {

		std::cerr << "(public)[DPAR::DPAR] NOT EXISTS! : " << "\"" << full_filepath << "\"" << std::endl;
		return;

	}

	//------------------

	/*
	std::string path;
    std::string file_name = "";
    std::string extension = "";

	initialized in DPAR.hpp
	*/

	//------------------

	int cycle = 0;
	cycle = path.length();

	while (cycle >= 0) { //cycle 1/2

		std::cout << "extension searching...( " << cycle << " : " << "0 )" << std::endl;

		if (path[cycle] == '.') {
			cycle++;
			extension = path.substr(cycle, path.length());
			std::cout << "(public)[DPAR::DPAR] EXTENSION EXISTS : " << "\"" << extension << "\"" << std::endl;
			break;

		}
		else if (cycle == 0 && path[cycle] == '.') {

			std::cerr << "(public)[DPAR::DPAR] EXTENSION NOT EXISTS : " << "\"" << full_filepath << "\"" << std::endl;
			return;
		}
		
		if (cycle != 0)
		cycle--;
	}

	//------------------

	cycle = path.length();

	while (cycle >= 0) { //cycle 2/2

		std::cout << "File name searching...( " << cycle << " : " << "0 )" << std::endl;

		if (path[cycle] == '\\' || path[cycle] == '/') {
			cycle++;
			file_name = path.substr(cycle, path.length());
			std::cout << "(public)[DPAR::DPAR] FILE NAME EXISTS : " << "\"" << file_name << "\"" << std::endl;
			break;

		}
		else if (cycle == 0 && path[cycle] == '.') {

			std::cerr << "(public)[DPAR::DPAR] FILE NAME NOT EXISTS : " << "\"" << full_filepath << "\"" << std::endl;
			return;
		}

		if (cycle != 0)
			cycle--;

	}

	cycle = 0;
	//------------------



}

DPAR::~DPAR() {

	std::cout << "\n\nDPAR was finished\n\n";
	std::cout << "_________________________________________________________________________" << std::endl << std::endl << std::endl << std::endl << std::endl;
}
//----------------------------------

