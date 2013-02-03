package com.pc.controller;

import java.util.List;

import android.app.Activity;
import android.app.ProgressDialog;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.ListView;

import com.pc.controller.config.Config;
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
		String[] hostArray = convertToHostArray(hostList);
		ArrayAdapter<String> arrayAdapter = new ArrayAdapter<String>(this,
                android.R.layout.simple_list_item_1, hostArray);
		_hostListView.setAdapter(arrayAdapter);
	}
	
	private String[] convertToHostArray(List<String[]> hostList){
		String [] hostArray = new String[hostList.size()];
		int index = 0;
		for(String[] host : hostList){
			hostArray[index++] = host[0];
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

}
