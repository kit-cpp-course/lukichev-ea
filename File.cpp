#include "File.h"


File::File()
{
}

File::File(string str)
{	
			name = str;
			ext=Extension::Extension(name);
}


string File::ReturnName() {
	return name;
}
string File::ReturnExt()
{
	return ext.ReturnExt();
}
