#ifndef ACTIONRECEIVER_H
#define ACTIONRECEIVER_H
#include "Receiver.h"
#include "Network.h"
class ActionReceiver : public Receiver
{
public:
	ActionReceiver(Network * network);
	~ActionReceiver(void);
public:
	void handleData(unsigned char * buf);
};
#endif
