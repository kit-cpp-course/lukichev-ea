#pragma once
#include "File.h"

// ласс, описывающий папку

class Folder
{
public:
	Folder() {};
	Folder(string str);
	//ћетод, позвол€ющий перезаписать им€ папки
	string GetName();
	//—ортировка фалов в данной папке
	void sort(string EndCat, string Arhiv);

private:
	//»м€ папки
	string Name;
	//—писок фалов в папке
	std::vector<File> mass;
};