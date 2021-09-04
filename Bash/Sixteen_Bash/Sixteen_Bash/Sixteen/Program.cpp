#include "Program.h"

void Program::subs_error(string* current, string* next)
{
	subs_error_nom(current, next);
}

Program::Program()
{
	add_Command(new Sixteen());
}

const char* Program::name()
{
	return "program";
}

const char* Program::fullname()
{
	return "program";
}

void Program::execute()
{
	Console::write_Warning((char*)"no command");
}
