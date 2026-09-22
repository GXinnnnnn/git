#ifndef _TURN_O_
#define _TURN_O_
#include "HardwareInfo.c"
#include <SetMotorCode.h>
#include "speed_control.c"
#include <GetMotorCode.h>

void turn_o(unsigned int angle, int spl, int spr)
{
    long var0 = 0;
    long var1 = 0;
    SetMotorCode(_M1_);
    SetMotorCode(_M2_);
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
}
#endif

