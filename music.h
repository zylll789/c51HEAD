#include<segutils.h>
#include<keycontrol.h>

/*
    one example music:
    code unsigned int poem[] = {0,
    1,1,1,    1,5,1,    1,5,1,    1,6,1,    4,6,2,    0,0,6,//
    1,1,1,    1,5,1,    1,5,1,    1,6,1,    4,2,1,    1,1,1,    0,0,6,//
    1,1,1,    1,5,1,    1,5,1,    1,6,1,    4,6,2,//
    0,0,4,    1,6,1,    1,5,1,    1,6,1,    4,6,1,//
    2,2,1,    5,2,1,    2,1,1,    4,6,1,    1,5,1,    1,1,1,    0,0,6,//
    2,4,1,    5,2,1,    2,5,1,    2,4,1,    2,1,1,    5,2,1,//
    2,4,1,    5,2,1,    5,6,1,    2,4,1,    4,6,1,    5,2,1,//
    2,4,1,    5,2,1,    2,2,1,    5,1,1,    2,1,1,//
    5,2,1,    5,1,1,    2,1,1,    5,5,1//
};

    example use:
    void main(){
    P3_7 = 1;
    TMOD = 0x01;
    EA=1;
    while (1)
    {
        checkPlay(K11, poem);
    }
}
*/

unsigned int timer;
code unsigned int pinlv[6][8] = {
    {0,262,294,330,349,392,440,494},//_1,_2,_3,_4,_5,_6,_7
    {0,523,587,659,698,784,880,988},//1,2,3,4,5,6,7
    {0,1046,1175,1318,1397,1568,1760,1976},//1_,2_,3_,4_,5_,6_,7_
    {0,277,311,0,370,415,466,0},//# of _1,_2,_4,_5,_6
    {0,554,622,0,740,831,932,0},//# of 1,2,4,5,6
    {0,1109,1245,0,1480,1661,1865,0}//# of 1_,2_,4_,5_,6_
};

//length -> how many voice point you send in
//p -> the music you send in,it should be like a *p start with 0 and three num a group.
//for example,{0,  1,1,1,  2,2,2}means you put in 2 voice of mid-do for 250ms and high-re for 500ms
void play(unsigned int* p,unsigned int length){
    int i;
    for(i=0;i<length;i++){
        TR0=1;
        timer=65536-1000000/(pinlv[p[3*i+1]][p[3*i+2]]*2);
        TH0=timer/256;
        TL0=timer%256;
        delay(250*p[3*i+3]);
    }
}

void timer0() interrupt 1
{
    TH0=timer/256;
    TL0=timer%256;
    P3_7 = ~P3_7;
}

//key -> the key pressed to play music
//p -> the music you want to play
void checkPlay(int key,unsigned int *p){
    if(checkKeyDown() == key){
            delay(10);
            if(checkKeyDown() == key){
                ET0=1;
                play(p,51);
                ET0=0;
            }
        }
}