package com.pc.controller;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.GestureDetector;
import android.view.GestureDetector.OnGestureListener;
import android.view.KeyEvent;
import android.view.MotionEvent;
import android.widget.Toast;

import com.pc.controller.action.MouseAction;

public class ClientActivity extends Activity implements OnGestureListener

{
    /** Called when the activity is first created. */
	private int lastX;
	private int lastY;
	private int distance = 0;
	private GestureDetector gd;  
	private MouseAction mouseAction;
	public static ClientActivity mainActivity;
	
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        Bundle bundle = this.getIntent().getExtras();
        if (bundle != null && bundle.containsKey("HostAddr")){
        	mouseAction = new MouseAction(bundle.getString("HostAddr"));
        } else {
        	//
        }
        mainActivity = this;
        setContentView(R.layout.main);

        gd = new GestureDetector(this);
        gd.setIsLongpressEnabled(true);  
        
    }
    
    public boolean onTouchEvent(MotionEvent event){
    	int iAction = event.getAction();
    	if (iAction == MotionEvent.ACTION_CANCEL ){
    		return false;
    	}
    
    	if (iAction == MotionEvent.ACTION_MOVE){ 	
    	  int x = (int)event.getX();
    	  int y = (int)event.getY();
    	  Short dx = (short)(x-lastX);
    	  Short dy = (short)(y-lastY);

    	  mouseAction.send((short)MouseAction.MOUSEEVENT_MOVE, dx, dy, (short)0);
    	  distance += dx*dx +dy*dy;
    	//  DisplayToast("Network: (" + dx + "," + dy + "ww)");
    	  lastX = x;
    	  lastY = y;
    	} else {
    	  gd.onTouchEvent(event);
    	}

    	return super.onTouchEvent(event);
    }
    
    public void DisplayToast(String str){
    	Toast.makeText(this, str, Toast.LENGTH_SHORT).show();
    }

	@Override
	public boolean onDown(MotionEvent event) {
		int x = (int)event.getX();
    	int y = (int)event.getY();
    	lastX = x;
    	lastY = y;
    	distance = 0;
    //	DisplayToast("Down: (" + x + "," + y + ")");
		return false;
	}

	@Override
	public boolean onFling(MotionEvent e1, MotionEvent e2, float velocityX,
			float velocityY) {
		DisplayToast("Fling");
		return false;
	}

	@Override
	public void onLongPress(MotionEvent e) {
	    if (distance == 0){
		mouseAction.send((short)MouseAction.MOUSEEVENT_RIGHT, (short)0, (short)0, (short)0);
		mouseAction.send((short)0, (short)0, (short)0, (short)0);
		DisplayToast("LongPress");
	   }
		
	}

	@Override
	public boolean onScroll(MotionEvent e1, MotionEvent e2, float distanceX,
			float distanceY) {
		//DisplayToast("Scroll");
		return false;
	}

	@Override
	public void onShowPress(MotionEvent e) {
	//	mouseAction.send((short)MouseAction.MOUSEEVENT_RIGHT, (short)0, (short)0, (short)0);
	//	DisplayToast("ShowPress");		
	}

	@Override
	public boolean onSingleTapUp(MotionEvent e) {
		mouseAction.send((short)MouseAction.MOUSEEVENT_LEFT, (short)0, (short)0, (short)0);
		mouseAction.send((short)0, (short)0, (short)0, (short)0);
		DisplayToast("SingleTapUp");	
		return false;
	}
	
	public boolean onKeyDown(int keyCode, KeyEvent event)  {   
	    if (keyCode == KeyEvent.KEYCODE_BACK && event.getRepeatCount() == 0) {   
	    	Intent intent = new Intent();  
	    	intent.setClass(ClientActivity.this, PCListActivity.class);
			startActivity(intent);
			finish();
	        return true;   
	    }   
	  
	    return super.onKeyDown(keyCode, event);   
	}  

}