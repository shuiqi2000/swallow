package com.pc.controller.network;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.PortUnreachableException;
import java.net.SocketException;
import java.net.SocketTimeoutException;
import java.net.UnknownHostException;

import android.app.Activity;
import android.content.Context;
import android.net.DhcpInfo;
import android.net.wifi.WifiManager;

import com.pc.controller.PCListActivity;

public class UDPNetwork extends Network{
	private int port;
	private DatagramSocket socket = null;
	private int waitTime = 10000;
	private String hostAddr;
	public UDPNetwork(String hostAddr, int port){
		this.port = port;
		this.hostAddr = hostAddr;
		try {
			socket = new DatagramSocket();
			socket.setSoTimeout(waitTime);
		} catch (SocketException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	public UDPNetwork(int port){
		this.port = port;
		try {
			socket = new DatagramSocket();
			socket.setSoTimeout(waitTime);
		} catch (SocketException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	public UDPNetwork(String ip){
		port = 10001;
		try {
			socket = new DatagramSocket();
			socket.setSoTimeout(waitTime);
		} catch (SocketException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	public boolean isConnected(String addr){
		InetAddress serverAddress;
		try {
			serverAddress = InetAddress.getByName(addr);
			socket.connect(serverAddress, port);
			return socket.isConnected();
		} catch (UnknownHostException e) {
			return false;
		}

	}
	
	public int send(byte[] data, String addr){
    	try {
			InetAddress serverAddress = InetAddress.getByName(addr);
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
	public int send(byte[] data){
    	try {
	
			InetAddress serverAddress = InetAddress.getByName(hostAddr);
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

	
	public Object[] receive(){
	    try {
	    	Object[] result = new Object[2];
	    	byte[] rbuf = {0,0,0,0,0,0,0,0};
	    	DatagramPacket packet = new DatagramPacket(rbuf, rbuf.length);
	    	socket.receive(packet);
	    	result[0] = packet.getAddress().getHostName();
	    	result[1] = rbuf;
 	    	return result;
	    } catch (SocketTimeoutException ste){
			ste.printStackTrace();
		} catch (PortUnreachableException pue){
		    pue.printStackTrace();
		} catch (SocketException e) {	   
	    	e.printStackTrace();
	    } catch (IOException e) {
			e.printStackTrace();
		} 
	    
	    return null;	
	}
	
	public static String[] getNetworkObjects(Activity activity){

		WifiManager wifii= (WifiManager) activity.getSystemService(Context.WIFI_SERVICE);
		DhcpInfo dhcpInfo=wifii.getDhcpInfo();
		int netmask = toHH(dhcpInfo.netmask);
		int ipAddress = toHH(dhcpInfo.ipAddress);
		int boardAddress = -1; // 0xFFFFFFFF
		int networkAddress = ipAddress & netmask;
		int networkSize = netmask ^ boardAddress;
		String [] addrs = new String[networkSize];
		for (int i = 1; i < networkSize; i++){
			int addr = networkAddress + i;
			addrs[i-1] = intToIp(addr);
		}
				
		return addrs;
	}
	
	/**  
     * 把int->ip地址  
     * @param ipInt  
     * @return String  
     */  
    public static String intToIp(int ipInt) {   
        return new StringBuilder().append(((ipInt >> 24) & 0xff)).append('.')   
                .append((ipInt >> 16) & 0xff).append('.').append(   
                        (ipInt >> 8) & 0xff).append('.').append((ipInt & 0xff))   
                .toString();   
    }   
	
    /**  
     * 将 int转为高字节在前，低字节在后的byte数组  
     * @param n int  
     * @return byte[]  
     */   
   public   static   int toHH( int  n) {  
     int res = 0;
     res |= (n & 0xff) <<24;
     res |= (n >>  8  &  0xff) <<16;
     res |= (n >>  16  &  0xff) <<8;
     res |=  n >>  24  &  0xff;

     return res;
   }   

}
