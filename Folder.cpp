#include "Folder.h"
#include <fstream>
#include <Windows.h>
namespace fs = std::experimental::filesystem;


Folder::Folder()
{
}

Folder::Folder(string path)
{
	File fl;
	string str;
	Name = path;
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
		Nm = "";
		for (const auto & entry : fs::directory_iterator(Arhiv))
		{
			Input.open(entry.path().string());
			while (Input.eof() != 1)
			{
				std::getline(Input, line);
				if (line == mass[i].ReturnExt())
				{
					Nm = entry.path().filename().string();
					break;
				}
			}
			Input.close();
			if (Nm != "")
			{
				break;
			}
			else
			{

			}
		}
		CopyFile((Name + "\\" + mass[i].ReturnName()).c_str(), (EndCat + "\\" + Nm +"\\"+ mass[i].ReturnName()).c_str(), false);
	}
}