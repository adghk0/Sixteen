#pragma once
#include "../../Command.h"

class Help :
    public Command
{
private:
	Command* sixteen;

	void show_Commands(Command* command, int level, bool start);

protected:
	void subs_error(string* current, string* next);

public:
	Help(Command* sixteen);

	const char* name();
	const char* fullname();
	void execute();
};

