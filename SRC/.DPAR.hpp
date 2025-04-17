#pragma once

#include <iostream>
#include <filesystem>
#include <fstream>
#include <list>
#include <stdexcept>
#include <chrono>
#include <ctime>
#include <string>


class DPAR {
private:

    std::string File_manager();

public:
    std::string Fileread(std::string full_filepath = "-");


    //----------------------------------
    enum class TYPE {
        NONE, //0
        READ, //1
        PARSE //2
    };


    std::string path = "-";
    DPAR::TYPE requesttype = DPAR::TYPE::NONE;
    bool argument_autorun = true;
    int pause = 0; //variable for destructor only

    std::string file_name = "-";
    std::string extension = "-";

    DPAR(std::string full_filepath, DPAR::TYPE type = DPAR::TYPE::READ, bool autorun = true);

    ~DPAR();

    //----------------------------------

    std::string JSON(std::string raw_parse_data = "-");
    
};
