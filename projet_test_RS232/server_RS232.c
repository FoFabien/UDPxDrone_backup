#include <18F6722.h>
#use delay(clock=20000000)
#use rs232(baud=9600, xmit=PIN_C6, rcv=PIN_C7)
#fuses HS, NOWDT, NOLVP, NODEBUG
#define STACK_USE_CCS_PICNET TRUE

#define STACK_USE_MAC TRUE

#include "drivers\stacktsk.c"

void MACDisplayHeader(MAC_ADDR *mac, int8 type) {
   int8 i;
   printf("\r\nMAC: ");
   for (i=0;i<6;i++) {
      printf("%X", mac->v[i]);
      if (i!=5)
         putc(':');
   }
   printf("  PROT:0x08%X ",type);

   if (type==MAC_IP)
      printf("[IP]");
   else if (type==MAC_ARP)
      printf("[ARP]");
}

void main(void) {
   MAC_ADDR mac;
   int8 type;

   printf("\r\n\nCCS TCP/IP TUTORIAL 7A\r\n");

   MACInit();

   while(TRUE) {
      if (MACGetHeader(&mac, &type)) {
         if (type!=MAC_UNKNOWN) {
            MACDisplayHeader(&mac, type);
         }
      }
   }
}

