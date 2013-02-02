#include "ConfigParser.h"
#include "../log/Log.h"

int ConfigParser::deviceType = 0;

ConfigParser::ConfigParser(void)
{
	ActionParserHandle::getInstance()->addActionParser(deviceType, this);
}

ConfigParser::~ConfigParser(void)
{
    
}

int ConfigParser::parse(unsigned char *data, Receiver * receiver){
    Log::debug(std::string("ConfigReceiver::handleData"));
    Log::debug(std::string((char *)data));
	if (data[0] == 0 && data[1] == 1){
		unsigned char buf[8];
		buf[0] = buf[1] = 1;
		receiver -> getNetwork() -> send(buf, 8);
	}
}

ConfigParser configParser;
