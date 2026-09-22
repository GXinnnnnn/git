#ifndef _CAM_THING_
#define _CAM_THING_
#include "HardwareInfo.c"
#include <SetSysTime.h>
#include <GetSysTime.h>
#include "speed_control.c"
#include <SetWaitForTime.h>

void cam_thing(int time0, double dis_time)
{
    // extern global var
    extern int g_Cam_Cnt;

    int time_begin = 0;
    int time_now = 0;
    SetSysTime();
    time_begin = GetSysTime();
    while ( time_now-time_begin<time0 )
    {
        time_now = GetSysTime();
    }
    g_Cam_Cnt=g_Cam_Cnt+1;
    if ( g_Cam_Cnt<5 )
    {
        speed_control(-40, -40);
        SetWaitForTime(dis_time);
        speed_control(0, 0);
    }
    SetWaitForTime(1);
}
#endif

