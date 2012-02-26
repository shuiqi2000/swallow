#include "StdAfx.h"
#include "MouseActionParser.h"
#include "../action/MouseAction.h"
#include "../action/MouseEventMouseAction.h"

int MouseActionParser::deviceType = 1;

MouseActionParser::MouseActionParser(void)
{
	ActionParserHandle::getInstance()->addActionParser(deviceType, this);
	mouseAction = new MouseEventMouseAction;
}

MouseActionParser::~MouseActionParser(void)
{
}

int MouseActionParser::parse(unsigned char *data){
	
	mouseAction->action(*(usint *)(data + 1), *(usint *)(data + 3), *(usint *)(data + 5), *(sint *)(data + 7));
	return 0;
}

MouseActionParser mouseActionParser;