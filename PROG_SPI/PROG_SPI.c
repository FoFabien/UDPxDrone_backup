#define STACK_USE_ICMP  0
#define STACK_USE_ARP   0
#define STACK_USE_UDP   1


#define MAX_SOCKETS                     6
#define MAX_UDP_SOCKETS                 4

#include "ccstcpip.h"

#define UDP_SOURCE_PORT 1024
#define UDP_DESTINATION_PORT  11000
#define UDP_NUM_LISTEN_SOCKETS   2

UDP_SOCKET last_rx_socket=INVALID_UDP_SOCKET;



void main(void)
{
   static int8 tx_socket;
   int X = 0;
   char chaine[36] = "1234\0";


 output_low(PIN_E1);
 delay_ms(700);
 output_high(PIN_E1);
 delay_ms(700);


   //output_low(PIN_E2);


   set_tris_b(0);


   init_user_io();




  IPAddrInit();
   MACAddrInit();
   MACInit();
    UDPInit(); // INITIALISATION UDP

   //lcd_init();

SetCLKOUT(0x00);//valide la communication avec la pile IP (clkout=O)
output_low(PIN_E1);
SetCLKOUT(0x05);

while(TRUE)
   {


   /*SetCLKOUT(0x01);//0x01: Divide by 1 (25 MHz)
   SetCLKOUT(0x02);//0x02: Divide by 2 (12.5 MHz)
   SetCLKOUT(0x03);//0x03: Divide by 3 (8.333333 MHz)
   SetCLKOUT(0x04);//0x04: Divide by 4 (6.25 MHz, POR default)
   SetCLKOUT(0x05);//0x05: Divide by 8 (3.125 MHz)*/



    tx_socket=UDPOpen(UDP_SOURCE_PORT, &UDPSocketInfo[last_rx_socket].remoteNode, UDP_DESTINATION_PORT); // OUVERTURE DU PORT

    UDPSocketInfo[tx_socket].remoteNode.IPAddr.v[0] = 255; // BROADCAST
    UDPSocketInfo[tx_socket].remoteNode.IPAddr.v[1] = 255;
    UDPSocketInfo[tx_socket].remoteNode.IPAddr.v[2] = 255;
    UDPSocketInfo[tx_socket].remoteNode.IPAddr.v[3] = 255;

    UDPSocketInfo[tx_socket].remoteNode.MACAddr.v[0] = 0xFF; // BROADCAST
    UDPSocketInfo[tx_socket].remoteNode.MACAddr.v[1] = 0xFF;
    UDPSocketInfo[tx_socket].remoteNode.MACAddr.v[2] = 0xFF;
    UDPSocketInfo[tx_socket].remoteNode.MACAddr.v[3] = 0xFF;
    UDPSocketInfo[tx_socket].remoteNode.MACAddr.v[4] = 0xFF;
    UDPSocketInfo[tx_socket].remoteNode.MACAddr.v[5] = 0xFF;

   for (X = 0; X<4; X++) // ON PREPARE LA CHAINE
   {
   UDPPut(chaine[X]);
   }
   UDPFlush(); // ON ENVOI
   UDPClose(tx_socket); // ON FERME LE PORT
   }

}


