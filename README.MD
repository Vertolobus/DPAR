
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

<h3>ДОКУМЕНТАЦИЯ</h3>
<b>Кратко о функциях</b>

<b> DPAR Функции:</b>

* string DPAR::Fileread(string filepath);

  <b>Функция  для чтения содержимого файла</b>

  Аргументы:
	
  string filepath - Путь до файла 


  <hr>

* void DPAR::Filewrite(std::string filepath, std::string raw_text, bool clear = false);

  <b>Функция для записи данных в файл</b>
  
  Аргументы:

  string raw_text - Текст который будет записан в файл
  
  string filepath - Путь до файла 
  
  bool clear - Если включено то содержимое файла будет очищено
  

  <hr>

* bool DPAR::file_validation(string filepath);

  <b>Функция для проверки существует ли файл</b>
  
  Аргументы:
	
  string filepath - Путь до файла 

  <hr>

* bool DPAR::folder_validation(string folderpath);

  <b>Функция для проверки существует ли папка</b> 
  
  Аргументы:
	
  string folderpath - Путь до файла 

  <hr>

* std::vector folderfiles_iterator(string folderpath = "-");

  <b>Функция для возвращения вектора со всеми объектами в папке</b>
  
  Аргументы:
	
  string folderpath - Путь до папки

  bool fullpath - Если активно то выводит полный путь к файлу в противном случае выводится лишь название файла

<hr>