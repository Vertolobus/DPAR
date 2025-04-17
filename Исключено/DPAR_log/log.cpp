#include <iostream>

#include "log.hpp"

// DPAR::log LOG FORMAT: (class-modifier [optional])[full_funcname] title : value[optional] << std::endl
//EXAMPLE - "[DPAR::read] FILE-EXISTS : \"" << path << "\""

void DPAR_log(std::string title, std::string full_funcname, std::string value, std::string class_modifier) {

	if (class_modifier != "-") { //optional

		std::cout << "(" << class_modifier << ")";

	}
	
	if (full_funcname == "-") {

		std::cerr << "ERROR: NO FULL_FUNCNAME OPTION";

	}
	else {
		std::cout << "[" << full_funcname << "]";
	}

	if (title == "-") {

		std::cerr << "ERROR: NO TITLE OPTION";

	}
	else {
		std::cout << " " << title;
	}

	if (value != "-") { //optional

		std::cout << " : " << value;

	}

	std::cout << std::endl;

}