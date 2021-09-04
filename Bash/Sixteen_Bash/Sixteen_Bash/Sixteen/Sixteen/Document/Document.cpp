#include "Document.h"

void Document::subs_error(string* current, string* next)
{
	subs_error_nom(current, next);
}

Document::Document()
{
}

const char* Document::name()
{
	return "doc";
}

const char* Document::fullname()
{
	return "document";
}

void Document::execute()
{
	Console::write_Warning((char*)"the document command must has sub command");
}
