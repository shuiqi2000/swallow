package com.pc.controller;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.KeyEvent;
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Spinner;

import com.pc.controller.config.Config;
import com.pc.controller.task.AutoSearchTask;

public class ConfigActivity extends Activity {
	
	private Button _searchButton;
	private Button _connectButton;
	private Spinner _spinner;
	private EditText _address;
	private EditText _port;
	
	public static ConfigActivity object;
	@Override
	public void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.config);
		object = this;
		//_searchButton = (Button)findViewById(R.id.SEARCH);
		_connectButton = (Button)findViewById(R.id.CONNECT);
		_spinner = (Spinner)findViewById(R.id.spinMethod);
		_address =(EditText)findViewById(R.id.editAddr);
		_port =(EditText)findViewById(R.id.editPort);
		String [] methods = new String[]{getString(R.string.MouseControl), getString(R.string.OtherControl)};
		ArrayAdapter<String> adapter = new ArrayAdapter<String>(this, android.R.layout.simple_spinner_item, methods);
		adapter.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item);
		_spinner.setAdapter(adapter);
		_address.setText("192.168.0.100");
		_port.setText("10000");
		/*_searchButton.setOnClickListener(new Button.OnClickListener(){

			@Override
			public void onClick(View v) {
		        AutoSearchTask task = new AutoSearchTask();
		        task.run();
			}
			
		});*/
		_connectButton.setTextSize(20);
		_connectButton.setOnClickListener(new Button.OnClickListener(){

			@Override
			public void onClick(View v) {			
				Intent intent = new Intent();
				String ip = _address.getText().toString();
				if (ip != null){
				    Config.ip = ip.trim();
				}
				
				String port = _port.getText().toString();
				if (port != null){
					Config.controlPort = Integer.parseInt(port.trim());
				}
				
				intent.setClass(ConfigActivity.this, ClientActivity.class);
				startActivity(intent);
				
				finish();
			}
			
		});
				
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
