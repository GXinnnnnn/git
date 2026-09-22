#ifndef _TURN_ANGLE_
#define _TURN_ANGLE_
#include "HardwareInfo.c"
#include <SetWaitForTime.h>
#include <SetMotorCode.h>
#include "speed_control.c"
#include <GetMotorCode.h>

void turn_angle(int spl, int spr, unsigned int angle)
{
    long var0 = 0;
    long var1 = 0;
    SetWaitForTime(0.2);
    angle=abs(angle);
    SetMotorCode(_M1_);
    SetMotorCode(_M2_);
    speed_control(spl, spr);
    while (1)
    {
        var0 = GetMotorCode(_M1_);
        var1 = GetMotorCode(_M2_);
        if ( abs(var0)>=angle||abs(var1)>=angle )
        {
            break;
        }
    }
    speed_control(0, 0);
    SetWaitForTime(0.2);
}
#endif

