#pragma once
#include <iostream>
#include <Windows.h>

using namespace std;

namespace Console
{
    enum {
        BLACK,
        DARK_BLUE,
        DARK_GREEN,
        DARK_SKYBLUE,
        DARK_RED,
        DARK_VOILET,
        DAKR_YELLOW,
        GRAY,
        DARK_GRAY,
        BLUE,
        GREEN,
        SKYBLUE,
        RED,
        VIOLET,
        YELLOW,
        WHITE,
    };

	void set_Color(char fore, char back);

    void write_Message(char* msg);
	void write_Warning(char* msg);
	void write_Error(char* msg);
};

