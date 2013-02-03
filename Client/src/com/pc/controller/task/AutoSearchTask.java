package com.pc.controller.task;

import java.util.ArrayList;
import java.util.List;

import android.os.AsyncTask;

import com.pc.controller.PCListActivity;
import com.pc.controller.config.Config;
import com.pc.controller.network.Network;
import com.pc.controller.network.UDPNetwork;

public class AutoSearchTask extends AsyncTask<String, Integer, List<String[]>>{
	private PCListActivity activity = null;
	private int addrSum = 0;
	private int addrCount = 0;
	Network network = new UDPNetwork(Config.controlPort);
	
	public AutoSearchTask(PCListActivity activity){
		this.activity = activity;
		activity.startWait();
		Broadcast broadcast = new Broadcast();
		broadcast.start();
	}
	
	public class Broadcast extends Thread{
		public void run(){
			String[] addrs = UDPNetwork.getNetworkObjects(activity);
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
	protected List<String[]> doInBackground(String... params) {
		List<String[]> hostList = new ArrayList<String[]>();
		byte[] data = null;
		for(int i =0; i<1; i++){
		  Object[] res = network.receive();
		  if(res == null){
			  continue;
		  }
		  data = (byte[])res[1];
		  if (data != null && data.length >= 2 && data[0] == 1
				&& data[1] == 1) {
			String [] host = new String[2];
			host[0] = (String)res[0];
			host[1] = new String(data);
			hostList.add(host);
		  }
		}
		return hostList;
	}
	
	protected void onPostExecute(List<String[]> result){
		if (result != null && !result.isEmpty()){
			//Config.ip = result;
			activity.setHostList(result);
		} 
		activity.stopWait();
	}

}
