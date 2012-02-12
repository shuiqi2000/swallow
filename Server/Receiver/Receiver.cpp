#include "StdAfx.h"
#include "Receiver.h"
#include "UDPNetwork.h"
#include "../Action/MouseEventMouseAction.h"
#include "../parser/ActionParserHandle.h"

Receiver::Receiver(void)
{
	network = new UDPNetwork(this);
}

Receiver::~Receiver(void)
{
	delete network;
}

void Receiver::start(){
	network->start();
}
void Receiver::handleData(char * data){
	ActionParser* actionParser = ActionParserHandle::getInstance()->getActionParser(1);
	if(actionParser != NULL){
		actionParser->parse(data);
	}
	/*
	MouseEventMouseAction ma;
	ma.action(MouseAction::MOUSEEVENT_MOVE, 1, 1, 0);
	*/
}