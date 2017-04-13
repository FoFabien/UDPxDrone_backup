#if defined(__PCM__)
#include <16F877A.h>
#device ICD=TRUE
#fuses HS,NOWDT,NOPROTECT
#use delay(clock=20000000)
#use rs232(baud=9600,xmit=pin_b7,bits=8,parity=N)
#endif


main(){
   int X = 0;

set_tris_c(0b10011000);


      while(true)
      {
      output_high(pin_b7);

                 if(X == 1)
                 {
                 output_low(pin_b5);
                 //output_high(pin_b7);
                 delay_ms(5000);
                 X--;
                 }
                 else
                 {
                 output_high(pin_b5);
                 //output_low(pin_b7);
                 delay_ms(5000);
                 X++;
                 }

      }
}


