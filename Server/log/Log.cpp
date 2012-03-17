// Log.cpp: implementation of the Log class.
//
//////////////////////////////////////////////////////////////////////

#include <fstream>
#include "Log.h"
#include <string>
using namespace std;


//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
//HANDLE Log::hEvent=NULL;
Log::Log()
{
//	strcpy(this->logfile,"

}

Log::Log(char *logfile)
{
	strcpy(this->logfile,logfile);
}

Log::~Log()
{

}

void Log::warning(char *info){
	if(info==NULL)return;
}

void Log::debug(std::string info){
//    WaitForSingleObject(hEvent, INFINITE);

//	CTime now;
//	now=CTime::GetCurrentTime();
//    char strDate[50];
//	sprintf(strDate,"%4d-%02d-%02d",now.GetYear(),now.GetMonth(),now.GetDay());
//    char strTime[50];
//	sprintf(strTime,"%4d-%02d-%02d %02d:%02d:%02d"
//		,now.GetYear()
//		,now.GetMonth()
//		,now.GetDay()
//		,now.GetHour()
//		,now.GetMinute()
//		,now.GetSecond());
	char logfile[100]="c:\\log\\swallow.txt";
    ofstream logstream(logfile,ios::app);
//	logstream.open(logfile,ios::app);
	logstream<<"debug:"<<info<<endl;
	logstream.close();
	
//	ReleaseMutex(hEvent);
}

void Log::error(char *info){
	if(info==NULL)return;

}
