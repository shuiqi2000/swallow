#ifndef CONFIGPARSER_H
#define CONFIGPARSER_H
#include "actionparser.h"
#include "ActionParserHandle.h"

class ConfigParser :
	public ActionParser
{
public:
	ConfigParser(void);
	~ConfigParser(void);
public:
	virtual int parse(unsigned char *data, Receiver * receiver);
public:
	static int deviceType;
};

extern ConfigParser configParser;
#endif
