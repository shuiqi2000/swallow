#include "StdAfx.h"
#include "UDPNetwork.h"

UDPNetwork::UDPNetwork(Receiver * receiver):Network(receiver){
    serverPort = 10000;
	isRunning = true;
	socket = shared_ptr<ip::udp::socket>(new ip::udp::socket(ios,ip::udp::endpoint(ip::udp::v4(),serverPort)));
}

UDPNetwork::~UDPNetwork(void)
{

}

void UDPNetwork::test(){
	  OutputDebugString("test");
	  run();
	  ios.run();
}
void UDPNetwork::start(){
	//networkThread.join();
	run();
	ios.run();
	//thread networkThread(boost::bind(&Network::run,this));
}

void UDPNetwork::run(){
	if (isRunning){
	    memset(buf,0,defaultBufSize);
  
	    shared_ptr<boost::asio::ip::udp::endpoint> sender_endpoint(new boost::asio::ip::udp::endpoint);
	    boost::asio::socket_base::receive_buffer_size receive_buffer_size(64 * 1024 * 1024);
        socket->set_option(receive_buffer_size);

	    socket->async_receive_from(buffer(buf), *sender_endpoint,
		                           boost::bind(&UDPNetwork::handlePacket,
		                                       this,
					                           sender_endpoint,
		                                       placeholders::error,
					                           buf,
					                           placeholders::bytes_transferred)); 
    
	}

}

void UDPNetwork::handlePacket(boost::shared_ptr<boost::asio::ip::udp::endpoint> sender_endpoint, 
		const system::error_code& error,
	    unsigned char * buf,
	    int size){

	unsigned char * useBuf = new unsigned char[defaultBufSize];
	memcpy(useBuf, buf, defaultBufSize);
	OutputDebugString("\r\n");
	OutputDebugString(sender_endpoint->address().to_string().c_str());
    OutputDebugString("\r\n");

	receiver->handleData(useBuf);

	run();

}

void UDPNetwork::sendUDPPacket(string ip,int port){
	OutputDebugString("Network::sendUDPPacket");
	
	io_service ios1;
	ip::udp::endpoint send_ep(ip::address::from_string(ip),port);
	ip::udp::socket sock(ios1);
    sock.open(ip::udp::v4());
	sock.send_to(buffer("test"),send_ep);
	
}
