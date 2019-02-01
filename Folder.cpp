#include "Folder.h"
#include <fstream>
#include <Windows.h>
namespace fs = std::experimental::filesystem;



Folder::Folder(string path)
{
	File fl;
	string str;
	Name = path;
	//Создание списка фалов в папке
	for (const auto & entry : fs::directory_iterator(path))
	{
		str = entry.path().filename().string();
		int i = str.length() - 1;
		while (i >= 0)
		{
			if (str[i] == '.')
			{
				mass.push_back(File(str));
				break;
			}
			i--;
		}
	}
}

string Folder::GetName()
{
	return Name;
}

void Folder::sort(string EndCat, string Arhiv)
{
	ifstream Input;
	string line, Nm;
	for (size_t i = 0; i < mass.size(); ++i)
	{
		//Берем файл из списка
		Nm = "";
		for (const auto & entry : fs::directory_iterator(Arhiv))
		{
			//Открываем файл с содержанием критериев сортировки
			Input.open(entry.path().string());
			while (Input.eof() != 1)
			{
				//сверяем расширение файла с критериями
				std::getline(Input, line);
				if (line == mass[i].ReturnExt())
				{
					//Если подходит, то запоминаем имя папки, куда надо скопировать файл
					Nm = entry.path().filename().string();
					break;
				}
			}
			//Если не подошел ни один из критериев, папку, в которую надо скопировать файл, выбираем основную итоговую
			Input.close();
			if (Nm != "")
			{
				break;
			}
		}
		//Копируем файл в нужное место
		CopyFile((Name + "\\" + mass[i].ReturnName()).c_str(), (EndCat + "\\" + Nm +"\\"+ mass[i].ReturnName()).c_str(), false);
	}
}