
		______________________________________________________________________________
		__________________   ________     ________     _______       ________           
		______/_/______/_/   ___  __ \    ___  __ \    ___    |      ___  __ \          
		____/_/  ____/_/     __  / / /    __  /_/ /    __  /| |      __  /_/ /          
		__/_/    __/_/       _  /_/ /     _  ____/     _  ___ |      _  _, _/           
		/_/      /_/         /_____/      /_/          /_/  |_|      /_/ |_|            
		_________________________________________________________________________

				D | P | A | R - DATA PARSER AND READER 
			This program is licensed under the GNU General Public License (GPL)
		    Эта программа лицензирована по лицензии GNU General Public License (GPL).

	ПРОЕКТ НАХОДИТСЯ НА РАННЕЙ СТАДИИ РАЗРАБОТКИ, ПОЭТОМУ В НЕКОТОРЫХ МЕСТАХ МОГУТ БЫТЬ ПУСТЫЕ МЕСТА ИЛИ ОШИБКИ

<hr>

<h2>ОПИСАНИЕ</h2>

<h3> DPAR - библеотека для чтение и записи данных из разных форматов файлов </h3>
<h3> список поддерживаемых форматов для анализа(будущая функция): </h3>

* JSON(СКОРО)

* TXT(СКОРО)

* Markdown(СКОРО)

* XML(СКОРО)

<hr>

<h3>ДОКУМЕНТАЦИЯ</h3>

<b> Функции:</b>


* string Fileread(string filepath = "-");

  <b>Функция  для чтения содержимого файла</b>
  
  Аргументы:
	
  string filepath - Путь до файла 

  <hr>

* void Filewrite(string raw_text,  string filepath = "-");

  <b>Функция для записи данных в файл</b>
  
  Аргументы:
  string raw_text - Текст который будет записан в файл
	
  string filepath - Путь до файла 

  <hr>

* //list<string> Fileanalysis(string filepath = "-"); //future func

  <b>Будущая функция</b>

  <hr>

* bool file_validation(string filepath);

  <b>Функция для проверки существует ли файл</b>
  
  Аргументы:
	
  string filepath - Путь до файла 

  <hr>

* bool folder_validation(string folderpath);

  <b>Функция для проверки является ли путь - папкой</b>
  
  Аргументы:
	
  string filepath - Путь до файла 

 <hr>

<hr>

## Структура проекта
- [Source](SRC/)
    - [DPAR.cpp](SRC/.DPAR.cpp) 
    - [DPAR.hpp](SRC/.DPAR.hpp) 
    - [language_manager.cpp](SRC/.language_manager.cpp)
