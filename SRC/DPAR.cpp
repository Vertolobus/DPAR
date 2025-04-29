#include <iostream>
#include <filesystem>
#include <fstream>
#include <list>
#include <stdexcept>
#include <chrono>
#include <thread>
#include <string>

#include "DPAR.hpp"
//----------------------------------
bool DPAR::file_validation(std::string filepath) {
	if (filepath == "-") {  //constructor argument
		if (std::filesystem::is_directory(path)) {
			return false;
		}
		else if (!std::filesystem::exists(path)) {
			return false;
		}
		else {

			return true;

		}
	}
	else { //funcion argument
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
}
//----------------------------------
bool DPAR::folder_validation(std::string folderpath) {
	if (folderpath == "-") {
		if (!std::filesystem::is_directory(path)) { //constructor argument
			return false;
		}
		else {
			return true;
		}
	}
	else {
		if (!std::filesystem::is_directory(folderpath)) { //funcion argument
			return false;
		}
		else {
			return true;
		}

	}
}
//----------------------------------

//Iterator files from folder
std::vector<std::filesystem::path> DPAR::folderfiles_iterator(std::string folderpath) {
	/*
	/*
	std::vector<std::filesystem::path> filespath;

	initialized in DPAR.hpp
	*/


	if (folderpath == "-") { //constructor argument
		if (!folder_validation(path)) {
			int cutnumber = 0;

			for (int cycle = path.length() - 1; cycle >= 0; cycle--) {
				if (path[cycle] == '\\' || path[cycle] == '/') {

					cutnumber = cycle;
					break;
				}
			}

			for (auto const& content_iterator : std::filesystem::directory_iterator(path.substr(0, cutnumber))) {
				filespath.push_back(content_iterator.path());

			}

		}
		else {
			for (auto const& content_iterator : std::filesystem::directory_iterator(path)) {
				filespath.push_back(content_iterator.path());

			}
		}

		return filespath;

	}
	else { //funcion argument
		if (!folder_validation(folderpath)) {

			for (int cycle = folderpath.length() - 1; cycle >= 0; cycle--) {
				if (folderpath[cycle] == '\\' || folderpath[cycle] == '/') {
					folderpath = folderpath.substr(0, cycle);
				}
			}

		}
		
		for (auto const& content_iterator : std::filesystem::directory_iterator(folderpath)) {
			filespath.push_back(content_iterator.path());

		}

		return filespath;

	}
}
//----------------------------------

//----------------------------------
//Class DPAR was initializated in .DPAR.hpp
DPAR::DPAR(std::string fullpath) : path(fullpath) {
	/*
	std::string path;
	std::string file_name = "";
	std::string extension = "";

	initialized in DPAR.hpp
	*/
	if (DPAR::file_validation(fullpath)) { //if file exists

		//step 1.1 : extension detecting
		//------------------
		for (int cycle = fullpath.length(); cycle >= 0; cycle--) {

			if (fullpath[cycle] == '.') {
				cycle++;
				extension = fullpath.substr(cycle, fullpath.length());
				break;

			}

			if (fullpath[cycle] == '\\' || fullpath[cycle] == '/') {

				extension = "";

			}

		}

		//step 1.2 : file name detecting
		//------------------

		for (int cycle = fullpath.length(); cycle >= 0; cycle--) {

			//File name searching...

			if (fullpath[cycle] == '\\' || fullpath[cycle] == '/') {
				cycle++;
				file_name = fullpath.substr(cycle, fullpath.length());
				break;

			}
			else if (cycle == 0 && fullpath[cycle] == '.') {

				file_name = "";

			}
		}

	}
}
//----------------------------------

//----------------------------------
//File operation func

//File reader
std::string DPAR::Fileread() {

	if (path != "-" && DPAR::file_validation()) { //constructor argument


		//------------------
		std::ifstream readfile(path, std::ios::in);
		if (!readfile.is_open()) {

			throw std::runtime_error("File open ERROR");
			return std::string();

		}

		std::string text = "";
		std::string line = "";

		while (std::getline(readfile, line)) {

			text += line + "\n";

		}


		readfile.close();

		return text;
		//------------------
	}
	else {

		throw std::runtime_error("Unknown ERROR!");

	}

}
//----------------------------------

//File writer
void DPAR::Filewrite(std::string raw_text, bool clear) {

	if (path != "-" && DPAR::file_validation()) { //constructor argument
		std::ofstream writefile;
		if (clear) {
			writefile.open(path, std::ios::out | std::ios::trunc); 
		}
		else {
			writefile.open(path, std::ios::out | std::ios::app);
		}
		if (!writefile.is_open()) {

			throw std::runtime_error("File open ERROR");
			return;

		}

		writefile  << raw_text + "\n";


		writefile.close();

	}
	else {

		throw std::runtime_error("Unknown error");

	}
}
//----------------------------------