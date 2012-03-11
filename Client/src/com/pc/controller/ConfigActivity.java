package com.pc.controller;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;

import com.pc.controller.task.AutoSearchTask;

public class ConfigActivity extends Activity {
	
	private Button _searchButton;
	private Button _connectButton;
	public static ConfigActivity object;
	@Override
	public void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.config);
		object = this;
		_searchButton = (Button)findViewById(R.id.SEARCH);
		_connectButton = (Button)findViewById(R.id.CONNECT);
		
		_searchButton.setOnClickListener(new Button.OnClickListener(){

			@Override
			public void onClick(View v) {
		        AutoSearchTask task = new AutoSearchTask();
		        task.run();
			}
			
		});
		
		_connectButton.setOnClickListener(new Button.OnClickListener(){

			@Override
			public void onClick(View v) {			
				Intent intent = new Intent();
				intent.setClass(ConfigActivity.this, ClientActivity.class);
				startActivity(intent);
				
				ConfigActivity.this.finish();
			}
			
		});
				
	}
}
