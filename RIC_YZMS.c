#include "HardwareInfo.c"
#include "JMLib.c"
u16 tempCS=0;
u16 G1,G2,G3,G4,G5;

// define global var
unsigned int S1 = 0;
unsigned int S2 = 0;
unsigned int S3 = 0;
unsigned int S4 = 0;
unsigned int S5 = 0;
unsigned int g_0 = 0;
unsigned int g_temp = 0;
double line_proportion = 0.2;   //巡线抖动
long T15 = 0;   //光电15路口判断
long light_ws = 0;   //走圆弧参数，顺时针将变量设置成5，逆时针设置成1
int mode = 1;
int sp = 40;
int angle = 1;
long g_1 = 0;
long g_2 = 0;
long g_3 = 0;
long g_4 = 0;
long g_5 = 0;
int g_Cam_Cnt = 0;   //记录车子识别物品时后退次数
unsigned long T1 = 0;
unsigned long T2 = 0;
unsigned long T4 = 0;
unsigned long T5 = 0;
unsigned char flag = 0;

int main(void)
{
    E6RCU_Init();
    long rl = 0;
    long var1 = 0;
    long var2 = 0;
    int com = 0;
    int tem_bmp = 0;
    int seachline_tem = 0;
    int bluth_time = 0;
    unsigned char var0 = 0;
    int img_time = 0;
    while(1);
}

