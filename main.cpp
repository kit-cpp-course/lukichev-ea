#include "stdafx.h"
#include "Folder.h"
#include <Windows.h>
namespace fs = std::experimental::filesystem;
int main(int argc, char *argv[])
{
		string EndStr, BeginStr, Arh;
		if (argc != 1)
		{
			//получение данных из командной строки
			BeginStr = argv[1];
			EndStr = argv[2];
			Arh = argv[3];
		}
		else
		{
			std::cin >> BeginStr;
			std::cin >> EndStr;
			std::cin >> Arh;
		}
		//Создание списка всего, что находится в указанной папке
	CreateDirectory(EndStr.c_str(), NULL);
	for (const auto & entry : fs::directory_iterator(Arh))
	{
		CreateDirectory((EndStr + "\\" + entry.path().filename().string()).c_str(), NULL);
	}
	std::vector<Folder> vt; 
	vt.push_back(Folder(BeginStr));
	for (size_t i = 0; i < vt.size(); ++i) {
		BeginStr = vt[i].GetName();
		//Заполнение списка папок
		for (const auto & entry : fs::directory_iterator(BeginStr))
		{
			if (entry.path().extension() == "")
			{
				vt.push_back(Folder(entry.path().string()));
			}
			else
			{
				continue;
			}
		}
	}
	//Запуск соритровки по всем папкам из списка
	for (size_t i = 0; i < vt.size(); ++i)
	{
		vt[i].sort(EndStr, Arh);
	}
	system("pause"); 
}
