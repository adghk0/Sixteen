#include "Console.h"

void Console::set_Color(char fore, char back)
{
	int color = fore | back << 4;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void Console::write_Message(char* msg)
{
    set_Color(WHITE, BLACK);
    cout << msg << endl;
}

void Console::write_Warning(char* msg)
{
    set_Color(YELLOW, BLACK);
    cout << "[WARNING] " << msg << endl;
}

void Console::write_Error(char* msg)
{
    set_Color(RED, BLACK);
    cout << "[ERROR] " << msg << endl;
}

