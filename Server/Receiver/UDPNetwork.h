#pragma once
#include <boost/thread.hpp>
#include <boost/asio.hpp>
#include <string>
#include "Receiver.h"
#include "Network.h"
using namespace std;
using namespace boost;
using namespace boost::asio;

const int defaultBufSize = 1024;
class UDPNetwork: 
	public Network
{
	
private:
	typedef shared_ptr<ip::udp::socket> sock_pt;
	int serverPort;
	bool isRunning;
	unsigned char buf[defaultBufSize];
	sock_pt socket;
    boost::asio::io_service ios;

public:
	UDPNetwork(Receiver * receiver);
	virtual ~UDPNetwork(void);
    void test();
	virtual void start();
	static void sendUDPPacket(string ip,int port);

protected:
	virtual void run();

private:
	void handlePacket(boost::shared_ptr<boost::asio::ip::udp::endpoint> sender_endpoint, 
		const system::error_code& error,
	    unsigned char * buf,
	    int size);

};
