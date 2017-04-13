#if defined(__PCM__)
#include <16F877A.h>
#device ICD=TRUE
#fuses HS,NOWDT,NOPROTECT
#use delay(clock=20000000)
#use rs232(baud=57600,xmit=pin_c6,rcv=pin_c7,bits=8,parity=N)
#endif

   int X = 0, Y = 0, Z = 0, U = 0, V = 0, W = 0, B = 0;

main(){
//char chaine[37] = "X+000DY+000DZ+000DU+000DV+000DW+000D";


set_tris_c(0b10011000);
/*output_high(pin_c7);
while(pin_c6==1);
{}
output_low(pin_c7);*/

while(true)
{


   printf("X+%03uDY+%03uDZ+%03uDU+%03uDV+%03uDW+%03uDB+%03uD",X,Y,Z,U,V,W,B);

   //printf("%s",chaine);


                  X++;
                  if(X == 255)
                     X = 0;

                  Y++;
                  if(Y == 255)
                     Y = 0;

                  Z++;
                  if(Z == 255)
                     Z = 0;

                  U++;
                  if(U == 255)
                     U = 0;

                  V++;
                  if(V == 255)
                     V = 0;

                  W++;
                  if(W == 255)
                     W = 0;

                  B++;
                  if(B == 255)
                     B = 0;

                 if(X > 123)
                 output_low(pin_b5);
                 else
                 output_high(pin_b5);
       }
}

