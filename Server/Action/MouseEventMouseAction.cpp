#include "StdAfx.h"
#include "MouseEventMouseAction.h"

MouseEventMouseAction::MouseEventMouseAction(void)
{
}

MouseEventMouseAction::~MouseEventMouseAction(void)
{
}

void MouseEventMouseAction::action(uint flag, uint dx, uint dy, int  wheel){
	uint dwFlags = 0;
	if ((flag & MouseAction::MOUSEEVENT_LEFT)
		&& !(lastFlag & MouseAction::MOUSEEVENT_LEFT)){
		dwFlags |= MOUSEEVENTF_LEFTDOWN;
	}else if ((flag & MouseAction::MOUSEEVENT_LEFT)
		&& (lastFlag & MouseAction::MOUSEEVENT_LEFT)){
        dwFlags |= MOUSEEVENTF_LEFTDOWN;
	}

	if (!(flag & MouseAction::MOUSEEVENT_LEFT)
		&& (lastFlag & MouseAction::MOUSEEVENT_LEFT)){
		dwFlags |= MOUSEEVENTF_LEFTUP;
	}

	if ((flag & MouseAction::MOUSEEVENT_RIGHT)
		&& !(lastFlag & MouseAction::MOUSEEVENT_RIGHT)){
		dwFlags |= MOUSEEVENTF_RIGHTDOWN;
	}else if ((flag & MouseAction::MOUSEEVENT_RIGHT)
		&& (lastFlag & MouseAction::MOUSEEVENT_RIGHT)){
        dwFlags |= MOUSEEVENTF_RIGHTDOWN;
	}

	if (!(flag & MouseAction::MOUSEEVENT_RIGHT)
		&& (lastFlag & MouseAction::MOUSEEVENT_RIGHT)){
		dwFlags |= MOUSEEVENTF_RIGHTUP;
	}

	if (flag & MouseAction::MOUSEEVENT_MOVE){
        dwFlags |= MOUSEEVENTF_MOVE;
	}

	if (flag & MouseAction::MOUSEEVENT_ABSOLUTEMOVE){
		dwFlags |= MOUSEEVENTF_ABSOLUTE;
	    
	}

	mouse_event(dwFlags, dx, dy, 0, 0);


}
