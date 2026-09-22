#ifndef _BACK_TO_ONLINE_
#define _BACK_TO_ONLINE_
#include "HardwareInfo.c"
#include "light01.c"
#include "speed_control.c"

void Back_To_OnLine(int L_R)
{
    // extern global var
    extern unsigned int S1;
    extern unsigned int S2;
    extern unsigned int S3;
    extern unsigned int S4;
    extern unsigned int S5;

    light01();
    while ( S1==0&&S2==0&&S3==0&S4==0&&S5==0 )
    {
        if ( L_R==0 )
        {
            speed_control(-40, 0);
        }
        else
        {
            speed_control(0, -40);
        }
        light01();
    }
    if ( S1==1||S2==1 )
    {
        while ( S5==0 )
        {
            speed_control(0, -40);
            light01();
        }
    }
    else
    {
        if ( S4==1||S5==1 )
        {
            while ( S1==0 )
            {
                speed_control(-40, 0);
                light01();
            }
        }
    }
    speed_control(0, 0);
}
#endif

