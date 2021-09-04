#include "Sixteen.h"

void Sixteen::subs_error(string* current, string* next)
{
	subs_error_nom(current, next);
}

Sixteen::Sixteen()
{
	add_Command(new Help(this));
	add_Command(new Document());
}

const char* Sixteen::name()
{
	return "st";
}

const char* Sixteen::fullname()
{
	return "sixteen";
}

void Sixteen::execute()
{
	Console::write_Warning((char*)"the sixteen command must has sub command");
}
