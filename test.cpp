#include <iostream>
#include <filesystem>
#include <fstream>
#include <list>
#include <stdexcept>
#include <chrono>
#include <thread>
#include <string>

#include "DPAR.hpp"

std::string DPAR::Fileread() {

	if (filepath != "-" && !folder_validation(filepath)) { //func argument

		//------------------
		std::ifstream readfile(filepath, std::ios::in);
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
	else if (path != "-" && !folder_validation(path)) { //constructor argument


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

void DPAR::Filewrite(std::string raw_text) {

	if (filepath != "-" && !folder_validation(filepath)) { //func argument

		std::ofstream writefile(filepath, std::ios::out);
		if (!writefile.is_open()) {

			throw std::runtime_error("File open ERROR");
			return;

		}

		writefile << DPAR::Fileread(filepath) + raw_text + "\n";


		writefile.close();
	}
	else if (path != "-" && !folder_validation(path)) { //constructor argument

		std::ofstream writefile(path, std::ios::out);
		if (!writefile.is_open()) {

			throw std::runtime_error("File open ERROR");
			return;

		}

		writefile << DPAR::Fileread(path) + raw_text + "\n";


		writefile.close();

	}
	else {

		throw std::runtime_error("Unknown error");

	}
}