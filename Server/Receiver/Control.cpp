#include "Control.h"
Control::Control(){
    isRunning = true;
}
bool Control::shutdown(){
    isRunning = false;
}
