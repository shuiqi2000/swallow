#pragma once
#include <map>
using namespace std;
class ActionParser
{
public:
	ActionParser(void);
	~ActionParser(void);
public:
	virtual int parse(char * data);



};
