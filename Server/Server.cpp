#include "stdafx.h"
#include "Server.h"
#include "Receiver/Receiver.h"

int APIENTRY _tWinMain(HINSTANCE hIns,
                     HINSTANCE hPrevIns,
                     LPTSTR    lpCmdLine,
                     int       nCmdShow)
{
	Receiver receiver;
	receiver.start();	
    return 1;
}




