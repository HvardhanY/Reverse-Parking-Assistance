#include <LPC21xx.H>

#include "header.h"

CAN1 m2;
extern int f;
void eint_handler(void)__irq{
        if(f==1){
			m2.id= 0x123;
			m2.rtr=1;
			m2.dlc=4;
			can1_tx(m2);
			f=0;
        }
        else {
				m2.id= 0x123;
				m2.rtr=1;
				m2.dlc=4;
				can1_tx(m2);
                f=1;

        }

                VICVectAddr=0;
                EXTINT=1;
}

void config_vic(void){
			VICIntSelect=0;
			VICVectCntl0=14|1<<5;
			VICVectAddr0=(unsigned int)eint_handler;
			VICIntEnable|=1<<14;

}
void enEintInterrupt(void){
                PINSEL1|=0<<1|1<<0;
                EXTMODE=1;
                EXTPOLAR=1;
}

