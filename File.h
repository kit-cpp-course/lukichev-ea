#pragma once
#include "stdafx.h"
#include "FileExtension.h"

class File
{
public:
	File();
	File(string str);
	void GetName(string str);
	string ReturnName();
	string ReturnExt();

private:
	string name;
	Extension ext;
};


