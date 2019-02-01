#include "File.h"




File::File(const string & str)
{	
			name = str;
			ext=Extension(name);
}


string File::ReturnName() {
	return name;
}
string File::ReturnExt()
{
	return ext.ReturnExt();
}
