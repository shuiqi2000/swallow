#include "ConfigReceiver.h"
#include "Network.h"
#include "../log/Log.h"
ConfigReceiver::ConfigReceiver(Network * network):Receiver(network){

}

ConfigReceiver::~ConfigReceiver(void){

}


void ConfigReceiver::handleData(unsigned char * data){
    Log::debug(std::string("ConfigReceiver::handleData"));
    Log::debug(std::string((char *)data));
	if (data[0] == 's' && data[1] == 't'){
        Network *network = getNetwork();
        if (network != NULL){
            network -> close();
        }
	}
}
