#include <18F4620.h>
#device adc=8

#FUSES NOWDT                    //No Watch Dog Timer
#FUSES WDT128                   //Watch Dog Timer uses 1:128 Postscale

#FUSES NOPROTECT                //Code not protected from reading
//#FUSES IESO                     //Internal External Switch Over mode enabled
//#FUSES BROWNOUT                 //Reset when brownout detected
//#FUSES BORV21                   //Brownout reset at 2.1V
#FUSES NOPUT                    //No Power Up Timer
#FUSES NOCPD                    //No EE protection
#FUSES STVREN                   //Stack full/underflow will cause reset
#FUSES NODEBUG                  //No Debug mode for ICD

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
#FUSES MCLR                     //Master Clear pin enabled


#use delay(clock=20000000)
#use rs232 (baud = 19200 , xmit = PIN_C6 , rcv = PIN_C7)

void spi(int x);

void main()
{
   int a = 0;

   /*setup_adc_ports(NO_ANALOGS|VSS_VDD);
   setup_adc(ADC_OFF|ADC_TAD_MUL_0);
   setup_psp(PSP_DISABLED);
   setup_spi(FALSE);
   setup_wdt(WDT_OFF);
   setup_timer_0(RTCC_INTERNAL);
   setup_timer_1(T1_DISABLED);
   setup_timer_2(T2_DISABLED,0,1);
   setup_comparator(NC_NC_NC_NC);
   setup_vref(FALSE);
   setup_oscillator(False);*/

   output_low(PIN_B5);
   delay_ms(5);



   output_low(PIN_E2);
   output_high(PIN_B5);
   // TODO: USER CODE!!
   while(true)
   {
   spi(0x01);
   a++;
   if (a >= 255)
   a = 0;
   }

}


void spi(int x)
{
int i;
int adres[1];
int buffer[1];

adres[0]=x;

output_low(PIN_B4);//CS_L (CS A L'ETAT BAS, DEBUT) --------------------------------------------------------------------------------------------
delay_us(2);

for(i=0; i<8; ++i)
{
      output_low(PIN_C3);//SCLK_L
      delay_us(5);
      output_bit(PIN_C5,shift_left(&adres[0],1,1));//DIN_ADIS
      delay_us(5);
      //shift_left(buffer,1,input(PIN_C4));//DOUT_ADIS
      //delay_us(1);
      output_high(PIN_C3);//SCLK_H
      delay_us(5);
}
  for(i=0; i<8; ++i)
{
      output_low(PIN_C3);//SCLK_L
      delay_us(5);
      //output_bit(PIN_C5,shift_left(&adres[0],1,1));//DIN_ADIS
      //delay_us(1);
      shift_left(buffer,1,input(PIN_C4));//DOUT_ADIS
      delay_us(5);
      output_high(PIN_C3);//SCLK_H
      delay_us(5);
  }
delay_us(5);
output_high(PIN_B4);//CS_H (CS A L'ETAT HAUT, FIN) --------------------------------------------------------------------------------------------
delay_us(5);

}
