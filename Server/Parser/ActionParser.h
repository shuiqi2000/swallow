#ifndef ACTIONPARSER_H
#define ACTIONPARSER_H
#include <map>
using namespace std;
class ActionParser
{
public:
	ActionParser(void);
	~ActionParser(void);
public:
	virtual int parse(unsigned char * data);

};
#endif
