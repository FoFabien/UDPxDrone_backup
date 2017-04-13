#include "C:\TS2_SE_08_09\Simon_Forest_Projet\PROG_RS232\RS232.h"

unsigned int rec;
#use rs232(baud=1200,parity=N,xmit=pin_d7,rcv=pin_c7,bits=8)
void main()
{
   int a = 0;

   /*setup_adc_ports(NO_ANALOGS|VSS_VDD);
   setup_adc(ADC_OFF|ADC_TAD_MUL_0);*/
   //setup_psp(PSP_DISABLED);
  // setup_spi(FALSE);
   //setup_wdt(WDT_OFF);
  // setup_timer_0(RTCC_INTERNAL);
  // setup_timer_1(T1_DISABLED);
  // setup_timer_2(T2_DISABLED,0,1);
  // setup_comparator(NC_NC_NC_NC);
   //setup_vref(FALSE);
  // setup_low_volt_detect(FALSE);
  // setup_oscillator(False);

while(1)
{

 putc('A');
 //rec=recev();
 //affelcd(0,0,rec);
 delay_ms(200);
 output_low(pin_b5);
 delay_ms(200);
 output_high(pin_b5);
 /*a++;
 if(a==9)
 a = 0;*/

}



}
