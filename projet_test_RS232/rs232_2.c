#if defined(__PCM__)
#include <16F877A.h>
#device ICD=TRUE
#fuses HS,NOWDT,NOPROTECT
#use delay(clock=20000000)
#use rs232(baud=9600,xmit=pin_c6,rcv=pin_c7,bits=8,parity=N)
#endif

   int X = 0, Y = 0, Z = 0, U = 0, V = 0, W = 0;

main(){

set_tris_c(0b10011000);
while(true)
{
   //putc(format);
   printf("X+%dDY+%dDZ+%dDU+%dDV+%dDW+%dD",X,Y,Z,U,V,W);

                  X++;
                  if(X == 255)
                     X = 0;

                  Y++;
                  if(Y == 255)
                     Y = 0;

                  Z++;
                  if(Z == 255)
                     Z =0;

                  U++;
                  if(U == 255)
                     U = 0;

                  V++;
                  if(V == 255)
                     V = 0;

                  W++;
                  if(W == 255)
                     W =0;

                 output_low(pin_b5);
}
}
