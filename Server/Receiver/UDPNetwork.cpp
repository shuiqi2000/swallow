#include "StdAfx.h"
#include "UDPNetwork.h"

UDPNetwork::UDPNetwork(int port, 
					   boost::asio::io_service& io_service):
							  ios(io_service),
					          serverPort(port)
{
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
	sendIP = sender_endpoint->address().to_string();
	sendPort = sender_endpoint->port();

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

int UDPNetwork::send(unsigned char * data, int length){
	io_service sios;
	if (sendIP == ""){
		return 1;
	}
	ip::udp::endpoint send_ep(ip::address::from_string(sendIP),sendPort);
	ip::udp::socket sock(sios);
    sock.open(ip::udp::v4());
	sock.send_to(buffer(data, length), send_ep);
	return 0;
}