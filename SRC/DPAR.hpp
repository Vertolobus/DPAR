#pragma once

#include <iostream>
#include <filesystem>
#include <fstream>
#include <list>
#include <stdexcept>
#include <chrono>
#include <ctime>
#include <string>
#include <vector>

/*		______________________________________________________________________________
		__________________   ________     ________     _______       ________           
		______/_/______/_/   ___  __ \    ___  __ \    ___    |      ___  __ \          
		____/_/  ____/_/     __  / / /    __  /_/ /    __  /| |      __  /_/ /          
		__/_/    __/_/       _  /_/ /     _  ____/     _  ___ |      _  _, _/           
		/_/      /_/         /_____/      /_/          /_/  |_|      /_/ |_|            
		_________________________________________________________________________

				        D | P | A | R - DATA PARSER AND READER 
			This program is licensed under the GNU General Public License (GPL)
          Эта программа лицензирована по лицензии GNU General Public License (GPL).

                                    LICENSE.TXT
*/

namespace DPAR { //DPAR_FUNC

    //A function for reading the contents of a file
    std::string Fileread(std::string filepath);

    //A function for writing the contents to the file
    void Filewrite(std::string filepath, std::string raw_text, bool clear = false);

    //A function to return a vector with all the objects in a folder
    std::vector<std::filesystem::path> folderfiles_iterator(std::string folderpath);

    //A function to check if a file exists
    bool file_validation(std::string filepath);

    //A function to check if a folder exists
    bool folder_validation(std::string folderpath);

}