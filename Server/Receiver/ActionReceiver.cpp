#include "ActionReceiver.h"
#include "../action/MouseEventMouseAction.h"
#include "../parser/ActionParserHandle.h"

ActionReceiver::ActionReceiver(Network * network):Receiver(network){

}

ActionReceiver::~ActionReceiver(void){

}


void ActionReceiver::handleData(unsigned char * data){
	ActionParser* actionParser = ActionParserHandle::getInstance()->getActionParser(data[0]);
	if(actionParser != NULL){
		actionParser->parse(data);
	}
}
