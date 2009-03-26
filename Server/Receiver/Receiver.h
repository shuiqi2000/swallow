#ifndef RECEIVER_H
#define RECEIVER_H
#include "Control.h"
#include "Network.h"
#include <list>
class Network;
class Receiver: public Control
{
public:
	Receiver(Network * network);
	virtual ~Receiver(void);
public:
	virtual void start();
	virtual void handleData(unsigned char * buf);
	virtual Network * getNetwork();
protected:
	Network* network;
};
#endif
