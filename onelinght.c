#ifndef _ONELINGHT_
#define _ONELINGHT_
#include "HardwareInfo.c"
#include <SetMotorCode.h>
#include "light01.c"
#include "speed_control.c"
#include <SetWaitForTime.h>
#include <GetMotorCode.h>

void onelinght(int sp, unsigned long bmp, unsigned long LR)
{
    // extern global var
    extern unsigned int S1;
    extern unsigned int S2;
    extern unsigned int S3;
    extern unsigned int S4;
    extern unsigned int S5;

    long vbmp = 0;
    long vbmp1 = 0;
    long flag = 0;
    SetMotorCode(_M1_);
    SetMotorCode(_M2_);
    bmp=fabs(bmp);
    while (1)
    {
        light01();
        if ( LR==1 )
        {
            if ( flag==1 )
            {
                if ( S1 )
                {
                    speed_control(40, 0);
                }
                else
                {
                    speed_control(0, 40);
                }
            }
            else
            {
                if ( S2||S3||S4||S5 )
                {
                    speed_control(40, 0);
                }
                else
                {
                    if ( S1 )
                    {
                        flag=1;
                        speed_control(40, 0);
                        SetWaitForTime(0.3);
                    }
                    else
                    {
                        speed_control(40, 0);
                        flag=0;
                    }
                }
            }
        }
        else
        {
            if ( flag==1 )
            {
                if ( S5 )
                {
                    speed_control(0, 40);
                }
                else
                {
                    speed_control(40, 0);
                }
            }
            else
            {
                if ( S2||S3||S4||S1 )
                {
                    speed_control(0, 40);
                    flag=0;
                }
                else
                {
                    if ( S5 )
                    {
                        flag=1;
                    }
                    else
                    {
                        speed_control(0, 40);
                    }
                }
            }
        }
        vbmp = GetMotorCode(_M1_);
        vbmp1 = GetMotorCode(_M2_);
        if ( fabs(vbmp)>=bmp||fabs(vbmp1)>=bmp )
        {
            speed_control(0, 0);
            break;
        }
    }
}
#endif

