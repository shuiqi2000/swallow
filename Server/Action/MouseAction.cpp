#include "StdAfx.h"
#include "MouseAction.h"
const uint MouseAction::MOUSEEVENT_LEFT = 0x01;
const uint MouseAction::MOUSEEVENT_RIGHT = 0x02;
const uint MouseAction::MOUSEEVENT_MIDDLE = 0x04;
const uint MouseAction::MOUSEEVENT_ABSOLUTEMOVE = 0x08;
const uint MouseAction::MOUSEEVENT_MOVE = 0x10;
MouseAction::MouseAction(void)
{
}

MouseAction::~MouseAction(void)
{
}
