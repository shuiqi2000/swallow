#include "stdafx.h"
#include "ConfigReceiver.h"

ConfigReceiver::ConfigReceiver(Network * network):Receiver(network){

}

ConfigReceiver::~ConfigReceiver(void){

}


void ConfigReceiver::handleData(unsigned char * data){
	if (data[0] == 1 && data[1] == 1){
		unsigned char buf[8];
		buf[0] = buf[1] = 1;
		network -> send(buf, 8);
	}
}