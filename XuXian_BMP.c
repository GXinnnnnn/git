#ifndef _XUXIAN_BMP_
#define _XUXIAN_BMP_
#include "HardwareInfo.c"
#include <SetMotorCode.h>
#include "light01.c"
#include "speed_control.c"
#include <GetMotorCode.h>

void XuXian_BMP(int bmp, int sp)
{
    // extern global var
    extern unsigned int S1;
    extern unsigned int S2;
    extern unsigned int S3;
    extern unsigned int S4;
    extern unsigned int S5;

    long vbmp = 0;
    long vbmp1 = 0;
    SetMotorCode(_M1_);
    SetMotorCode(_M2_);
    bmp=fabs(bmp);
    while (1)
    {
        light01();
        if ( S1==0&&S2==0&&S3==0&S4==0&&S5==0 )
        {
            speed_control(30, 30);
        }
        else
        {
            if ( S2==1 )
            {
                speed_control(40, 50);
            }
            else
            {
                if ( S3==1 )
                {
                    speed_control(40, 40);
                }
                else
                {
                    if ( S4==1 )
                    {
                        speed_control(50, 40);
                    }
                    else
                    {
                        if ( S1==1 )
                        {
                            speed_control(30, 50);
                        }
                        else
                        {
                            if ( S5==1 )
                            {
                                speed_control(50, 30);
                            }
                        }
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

