package com.pc.controller;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import android.app.Activity;
import android.app.ProgressDialog;
import android.content.Intent;
import android.os.Bundle;
import android.view.KeyEvent;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ListView;
import android.widget.SimpleAdapter;

import com.pc.controller.task.AutoSearchTask;

public class PCListActivity extends Activity {
	
	public static PCListActivity object;
	private List<String[]> hostList;
	private ProgressDialog _pd;
	
	private ListView _hostListView;
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		object = this;
		setContentView(R.layout.pclist);
		_hostListView = (ListView)findViewById(R.id.pcListView);
        _hostListView.setDivider(null);
		_hostListView.setOnItemClickListener(new AdapterView.OnItemClickListener() {

			@Override
			public void onItemClick(AdapterView<?> parent, View view,
					int position, long id) {
				connect(hostList.get(position)[0]);
			}
		});
		
		
		populateHost();
	}
	
	public void populateHost(){
		AutoSearchTask searchTask = new AutoSearchTask(this);
		searchTask.execute(null);
	}
	
	public void setHostList(List<String[]> hostList){
		this.hostList = hostList;
		List<Map<String, Object>> hostArray = convertToHostArray(hostList);
		SimpleAdapter simpleAdapter = new SimpleAdapter(this, hostArray, R.layout.pcitem,
                new String[]{"pcimage", "pcname"},
                new int[]{R.id.pcimage, R.id.pcname});
		_hostListView.setAdapter(simpleAdapter);
	}
	
	private List<Map<String, Object>> convertToHostArray(List<String[]> hostList){
		List<Map<String, Object>> hostArray = new ArrayList<Map<String, Object>>();
		for(String[] host : hostList){
			Map<String, Object> hostMap = new HashMap<String, Object>();
			hostMap.put("pcimage", R.drawable.pc);
			hostMap.put("pcname", host[0]);
			hostArray.add(hostMap);
		}
		return hostArray;
	}
	
	public void connect(String address) {			
		Intent intent = new Intent();
		Bundle bundle = new Bundle();
		bundle.putString("HostAddr", address);
		intent.putExtras(bundle);
		intent.setClass(PCListActivity.this, ClientActivity.class);
		
		startActivity(intent);
		
		finish();
	}
	
	public void stopWait(){
		if (_pd != null){
		  _pd.dismiss();
		}
	}
	
	public void startWait(){
		_pd = ProgressDialog.show(this,"同步", "正在同步…");
	}
	
	public boolean onKeyDown(int keyCode, KeyEvent event)  {   
	    if (keyCode == KeyEvent.KEYCODE_BACK && event.getRepeatCount() == 0) {   
	    	finish();
	    	System.exit(0);
	        return true;      
	    }   
	  
	    return super.onKeyDown(keyCode, event);   
	}  

}
