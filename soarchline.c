#ifndef _SOARCHLINE_
#define _SOARCHLINE_
#include "HardwareInfo.c"
#include <SetMotorCode.h>
#include "speed_control.c"
#include <GetMotorCode.h>
#include "light01.c"
#include <SetWaitForTime.h>

int soarchline(int sp, unsigned int angle)
{
    // extern global var
    extern unsigned int S3;
    extern unsigned int S2;
    extern unsigned int S1;

    int spl = 0;
    int spr = 0;
    long var0 = 0;
    long var1 = 0;
    spl=sp;
    spr=-sp;
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
        light01();
        if ( S1||S2||S3 )
        {
            speed_control(0, 0);
            return 1;
        }
    }
    speed_control(0, 0);
    SetWaitForTime(0.3);
    SetMotorCode(_M1_);
    SetMotorCode(_M2_);
    spl=-spl;
    spr=-spr;
    speed_control(spl, spr);
    while (1)
    {
        var0 = GetMotorCode(_M1_);
        var1 = GetMotorCode(_M2_);
        if ( abs(var0)>=angle*2||abs(var1)>=angle*2 )
        {
            break;
        }
        light01();
        if ( S1||S2||S3 )
        {
            speed_control(0, 0);
            return 1;
        }
    }
    speed_control(0, 0);
    SetWaitForTime(0.3);
    SetMotorCode(_M1_);
    SetMotorCode(_M2_);
    spl=-spl;
    spr=-spr;
    speed_control(spl, spr);
    while (1)
    {
        var0 = GetMotorCode(_M1_);
        var1 = GetMotorCode(_M2_);
        if ( abs(var0)>=angle||abs(var1)>=angle )
        {
            break;
        }
        light01();
        if ( S1||S2||S3 )
        {
            speed_control(0, 0);
            return 1;
        }
    }
    speed_control(0, 0);
    return ;
}
#endif

