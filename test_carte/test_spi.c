#define STACK_USE_ICMP  1
#define STACK_USE_ARP   1
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
   int a = 0;

   set_tris_b(0);


   init_user_io();



   UDPInit(); // INITIALISATION UDP


   IPAddrInit();
   MACAddrInit();
   MACInit();

   //lcd_init();


while(TRUE)
   {


/////////////////////////
// UDP INITIALISATION
////////////////////////

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


   UDPPut(0x01);
   UDPPut(0x02);
   UDPPut(0x03);
   UDPPut(0x04);
   UDPPut(0x05);
   UDPPut(0x06);

   UDPFlush(); // ON ENVOI
   UDPClose(tx_socket); // ON FERME LE PORT


if (a == 1)
         {
            output_low(PIN_E1);
            output_high(PIN_E2);
            a = a - 1;
         }
         else
         {
            output_low(PIN_E2);
            output_high(PIN_E1);
            a = a + 1;
         }


   }

}



