#include "stdafx.h"
#include "Server.h"
#include "Receiver/ActionReceiver.h"
#include "Receiver/ConfigReceiver.h"
#include "Receiver/UDPNetwork.h"

int APIENTRY _tWinMain(HINSTANCE hIns,
                     HINSTANCE hPrevIns,
                     LPTSTR    lpCmdLine,
                     int       nCmdShow)
{
	boost::asio::io_service iso;
	Network * actionNetwork = new UDPNetwork(10000,iso);
    ActionReceiver actionReceiver(actionNetwork);
	actionReceiver.start();	
	Network * configNetwork = new UDPNetwork(10001,iso);
	ConfigReceiver configReceiver(configNetwork);
	configReceiver.start();
	iso.run();
    return 0;
}




