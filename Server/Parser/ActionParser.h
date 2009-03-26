#ifndef ACTIONPARSER_H
#define ACTIONPARSER_H
#include <map>
#include "../receiver/Receiver.h"
using namespace std;
class ActionParser
{
public:
	ActionParser(void);
	~ActionParser(void);
public:
	virtual int parse(unsigned char * data, Receiver * receiver);

};
#endif
