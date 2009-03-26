#ifndef NETWORK_H
#define NETWORK_H
#include "Control.h"
#include "Receiver.h"
class Receiver;
class Network: 
    public Control
{
public:
	Network();
	virtual ~Network(void);
	virtual void start();
	void setReceiver(Receiver * receiver);
	virtual int send(unsigned char * data, int length);
	virtual void close();

protected:
	Receiver * receiver;

};
#endif
