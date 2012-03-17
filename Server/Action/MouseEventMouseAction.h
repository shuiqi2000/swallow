#ifndef MOUSEEVENTMOUSEACTION_H
#define MOUSEEVENTMOUSEACTION_H
#include "mouseaction.h"
#include <windows.h>
#include <winuser.h>


class MouseEventMouseAction :
	public MouseAction
{
public:
	MouseEventMouseAction(void);
	virtual ~MouseEventMouseAction(void);
	virtual void action(usint flag, usint dx, usint dy, sint  wheel);

public:
	usint lastFlag;
};

#endif
