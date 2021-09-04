#include "Command.h"

void Command::connect(string* current, string* next)
{
	int index = contain_Command(current);
	
	if (index != -1)
		subs->get(index)->exe(next);
	else
		subs_error(current, next);
}

Command::Command()
{
	subs = new ArrayList<Command*>;
}

void Command::exe(string* command)
{
#ifdef DEBUG
	cout << this->name() << ">";
#endif
	trim(*command);
	int i = command->find(' ');

	if (i > 0)
	{
		string cur = command->substr(0, i);
		string nex = command->substr(i);
		trim(cur);
		trim(nex);

		this->connect(&cur, &nex);
	}
	else if(command->length() > 0)
	{
		this->connect(command, new string(""));
	}
	else
	{
		this->execute();
	}
}

void Command::add_Command(Command* command)
{
	subs->add(command);
}

void Command::subs_error_nom(string* current, string* next)
{
	char buf[255];
	sprintf_s(buf, 255, "%s%s - unknown sub command in %s", current->c_str(), next->c_str(), fullname());
	Console::write_Warning(buf);
}

int Command::contain_Command(string* name)
{
	int i;
	
	for (i = 0; i < subs->size(); i++)
	{
		Command* c = subs->get(i);
		if (name->compare(c->name())==0 || name->compare(c->fullname())==0)
			break;
	}

	if (subs->size() == i)
		return -1;
	else
		return i;
}

ArrayList<Command*>* Command::get_Commands()
{
	return subs;
}
