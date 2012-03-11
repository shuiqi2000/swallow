package com.pc.controller.task;

import com.pc.controller.config.Config;
import com.pc.controller.network.Network;
import com.pc.controller.network.UDPNetwork;

public class AutoSearchTask {
	public void run(){
		Network network = new UDPNetwork(Config.configPort);
		String[] addrs = UDPNetwork.getNetworkObjects();
		String dAddr = null;
		for (String addr : addrs){
			byte[] buf = {0x1,0x1,0x0,0x0,0x0,0x0,0x0,0x0};
			network.send(buf, addr);
			byte[] data = network.receive();
			if (data!=null && data.length >= 2 && data[0] == 1 && data[1] == 1){
				dAddr = addr;
				break;
			}
		}
		Config.ip = dAddr;
	}

}
