#pragma once
#include "File.h"

class Folder
{
public:
	Folder();
	Folder(string str);
	string GetName();
	void sort(string EndCat, string Arhiv);

private:
	string Name;
	std::vector<File> mass;
};