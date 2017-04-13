#if defined(__PCM__)
#include <16F877A.h>//<18F4620.h>
#device ICD=TRUE
#fuses HS,NOWDT,NOPROTECT
//#device adc=8

/*#FUSES NOWDT                    //No Watch Dog Timer
//#FUSES WDT128                   //Watch Dog Timer uses 1:128 Postscale
#FUSES HS                       //High speed Osc (> 4mhz)
#FUSES NOPROTECT                //Code not protected from reading
#FUSES NOIESO                   //Internal External Switch Over mode disabled
#FUSES NOBROWNOUT               //No brownout reset
//#FUSES BORV21                   //Brownout reset at 2.1V
#FUSES NOPUT                    //No Power Up Timer
#FUSES NOCPD                    //No EE protection
//#FUSES STVREN                   //Stack full/underflow will cause reset
#FUSES NODEBUG                  //No Debug mode for ICD
//#FUSES LVP                      //Low Voltage Programming on B3(PIC16) or B5(PIC18)
#FUSES NOWRT                    //Program memory not write protected
#FUSES NOWRTD                   //Data EEPROM not write protected
#FUSES NOEBTR                   //Memory not protected from table reads
#FUSES NOCPB                    //No Boot Block code protection
#FUSES NOEBTRB                  //Boot block not protected from table reads
#FUSES NOWRTC                   //configuration not registers write protected
#FUSES NOWRTB                   //Boot block not write protected
#FUSES FCMEN                    //Fail-safe clock monitor enabled
#FUSES NOXINST                  //Extended set extension and Indexed Addressing mode disabled (Legacy mode)
#FUSES PBADEN                   //PORTB pins are configured as analog input channels on RESET
#FUSES LPT1OSC                  //Timer1 configured for low-power operation
#FUSES MCLR                     //Master Clear pin enabled*/

#use delay(clock=20000000)
#use rs232(baud=19200,parity=N,xmit=PIN_E0,bits=8)
#endif

//#use delay(clock=20000000)
//#use rs232 (baud = 19200 , xmit = PIN_C6)

void initelcd()
{
printf("%c",0xa0);
          delay_ms(10);

         printf("%c%c",0xa3,0xa1);
          delay_ms(20);
          printf("%c%c",0xa3,0x0C);
          delay_ms(20);
}

void affelcd(int POSx,int POSy, unsigned int carac)

   {
          printf("%c%c%c",0xa1,POSx,POSy);

          printf("%c%u%c",0xa2,carac,0);
        // delay_ms(10);
   }

void affelcdl(int POSx,int POSy, long result)

   {
          printf("%c%c%c",0xa1,POSx,POSy);
          printf("%c%ld%c",0xa2,result,0);
     }

   void affelcdf(int POSx,int POSy, float resflo)

   {
          printf("%c%c%c",0xa1,POSx,POSy);
          printf("%c%f%c",0xa2,resflo,0);
     }


   void affelcdx(int POSx,int POSy, float resx)

   {
          printf("%c%c%c",0xa1,POSx,POSy);
          printf("%c%x%c",0xa2,resx,0);
     }

     void affelcdc(int POSx,int POSy, char sign)

   {
          printf("%c%c%c",0xa1,POSx,POSy);
          printf("%c%c%c",0xa2,sign,0);
          
     }


#use rs232(baud=57600,parity=N,rcv=pin_c7,bits=8)
char recev()
{
char r;
r=fgetc();
return(r);
}


