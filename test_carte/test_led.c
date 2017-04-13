 #if defined(__PCH__)
 #include <18F4620.h>
 #use delay(clock=20000000)
 #fuses H4, NOWDT, NOLVP, NODEBUG
 #use rs232(baud=9600,rcv=PIN_A0,bits=8,parity=N)
 #define LED1 PIN_E1
 #define LED2 PIN_E2
 #endif

 void main(void)
{
   while(true)
   {
      output_low(LED1);
      output_low(LED2);
      delay_ms(500);
      output_high(LED1);
      output_high(LED2);
      delay_ms(500);
   }
}
      
