#pragma once
#include "Network.h"
class Network;
class Receiver
{
public:
	Receiver(void);
	virtual ~Receiver(void);
public:
	void start();
	void handleData(unsigned char * buf);
private:
	Network* network;
};
