/*----------------------------------------------------------------------------
 * Author : Eshwar Jorvekar
 * Date created 11 March, 2015
 * Note(s): target PIC16F73
			compiler: MikroC
 *----------------------------------------------------------------------------*/

#define AOUT_FREQ 750
#define DOT_LEN 50
#define DOT_SPACE 250
#define BAR_LEN 250
#define BAR_SPACE 50
#define DEFAULT_SPACE 300

int kp ;

void _dot() {
  PORTB.F1 = 1;  
  Sound_Play(AOUT_FREQ,DOT_LEN);
  PORTB.F1 = 0;
  Delay_ms(DOT_SPACE);
}

void _bar() {
  PORTB.F1 = 1;
  Sound_Play(AOUT_FREQ,BAR_LEN);
  PORTB.F1 = 0;
  Delay_ms(BAR_SPACE);
}

void main() 
{
  ADCON1 = 0x6;
  ADCON0 = 0x0;
  INTCON = 0x0;
  TRISB = 0x0;   //PORTB : output port
  PORTB = 0x0;   //0 - speaker, 1 - sign LED, 2 - busy LED
  
  PORTB.F2 = 1;     //BUSY LED
  Keypad_Init(&PORTC);     //Initialize keypad on port C
  Sound_Init(&PORTB , 0);  //Initialize sound on port B
  PORTB.F0 = 1;           //to BUZZER
  Delay_ms(300);
  PORTB.F0 = 0;   //initial state to BUZZER pin
 
  while(1)
   {
   kp=0;
    kp = Keypad_Released();
	switch(kp)
		{	 
                 case 1 : _dot(); _bar(); break;                         // A
                 case 2 : _bar(); _dot(); _dot(); _dot(); break;         // B
                 case 3 : _bar(); _dot(); _bar(); _dot(); break;         // C
                 case 4 : _bar(); _dot(); _dot(); break;                 // D
                 case 5 : _dot(); break;                                 // E
                 case 6 : _dot(); _dot(); _bar(); _dot(); break;         // F
                 case 7 : _bar(); _bar(); _dot(); break;                 // G
                 case 8 : _dot(); _dot(); _dot(); _dot(); break;         // H
                 case 9 : _bar(); _bar(); _bar(); _bar(); _bar(); break; // 0
                 case 10 : _dot(); _bar(); _bar(); _bar(); _bar(); break; // 1
                 case 11 : _dot(); _dot(); _bar(); _bar(); _bar(); break; // 2
                 case 12 : _dot(); _dot(); _dot(); _bar(); _bar(); break; // 3
                 case 13 : _dot(); _dot(); _dot(); _dot(); _bar(); break; // 4
                 case 14 : _dot(); _dot(); _dot(); _dot(); _dot(); break; // 5
                 case 15 : _bar(); _dot(); _dot(); _dot(); _dot(); break; // 6
                 case 16 : _bar(); _bar(); _dot(); _dot(); _dot(); break; // 7                 
		}
   }
      
}