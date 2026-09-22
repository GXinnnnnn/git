#ifndef _GOTIME_
#define _GOTIME_
#include "HardwareInfo.c"
#include "speed_control.c"
#include <SetWaitForTime.h>
#include <GetLightSensor.h>

extern u16 tempCS;

void gotime(int spl, int spr, double time)
{
    long vl = 0;
    long vr = 0;
    speed_control(spl, spr);
    SetWaitForTime(time);
    speed_control(0, 0);
}
#endif

