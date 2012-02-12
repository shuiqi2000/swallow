#pragma once

typedef unsigned int uint;
class MouseAction
{
public:
	MouseAction(void);
	virtual ~MouseAction(void);

public:
	/*
    virtual void leftDown()=0;
	virtual void leftUp()=0;
	virtual void rightDown()=0;
	virtual void rightUp()=0;
	virtual void middleDown()=0;
	virtual void middleUp()=0;
	virtual void move(int flag,int dx, int dy)=0;
	*/
/*
action: 
     d2     d1    d0
	 middle right left
*/
	virtual void action(uint action, uint dx, uint dy, int  wheel)=0;

public:

	const static uint MOUSEEVENT_LEFT;
	const static uint MOUSEEVENT_RIGHT;
	const static uint MOUSEEVENT_MIDDLE;
	const static uint MOUSEEVENT_ABSOLUTEMOVE;
	const static uint MOUSEEVENT_MOVE;

};
