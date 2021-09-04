#include <iostream>
#include <io.h>

#include "Sixteen/Program.h"
#include "Sixteen/Console.h"
#include <direct.h>

#define VERSION "0.1"

using namespace std;
using namespace Console;

/*
Sixteen Project

// st start
// st backup [-options]
// st link [domain|ip] [port] [id] [password]
*/
int main(int argc, char *argv[])
{
	Program* pro = new Program();
	
	char* buf = new char[255];
	char* dir = new char[255];
	char* t = _getcwd(buf, 255);
	strcpy_s(dir, 255, buf);

	set_Color(WHITE, BLACK);
	cout << "[Sixteen Manager v" << VERSION << "]" << endl;
	cout << "Copyright 2021. ¾ö°æÁØ. All right reserved." << endl << endl;

	while (true)
	{
		set_Color(WHITE, BLACK);
		cout << dir << "$ ";
		gets_s(buf, 254);

		if (strcmp(buf, "exit") == 0)
			return 0;
		else
			pro->exe(new string(buf));
		cout << endl;
	}
	 
	
}