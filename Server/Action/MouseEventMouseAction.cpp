#include "MouseEventMouseAction.h"
#include <sstream>
using namespace std;

MouseEventMouseAction::MouseEventMouseAction(void)
{
	lastFlag = 0;

}

MouseEventMouseAction::~MouseEventMouseAction(void)
{
}

void MouseEventMouseAction::action(usint flag, usint dx, usint dy, sint  wheel){
	usint dwFlags = 0;
	if ((flag & MouseAction::MOUSEEVENT_LEFT)
		&& !(lastFlag & MouseAction::MOUSEEVENT_LEFT)){
		dwFlags |= MOUSEEVENTF_LEFTDOWN;
	    OutputDebugString("MOUSEEVENT_LEFTDOWN");
	}else if ((flag & MouseAction::MOUSEEVENT_LEFT)
		&& (lastFlag & MouseAction::MOUSEEVENT_LEFT)){
        dwFlags |= MOUSEEVENTF_LEFTDOWN;
		OutputDebugString("MOUSEEVENT_LEFTDOWN");
	}

	if (!(flag & MouseAction::MOUSEEVENT_LEFT)
		&& (lastFlag & MouseAction::MOUSEEVENT_LEFT)){
		dwFlags |= MOUSEEVENTF_LEFTUP;
		OutputDebugString("MOUSEEVENT_LEFTUP");
	}

	if ((flag & MouseAction::MOUSEEVENT_RIGHT)
		&& !(lastFlag & MouseAction::MOUSEEVENT_RIGHT)){
		dwFlags |= MOUSEEVENTF_RIGHTDOWN;
		OutputDebugString("MOUSEEVENTF_RIGHTDOWN");
	}else if ((flag & MouseAction::MOUSEEVENT_RIGHT)
		&& (lastFlag & MouseAction::MOUSEEVENT_RIGHT)){
        dwFlags |= MOUSEEVENTF_RIGHTDOWN;
		OutputDebugString("MOUSEEVENTF_RIGHTDOWN");
	}

	if (!(flag & MouseAction::MOUSEEVENT_RIGHT)
		&& (lastFlag & MouseAction::MOUSEEVENT_RIGHT)){
		dwFlags |= MOUSEEVENTF_RIGHTUP;
		OutputDebugString("MOUSEEVENTF_RIGHTUP");
	}

	if (flag & MouseAction::MOUSEEVENT_MOVE){
        dwFlags |= MOUSEEVENTF_MOVE;
		stringstream ss;
		ss<<"MOUSEEVENTF_MOVE ";
		ss<<*(short int *)&dx;
		ss<<" ";
		ss<<*(short int *)&dy;

        OutputDebugString(ss.str().c_str());
	}

	if (flag & MouseAction::MOUSEEVENT_ABSOLUTEMOVE){
		dwFlags |= MOUSEEVENTF_ABSOLUTE;
	}

	mouse_event(dwFlags, dx, dy, 0, 0);

	lastFlag = flag;
}
