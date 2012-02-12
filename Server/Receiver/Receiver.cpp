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

void Receiver::handleData(unsigned char * data){
	ActionParser* actionParser = ActionParserHandle::getInstance()->getActionParser(data[0]);
	if(actionParser != NULL){
		actionParser->parse(data);
	}
}