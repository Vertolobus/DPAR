#pragma once
#include <iostream>

// DPAR::log LOG FORMAT: (class-modifier [optional])[full_funcname] title : value[optional] << std::endl
//EXAMPLE - "[DPAR::read] FILE-EXISTS : \"" << path << "\""

void DPAR_log(std::string title = "", std::string full_funcname = "", std::string value = "", std::string class_modifier = "");