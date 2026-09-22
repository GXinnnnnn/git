#ifndef _SINGLE_DRIVE_
#define _SINGLE_DRIVE_
#include "HardwareInfo.c"
#include <SetMotorCode.h>
#include <SetMotor.h>
#include <GetMotorCode.h>
#include "speed_control.c"

void single_drive(int mode, int sp, int angle)
{
    angle=abs(angle);
    SetMotorCode(_M1_);
    SetMotor(_M1_, sp);
    while (1)
    {
        var0 = GetMotorCode(_M1_);
        if ( abs(var0)>=angle )
        {
            break;
        }
    }
    speed_control(0, 0);
}
#endif

