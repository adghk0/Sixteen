#include <string>
#include <iostream>
#include "../ArrayList.h"
#include "../trim.h"
#include "Console.h"

//
//#define DEBUG
//

using namespace std;

#pragma once
class Command
{
private:
	ArrayList<Command*>* subs;

	void connect(string* current, string* next);

protected:
	virtual void subs_error(string* current, string* next) = 0;
	void subs_error_nom(string* current, string* next);

public:
	Command();

	void add_Command(Command* command);
	int contain_Command(string* name);
	ArrayList<Command*>* get_Commands();

	void exe(string* command);

	virtual const char* name() = 0;
	virtual const char* fullname() = 0;
	virtual void execute() = 0;
};

/*
protected:
	void subs_error(string* current, string* next);

public:
	Construction();

	const char* name();
	const char* fullname();
	void execute();
*/