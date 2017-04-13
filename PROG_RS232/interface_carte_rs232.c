/*#if defined(__PCM__)
#include <16F877A.h>
#device ICD=TRUE
#fuses HS,NOWDT,NOPROTECT
#use delay(clock=20000000)

#define LED_ROUGE pin_b5

#use rs232(baud=9600,rcv=pin_c7,bits=8,parity=N, stream=inproto)
#use rs232(baud=9600,xmit=pin_b7,bits=8,parity=N, stream=outproto)
#endif*/
#include "RS232.h"
#use rs232(baud=57600,xmit=pin_d7,bits=8,parity=N, stream=outproto)
#define LED_ROUGE pin_b5

main()
{
   char chara;
   char chaine[44] = "X+000DY+000DZ+000DU+000DV+000DW+000DB+000D";
   int a = 0;

   output_low(LED_ROUGE);
   delay_ms(500);
   while(true)
   {
      //fprintf(outproto, fgetc(inproto));
      output_high(LED_ROUGE);
      do
      {
      //chara = fgetc(inproto);
      chaine[0] = recev();//fgetc(inproto);

      }while(chaine[0] != 'X');

      output_low(LED_ROUGE);
      //fprintf(outproto, chara);

      for(a = 1; a < 42; a++)
      {
         //chara = fgetc(inproto);
         //fprintf(outproto, chara);
         chaine[a] = recev();//fgetc(inproto);
      }

      for(a = 0; a < 42; a++)
      {
      fputc(chaine[a], outproto);
      }
   }
}
