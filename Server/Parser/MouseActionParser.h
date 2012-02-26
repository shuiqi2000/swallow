#pragma once
#include "actionparser.h"
#include "ActionParserHandle.h"
#include "../action/MouseAction.h"

class MouseActionParser :
	public ActionParser
{
public:
	MouseActionParser(void);
	~MouseActionParser(void);
public:
	virtual int parse(unsigned char *data);
public:
	static int deviceType;
private:
	MouseAction* mouseAction;
};

extern MouseActionParser mouseActionParser;