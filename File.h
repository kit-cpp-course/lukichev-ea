#pragma once
#include "stdafx.h"
#include "FileExtension.h"

//�����, ����������� ����

class File
{
public:
	File() {};
	File(const string & str);
	//�����, ������������ ��� �����
	string ReturnName();
	//�����, ������������ ���������� �����
	string ReturnExt();

private:
	//��� �����
	string name;
	//���������� �����
	Extension ext;
};


