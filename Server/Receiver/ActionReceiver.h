#pragma once
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
