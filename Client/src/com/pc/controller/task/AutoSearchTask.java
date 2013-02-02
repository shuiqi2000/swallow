package com.pc.controller.task;

import java.util.ArrayList;
import java.util.List;

import android.os.AsyncTask;

import com.pc.controller.ConfigActivity;
import com.pc.controller.config.Config;
import com.pc.controller.network.Network;
import com.pc.controller.network.UDPNetwork;

public class AutoSearchTask extends AsyncTask<String, Integer, String>{
	private ConfigActivity activity = null;
	private int addrSum = 0;
	private int addrCount = 0;
	Network network = new UDPNetwork(Config.controlPort);
	
	public AutoSearchTask(ConfigActivity activity){
		this.activity = activity;
		activity.startWait();
		Broadcast broadcast = new Broadcast();
		broadcast.start();
	}
	
	public class Broadcast extends Thread{
		public void run(){
			String[] addrs = UDPNetwork.getNetworkObjects();
			addrSum = addrs.length;
			for (String addr : addrs) {
				if (addr == null){
					continue;
				}
				byte[] buf = { 0x0, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 };
				byte[] data = null;
				try {			
					network.send(buf, addr);
				} catch (Exception e) {
					continue;
				}
			}
		}
	}
	
	@Override
	protected String doInBackground(String... params) {
		byte[] data = null;
		Object[] res = network.receive();
		data = (byte[])res[1];
		if (data != null && data.length >= 2 && data[0] == 1
				&& data[1] == 1) {
			return (String)res[0];
		}
		return null;
	}
	
	protected void onPostExecute(String result){
		if (result != null){
			Config.ip = result;
			activity.setPCAddr(result);
		} 
		activity.stopWait();
	}

}
