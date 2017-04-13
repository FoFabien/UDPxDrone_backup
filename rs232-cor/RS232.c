//#include "G:\Simon_Forest_Projet\RS232.h"
#include "RS232.h"
unsigned int rec;
void main()
{

   setup_adc_ports(NO_ANALOGS|VSS_VDD);
   setup_adc(ADC_OFF|ADC_TAD_MUL_0);
   setup_psp(PSP_DISABLED);
  // setup_spi(FALSE);
   setup_wdt(WDT_OFF);
  // setup_timer_0(RTCC_INTERNAL);
   setup_timer_1(T1_DISABLED);
   setup_timer_2(T2_DISABLED,0,1);
   setup_comparator(NC_NC_NC_NC);
   setup_vref(FALSE);
  // setup_low_volt_detect(FALSE);
  // setup_oscillator(False);

while(1)
{

 rec=recev();
 affelcd(0,0,rec);
 delay_ms(100);

}



}
