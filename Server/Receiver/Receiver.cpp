#include "Receiver.h"

Receiver::Receiver(Network * network)
{
	this->network = network;
	this->network->setReceiver(this);
}

Receiver::~Receiver(void)
{
	if (network != 0){
	    delete network;
	}
}

void Receiver::start(){
    network->start();
}

void Receiver::handleData(unsigned char * data){

}

