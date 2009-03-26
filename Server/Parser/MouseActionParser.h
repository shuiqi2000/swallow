#ifndef MOUSEACTIONPARSER_H
#define MOUSEACTIONPARSER_H
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
	virtual int parse(unsigned char *data, Receiver * receiver);
public:
	static int deviceType;
private:
	MouseAction* mouseAction;
};

extern MouseActionParser mouseActionParser;
#endif
