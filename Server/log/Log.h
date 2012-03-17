// Log.h: interface for the Log class.
//
//////////////////////////////////////////////////////////////////////

#ifndef AFX_LOG_H__AACE3DB5_4CBA_4100_B8DA_0A0DE0CE090D__INCLUDED_
#define AFX_LOG_H__AACE3DB5_4CBA_4100_B8DA_0A0DE0CE090D__INCLUDED_

#include <string>
using namespace std;
class Log  
{
public:
//	static HANDLE hEvent;
	char logfile[100];
	Log(char *logfile);
	Log();
	void warning(char *info);
	static void debug(std::string info);
	void error(char *info);

	virtual ~Log();

};

#endif // !defined(AFX_LOG_H__AACE3DB5_4CBA_4100_B8DA_0A0DE0CE090D__INCLUDED_)
