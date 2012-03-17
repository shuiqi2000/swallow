#include "Network.h"

Network::Network(){

}

Network::~Network(void)
{

}

void Network::start(){

}

void Network::setReceiver(Receiver * receiver){
	this->receiver = receiver;
}

int Network::send(unsigned char * data, int length){
	return 0;
}
