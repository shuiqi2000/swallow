#pragma once
#include "mouseaction.h"
#include <winuser.h>

class MouseEventMouseAction :
	public MouseAction
{
public:
	MouseEventMouseAction(void);
	virtual ~MouseEventMouseAction(void);
	virtual void action(uint flag, uint dx, uint dy, int  wheel);

public:
	uint lastFlag;
};

