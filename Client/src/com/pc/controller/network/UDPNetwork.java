package com.pc.controller.network;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.SocketException;
import java.net.UnknownHostException;

import android.widget.Toast;

public class UDPNetwork extends Network{
	private int port;
	private String ip;
	public UDPNetwork(){
		port = 10000;
		ip = "192.168.0.102";
	}
	
	public int send(byte[] data){
    	try {
			DatagramSocket socket = new DatagramSocket();
			InetAddress serverAddress = InetAddress.getByName(ip);
			DatagramPacket packet = new DatagramPacket(data,data.length,serverAddress,port);			
			socket.send(packet);
		} catch (SocketException e) {
			// TODO Auto-generated catch block
			return 1;
		} catch (UnknownHostException e) {
			// TODO Auto-generated catch block
			return 1;
		} catch (IOException e) {
			// TODO Auto-generated catch block
			return 1;
		}
		return 0;
	}

}
