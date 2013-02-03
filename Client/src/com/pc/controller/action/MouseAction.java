package com.pc.controller.action;

import com.pc.controller.config.Config;
import com.pc.controller.network.UDPNetwork;

public class MouseAction extends Action {
	public static final int MOUSEEVENT_LEFT = 0x01;
	public static final int MOUSEEVENT_RIGHT = 0x02;
	public static final int MOUSEEVENT_MIDDLE = 0x04;
	public static final int MOUSEEVENT_ABSOLUTEMOVE = 0x08;
	public static final int MOUSEEVENT_MOVE = 0x10;
	
	private UDPNetwork network;
	
	public MouseAction(String addr){
	   network = new UDPNetwork(addr, Config.controlPort);
	}
	
	public void send(short flag, short dx, short dy, short wheel){	
    	  byte[] dxbytes = new byte[2];
    	  dxbytes[0] = (byte)(dx & 0xff);
    	  dxbytes[1] = (byte)((dx & 0xff00) >> 8);
    	  
    	  byte[] dybytes = new byte[2];
    	  dybytes[0] = (byte)(dy & 0xff);
    	  dybytes[1] = (byte)((dy & 0xff00) >> 8);
    	  
    	  byte[] flagbytes = new byte[2];
    	  flagbytes[0] = (byte)(flag & 0xff);
    	  flagbytes[1] = (byte)((flag & 0xff00) >> 8);
    	 
    	  byte data [] = {0x1,flagbytes[0],flagbytes[1],dxbytes[0], dxbytes[1],dybytes[0],dybytes[1],0x0,0x0};
    	  int ret = network.send(data);
	}

}
