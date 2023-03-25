#include <REGX52.H>

#ifndef _KEY_NUM
#define _KEY_NUM
    #define K1  1
    #define K2  2
    #define K3  3
    #define K4  4
    #define K11 11
    #define K12 12
    #define K13 13
    #define K14 14
    #define K21 21
    #define K22 22
    #define K23 23
    #define K24 24
    #define K31 31
    #define K32 32
    #define K33 33
    #define K34 34
    #define K41 41
    #define K42 42
    #define K43 43
    #define K44 44 
#endif

//get the key you pressed
char checkKeyDown(){
    P2_4 = P2_5 = P2_6 = P2_7 = 1;
    if(P2_0 == 0) return K4;
    if(P2_1 == 0) return K3;
    if(P2_2 == 0) return K2;
    if(P2_3 == 0) return K1;
    P2_4 = 0;
    if(P2_0 == 0) return K44;
    if(P2_1 == 0) return K43;
    if(P2_2 == 0) return K42;
    if(P2_3 == 0) return K41;
    P2_4 = 1;
    P2_5 = 0;
    if(P2_0 == 0) return K34;
    if(P2_1 == 0) return K33;
    if(P2_2 == 0) return K32;
    if(P2_3 == 0) return K31;
    P2_5 = 1;
    P2_6 = 0;
    if(P2_0 == 0) return K24;
    if(P2_1 == 0) return K23;
    if(P2_2 == 0) return K22;
    if(P2_3 == 0) return K21;
    P2_6 = 1;
    P2_7 = 0;
    if(P2_0 == 0) return K14;
    if(P2_1 == 0) return K13;
    if(P2_2 == 0) return K12;
    if(P2_3 == 0) return K11;
    P2_7 = 1;
    return 0;
}