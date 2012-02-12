#include "StdAfx.h"
#include "Receiver.h"
#include "UDPNetwork.h"
#include "../Action/MouseEventMouseAction.h"

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
void Receiver::handleData(char * buf){
	
	MouseEventMouseAction ma;
	
	ma.action(MouseAction::MOUSEEVENT_MOVE, 1, 1, 0);
	
}