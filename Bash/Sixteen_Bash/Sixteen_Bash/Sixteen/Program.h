#pragma once
#include "Command.h"

#include "Sixteen/Sixteen.h"

class Program :
    public Command
{
protected:
	void subs_error(string* current, string* next);

public:
	Program();

	const char* name();
	const char* fullname();
	void execute();
};

