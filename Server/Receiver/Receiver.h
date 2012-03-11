#pragma once
#include "Network.h"
class Network;
class Receiver
{
public:
	Receiver(Network * network);
	virtual ~Receiver(void);
public:
	virtual void start();
	virtual void handleData(unsigned char * buf);
protected:
	Network* network;
};
