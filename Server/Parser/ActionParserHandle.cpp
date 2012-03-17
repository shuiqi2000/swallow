#include "ActionParserHandle.h"

ActionParserHandle* ActionParserHandle::actionParserHandle = NULL;
ActionParserHandle::ActionParserHandle(void)
{
}

ActionParserHandle::~ActionParserHandle(void)
{
}

void ActionParserHandle::addActionParser(int deviceType, ActionParser * parser){
    actionParserMap[deviceType] = parser;
}

ActionParser * ActionParserHandle::getActionParser(int deviceType){
    return actionParserMap[deviceType];
}

ActionParserHandle* ActionParserHandle::getInstance(){
	if (actionParserHandle == NULL){
		actionParserHandle = new ActionParserHandle;
	}
	return actionParserHandle;
}
