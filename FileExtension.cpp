#include "FileExtension.h"



Extension::Extension()
{
}
Extension::Extension(string name)
{
	int i = name.length() - 1;
	while (name[i] != '.')
	{
		i--;
	}
	i++;
	for (i;i<name.length();i++)
	{
		ext = ext + name[i];
	}
}
string Extension::ReturnExt()
{
	return ext;
}