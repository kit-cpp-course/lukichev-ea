#pragma once
#include "stdafx.h"
#include "FileExtension.h"

//Класс, описывающий файл

class File
{
public:
	File() {};
	File(const string & str);
	//Метод, возвращающий имя файла
	string ReturnName();
	//Метод, возвращающий расширение файла
	string ReturnExt();

private:
	//Имя файла
	string name;
	//Расширение файла
	Extension ext;
};


