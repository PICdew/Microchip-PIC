// Date created 19 june 2015

#define switch1 PORTA.F0        //RA0 is our input pin for project
#define switch2 PORTA.F1        //RA1 is our input pin for project

void main()
{
 TRISB=0xc0;                           // set RB0 and RB1 as input
 TRISD=0x00;                           // set port D is output
while(1)
  {

   {
   if(switch1=1){PORTD=0xf0;break;}
   if(switch2=1){PORTD=0x0f;break;}
   }


  }
}