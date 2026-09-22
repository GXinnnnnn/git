#ifndef _INIT_
#define _INIT_
#include "HardwareInfo.c"
#include <GetMotorCode.h>
#include <SetMotor.h>
#include <SetWaitForTime.h>
#include <SetInBeep.h>
#include <SetMotorCode.h>
#include <SetLCDBack.h>
#include <SetLCDSolidCircle.h>
#include <SetDisplayStr.h>
#include <GetTouchScreenX.h>
#include <GetTouchScreenY.h>
#include <GetRightButton.h>
#include <SetLCDClear.h>

unsigned int init()
{
    long c4 = 0;
    long c3 = 0;
    long oc3 = 0;
    long oc4 = 0;
    long x = 0;
    long y = 0;
    long b1 = 0;
    long rs = 0;
    oc3 = GetMotorCode(_M3_);
    oc4 = GetMotorCode(_M4_);
    SetMotor(_M3_, -20);
    SetMotor(_M3_, -20);
    while (1)
    {
        SetWaitForTime(0.1);
        c3 = GetMotorCode(_M3_);
        c4 = GetMotorCode(_M4_);
        if ( oc3==c3&&oc4==c4 )
        {
            break;
        }
        oc3=c3;
        oc4=c4;
    }
    SetMotor(_M3_, 0);
    SetMotor(_M4_, 0);
    SetInBeep(ON);
    SetWaitForTime(0.1);
    SetInBeep(OFF);
    SetMotorCode(_M3_);
    SetMotorCode(_M4_);
    SetLCDBack(ON);
    SetLCDSolidCircle(115, 150, 80, YELLOW);
    SetLCDSolidCircle(188, 268, 50, YELLOW);
    SetDisplayStr(175, 265, "זהױ¾", 63488, BLACK);
    while (1)
    {
        x = GetTouchScreenX();
        y = GetTouchScreenY();
        b1 = GetRightButton();
        if ( (x>143 && y>220 ) )
        {
            rs=0;
            break;
        }
        else
        {
            if ( (x>80 && y>100 )||b1 )
            {
                rs=1;
                break;
            }
        }
    }
    SetLCDClear(BLACK);
    return rs;
}
#endif

