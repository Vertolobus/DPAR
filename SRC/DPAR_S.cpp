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
bool DPAR_S::file_validation(std::string filepath) {
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
bool DPAR_S::folder_validation(std::string folderpath) {
	if (!std::filesystem::is_directory(folderpath)) { //funcion argument
		return false;
	}
	else {
		return true;
	}
}
//----------------------------------

//Iterator files from folder
std::vector<std::filesystem::path> DPAR_S::folderfiles_iterator(std::string folderpath) {
	std::vector<std::filesystem::path> filespath;

	if (!folder_validation(folderpath)) {
		int cutnumber = 0;

		for (int cycle = folderpath.length() - 1; cycle >= 0; cycle--) {
			if (folderpath[cycle] == '\\' || folderpath[cycle] == '/') {
				cutnumber = cycle;
				break;
			}
		}

		for (auto const& content_iterator : std::filesystem::directory_iterator(folderpath.substr(0, cutnumber))) {
			filespath.push_back(content_iterator.path());

		}

		return filespath;

	}
	else {

		for (auto const& content_iterator : std::filesystem::directory_iterator(folderpath)) {
			filespath.push_back(content_iterator.path());
		}

		return filespath;

	}

}
//----------------------------------
//File operation func

//File reader
std::string DPAR_S::Fileread(std::string folderpath) {

	if (folderpath != "-" && DPAR_S::file_validation( folderpath )) { //constructor argument


		//------------------
		std::ifstream readfile(folderpath, std::ios::in);
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
void DPAR_S::Filewrite(std::string filepath, std::string raw_text, bool clear) {

	if (filepath != "-" && DPAR_S::file_validation(filepath)) { //constructor argument
		std::ofstream writefile;
		if (clear) {
			writefile.open(filepath, std::ios::out | std::ios::trunc);
		}
		else {
			writefile.open(filepath, std::ios::out | std::ios::app);
		}
		if (!writefile.is_open()) {

			throw std::runtime_error("File open ERROR");
			return;

		}

		writefile << raw_text + "\n";


		writefile.close();

	}
	else {

		throw std::runtime_error("Unknown error");

	}
}
//----------------------------------