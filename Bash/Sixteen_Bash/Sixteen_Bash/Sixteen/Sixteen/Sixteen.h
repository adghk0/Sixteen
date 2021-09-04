#pragma once
#include "../Command.h"

#include "Help/Help.h"
#include "Document/Document.h"

class Sixteen :
    public Command
{
protected:
	void subs_error(string* current, string* next);

public:
	Sixteen();

	const char* name();
	const char* fullname();
	void execute();
};

