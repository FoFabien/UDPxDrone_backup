#include <18F4620.h>
#device adc=8

#FUSES NOWDT                    //No Watch Dog Timer
#FUSES NOPROTECT                //Code not protected from reading
#FUSES NOCPD                    //No EE protection

#use delay(clock=20000000)
#use rs232(baud=9600,parity=N,xmit=PIN_C6,rcv=PIN_C7,bits=8)




void main()
{
   int a = 0;
   

   // TODO: USER CODE!!
   while(true)
   {
      if (a == 1)
         {
            output_low(PIN_E1);
            output_high(PIN_E2);
            a = a - 1;
         }
         else
         {
            output_low(PIN_E2);
            output_high(PIN_E1);
            a = a + 1;
         }
         delay_ms(500);
         //output_low(PIN_E1);
         //output_low(PIN_E2);
   }

}
