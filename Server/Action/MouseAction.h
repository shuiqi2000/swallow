#pragma once

typedef unsigned short int usint;
typedef short int sint;
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
	virtual void action(usint action, usint dx, usint dy, sint  wheel)=0;

public:

	const static usint MOUSEEVENT_LEFT;
	const static usint MOUSEEVENT_RIGHT;
	const static usint MOUSEEVENT_MIDDLE;
	const static usint MOUSEEVENT_ABSOLUTEMOVE;
	const static usint MOUSEEVENT_MOVE;

};
