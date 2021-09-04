#pragma once
#include "../../Command.h"
class Document :
    public Command
{
protected:
	void subs_error(string* current, string* next);

public:
	Document();

	const char* name();
	const char* fullname();
	void execute();
};

