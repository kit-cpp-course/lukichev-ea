#include "stdafx.h"
#include "Folder.h"
#include <Windows.h>
namespace fs = std::experimental::filesystem;
int main()
{
	std::string path = "d:\Slovari";
	std::string str = "d:\End";
	std::string Arh = "d:\Arhiv";
	CreateDirectory(str.c_str(), NULL);
	for (const auto & entry : fs::directory_iterator(Arh))
	{
		CreateDirectory((str + "\\" + entry.path().filename().string()).c_str(), NULL);
	}
	std::vector<Folder> vt; 
	vt.push_back(Folder(path));
	for (size_t i = 0; i < vt.size(); ++i) {
		path = vt[i].GetName();
		for (const auto & entry : fs::directory_iterator(path))
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
	for (size_t i = 0; i < vt.size(); ++i)
	{
		vt[i].sort(str, Arh);
	}
	system("pause"); 
}
