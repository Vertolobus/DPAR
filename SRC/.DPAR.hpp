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

class DPAR {
public:
    std::string Fileread(std::string filepath = "-");
    void Filewrite(std::string raw_text,  std::string filepath = "-");
    //std::list<std::string> Fileanalys(std::string filepath = "-"); //future func

    bool file_validation(std::string filepath);
    bool folder_validation(std::string folderpath);
    //----------------------------------


    std::string path = "-";

    std::string file_name = "-";
    std::string extension = "-";


    DPAR(std::string filepath, std::string parse_data = "-");

    //----------------------------------

};
