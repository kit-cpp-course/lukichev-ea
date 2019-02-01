#include "stdafx.h"
#include "Folder.h"
#include <Windows.h>
namespace fs = std::experimental::filesystem;
int main(int argc, char *argv[])
{
		string EndStr, BeginStr, Arh;
		if (argc != 1)
		{
			//��������� ������ �� ��������� ������
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
		//�������� ������ �����, ��� ��������� � ��������� �����
	CreateDirectory(EndStr.c_str(), NULL);
	for (const auto & entry : fs::directory_iterator(Arh))
	{
		CreateDirectory((EndStr + "\\" + entry.path().filename().string()).c_str(), NULL);
	}
	std::vector<Folder> vt; 
	vt.push_back(Folder(BeginStr));
	for (size_t i = 0; i < vt.size(); ++i) {
		BeginStr = vt[i].GetName();
		//���������� ������ �����
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
	//������ ���������� �� ���� ������ �� ������
	for (size_t i = 0; i < vt.size(); ++i)
	{
		vt[i].sort(EndStr, Arh);
	}
	system("pause"); 
}
