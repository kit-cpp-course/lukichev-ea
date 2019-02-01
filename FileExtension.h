#pragma once
#include "stdafx.h"
using namespace std;

//Класс, описывающий расширение

class Extension
{
public:
	Extension() {};
	Extension(string name);
	//Метод, возвращающий расширение
	string ReturnExt();

private:
	string ext;
};



