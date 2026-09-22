#ifndef _TO_3_ONLINE_
#define _TO_3_ONLINE_
#include "HardwareInfo.c"
#include "light01.c"
#include "turn_w.c"
#include <SetWaitForTime.h>

void To_3_Online(int L_R_turn)
{
    // extern global var
    extern unsigned int S1;
    extern unsigned int S2;
    extern unsigned int S3;
    extern unsigned int S4;
    extern unsigned int S5;

    int time1 = 0;
    int time2 = 0;
    int time_b = 0;
    int time_o = 0;
    light01();
    if ( L_R_turn==5 )
    {
        turn_w(40, -40, 1);
        SetWaitForTime(0.2);
        turn_w(-40, 40, 4);
    }
    if ( L_R_turn==1 )
    {
        turn_w(-40, 40, 5);
        SetWaitForTime(0.2);
        turn_w(40, -40, 2);
    }
}
#endif

