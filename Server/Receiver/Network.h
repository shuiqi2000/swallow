#ifndef NETWORK_H
#define NETWORK_H
#include "Receiver.h"

class Receiver;
class Network
{
public:
	Network();
	virtual ~Network(void);
	virtual void start();
	void setReceiver(Receiver * receiver);
	virtual int send(unsigned char * data, int length);

protected:
	Receiver * receiver;

};
#endif
