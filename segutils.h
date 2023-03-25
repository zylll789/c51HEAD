#include <REGX52.H>

#ifndef _num_to_hex
#define _num_to_hex

    #define ZERO  0xc0//0
    #define ONE   0xf9//1
    #define TWO   0xa4//2
    #define THREE 0xb0//3
    #define FOUR  0x99//4
    #define FIVE  0x92//5
    #define SIX   0x82//6
    #define SEVEN 0xf8//7
    #define EIGHT 0x80//8
    #define NINE  0x90//9

    #define ZERO_DOT  0x40//0.
    #define ONE_DOT   0x79//1.
    #define TWO_DOT   0x24//2.
    #define THREE_DOT 0x30//3.
    #define FOUR_DOT  0x19//4.
    #define FIVE_DOT  0x12//5.
    #define SIX_DOT   0x02//6.
    #define SEVEN_DOT 0x78//7.
    #define EIGHT_DOT 0x00//8.
    #define NINE_DOT  0x10//9.

#endif

//num ^ a
int pow(int num, int a){
	int i = 0;
	int ans = 1;
	for(i; i < a; i++){
		ans *= num;
	}
	return ans;
}

//t ms
void delay(unsigned int t){
    int i,j;
    for (i = 0; i < 120; i++){
        for (j = 0; j < t; j++);
    }
}

//num -> defined num like ONE TWO or ONE_DOT for example,0 <= num <= 9
//pos -> the position where light lit,0~7 -> 10^pos 
void showNum(unsigned int num, unsigned int pos){
    P0 = num;
    P1 = 0xff - pow(2, pos);
}

void clearNum(){
	P0 = 0xff;
	P1 = 0xff;
}