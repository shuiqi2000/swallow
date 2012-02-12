#pragma once
#include "Receiver.h"

class Receiver;
class Network
{
public:
	Network(Receiver * receiver);
	virtual ~Network(void);
	virtual void start();

protected:
	Receiver * receiver;

};

