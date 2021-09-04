#include "Help.h"

void Help::show_Commands(Command* command, int level, bool start)
{
	cout << endl;

	int i;
	for (i = 0; i < level; i++)
		cout << "\t";
	if (!start)
		cout << "¦±¦¬ ";

	cout << command->fullname() << "(" << command->name() << ")" << endl;
	
	ArrayList<Command*>* cmds = command->get_Commands();
	for (i = 0; i < cmds->size(); i++)
		show_Commands(cmds->get(i), level + 1, false);
}

void Help::subs_error(string* current, string* next)
{
	subs_error_nom(current, next);
}

Help::Help(Command* sixteen)
{
	this->sixteen = sixteen;
}

const char* Help::name()
{
	return "-h";
}

const char* Help::fullname()
{
	return "help";
}

void Help::execute()
{
	show_Commands(sixteen, 0, true);
}
