#ifndef CONFIGRECEIVER_H
#define CONFIGRECEIVER_H
#include "Receiver.h"
class ConfigReceiver:public Receiver
{
public:
	ConfigReceiver(Network * network);
	~ConfigReceiver(void);
public:
	virtual void handleData(unsigned char * buf);
};
#endif
