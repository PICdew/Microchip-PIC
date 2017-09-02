// Date created 13 March 2015

#include<p18f4520.h>
#pragma config OSC=HS
#pragma config PWRT=OFF
#pragma config WDT=OFF
#pragma config DEBUG=OFF, LVP=OFF 
#pragma config FCMEN=ON
#pragma config XINST=OFF

void msdelay(unsigned int itime);

#define O PORTCbits.RC0
#define X PORTCbits.RC1
#define Y PORTCbits.RC2
#define Z PORTCbits.RC3 // define PORTC for inputs
#define A PORTCbits.RC4
#define B PORTCbits.RC5
#define C PORTCbits.RC6
#define D PORTCbits.RC7

#define ERR PORTDbits.RD0
#define END_WRK PORTDbits.RD1
#define WAIT PORTDbits.RD2
#define CLR PORTDbits.RD3 // define PORTD for inputs
#define GO PORTDbits.RD4
#define RGR PORTDbits.RD5
#define TST PORTDbits.RD6
#define UNDRSTOOD PORTDbits.RD7

#define LED PORTBbits.RB7 // define RB7 for output

void main(void)
{
 TRISCbits.TRISC0=1;
 TRISCbits.TRISC1=1;
 TRISCbits.TRISC2=1;
 TRISCbits.TRISC3=1; //make PORTC input pins
 TRISCbits.TRISC4=1;
 TRISCbits.TRISC5=1;
 TRISCbits.TRISC6=1;
 TRISCbits.TRISC7=1;
 
 TRISDbits.TRISD0=1;
 TRISDbits.TRISD1=1;
 TRISDbits.TRISD2=1;
 TRISDbits.TRISD3=1; //make PORTD input pins
 TRISDbits.TRISD4=1;
 TRISDbits.TRISD5=1;
 TRISDbits.TRISD6=1;
 TRISDbits.TRISD7=1;

 TRISBbits.TRISB7=0; //make RB7 output pin
 
 while(1)
  {
   if(O==1){msdelay(250);LED=1;LED=1;msdelay(250);LED=1;LED=1;msdelay(250);LED=1;LED=1;msdelay(250);LED=1;LED=1;msdelay(250);LED=1;LED=1;msdelay(250);} //0
   if(X==1){msdelay(250);LED=1;msdelay(250);LED=1;LED=1;msdelay(250);LED=1;LED=1;msdelay(250);LED=1;LED=1;msdelay(250);LED=1;LED=1;msdelay(250);} //1
   if(Y==1){msdelay(250);LED=1;msdelay(250);LED=1;msdelay(250);LED=1;LED=1;msdelay(250);LED=1;LED=1;msdelay(250);LED=1;LED=1;msdelay(250);} //2
   if(Z==1){msdelay(250);LED=1;msdelay(250);LED=1;msdelay(250);LED=1;msdelay(250);LED=1;LED=1;msdelay(250);LED=1;LED=1;msdelay(250);} //3
   if(A==1){msdelay(250);LED=1;msdelay(250);LED=1;LED=1;msdelay(250);} //A
   if(B==1){msdelay(250);LED=1;LED=1;msdelay(250);LED=1;msdelay(250);LED=1;msdelay(250);LED=1;msdelay(250);} //B
   if(C==1){msdelay(250);LED=1;LED=1;msdelay(250);LED=1;msdelay(250);LED=1;LED=1;msdelay(250);LED=1;msdelay(250);} //C
   if(D==1){msdelay(250);LED=1;LED=1;msdelay(250);LED=1;msdelay(250);LED=1;msdelay(250);} //D

   if(ERR==1){msdelay(250);LED=1;msdelay(250);LED=1;msdelay(250);LED=1;msdelay(250);LED=1;msdelay(250);LED=1;msdelay(250);LED=1;msdelay(250);LED=1;msdelay(250);LED=1;msdelay(250);} //ERROR
   if(END_WRK==1){msdelay(250);LED=1;msdelay(250);LED=1;msdelay(250);LED=1;msdelay(250);LED=1;LED=1;msdelay(250);LED=1;msdelay(250);LED=1;LED=1;msdelay(250);} //END WORK
   if(WAIT==1){msdelay(250);LED=1;msdelay(250);LED=1;LED=1;msdelay(250);LED=1;msdelay(250);LED=1;msdelay(250);LED=1;msdelay(250);} //WAIT
   if(CLR==1){msdelay(250);LED=1;msdelay(250);LED=1;msdelay(250);LED=1;msdelay(250);LED=1;msdelay(250);LED=1;msdelay(250);LED=1;msdelay(250);} //CLEAR
   if(GO==1){msdelay(250);LED=1;LED=1;msdelay(250);LED=1;msdelay(250);LED=1;LED=1;msdelay(250);} //GO
   if(RGR==1){msdelay(250);LED=1;msdelay(250);LED=1;LED=1;msdelay(250);LED=1;msdelay(250);} //ROGER
   if(TST==1){msdelay(250);LED=1;msdelay(250);LED=1;msdelay(250);LED=1;msdelay(250);LED=1;LED=1;msdelay(250);} //TEST
   if(UNDRSTOOD==1){msdelay(250);LED=1;msdelay(250);LED=1;msdelay(250);LED=1;msdelay(250);LED=1;LED=1;msdelay(250);LED=1;msdelay(250);} //UNDERSTOOD
  }
}
 void msdelay (unsigned int itime)
{
int i,j;
for(i=0;i<itime;i++)
for(j=0;j<1275;j++);

}