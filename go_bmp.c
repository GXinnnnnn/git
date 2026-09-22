#ifndef _GO_BMP_
#define _GO_BMP_
#include "HardwareInfo.c"
#include <SetMotorCode.h>
#include <SetMotor.h>
#include <GetMotorCode.h>
#include <SetInBeep.h>
#include <SetWaitForTime.h>
#include "speed_control.c"
#include <GetLightSensor.h>

extern u16 tempCS;

void go_bmp(int bmp, int spl, int spr)
{
    long vl = 0;
    long vr = 0;
    SetMotorCode(_M1_);
    SetMotorCode(_M2_);
    bmp=abs(bmp);
    SetMotor(_M1_, spl);
    SetMotor(_M2_, spr);
    while (1)
    {
        vl = GetMotorCode(_M1_);
        vr = GetMotorCode(_M2_);
        if ( abs(vl)>=bmp&&abs(vr)<=bmp )
        {
            SetMotor(_M1_, 0);
            SetMotor(_M2_, 30);
        }
        else
        {
            if ( abs(vl)<=bmp&&abs(vr)>=bmp )
            {
                SetMotor(_M1_, 30);
                SetMotor(_M2_, 0);
            }
            else
            {
                if ( abs(vl)>=bmp&&abs(vr)>=bmp )
                {
                    break;
                }
            }
        }
    }
    SetInBeep(ON);
    SetWaitForTime(0.05);
    SetInBeep(OFF);
    speed_control(0, 0);
}
#endif

