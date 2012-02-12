#pragma once
#include <map>
#include "ActionParser.h"
using namespace std;
class ActionParserHandle
{
private:
	ActionParserHandle(void);
public:
	~ActionParserHandle(void);

public:
	map<int, ActionParser *> actionParserMap;
	void addActionParser(int deviceType, ActionParser * parser);
	ActionParser * getActionParser(int deviceType);
	static ActionParserHandle* getInstance();

private:
	static ActionParserHandle* actionParserHandle;
	
};
