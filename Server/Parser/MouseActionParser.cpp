#include "StdAfx.h"
#include "MouseActionParser.h"
#include "../action/MouseAction.h"
#include "../action/MouseEventMouseAction.h"
int MouseActionParser::deviceType = 1;
MouseActionParser::MouseActionParser(void)
{
	ActionParserHandle::getInstance()->addActionParser(deviceType, this);
}

MouseActionParser::~MouseActionParser(void)
{
}

int MouseActionParser::parse(char *data){
	MouseAction* mouseAction = new MouseEventMouseAction;
	mouseAction->action(*(uint *)(data + 1), *(uint *)(data + 3), *(uint *)(data + 5), *(int *)(data + 7));
	return 0;
}

MouseActionParser mouseActionParser;