#pragma once
#include "actionparser.h"
#include "ActionParserHandle.h"

class MouseActionParser :
	public ActionParser
{
public:
	MouseActionParser(void);
	~MouseActionParser(void);
public:
	virtual int parse(char *data);
public:
	static int deviceType;
};

extern MouseActionParser mouseActionParser;