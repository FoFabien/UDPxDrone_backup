
#define STACK_USE_ICMP  0 // ON DEFINIT CE DONT ON A BESOIN
#define STACK_USE_ARP   0
#define STACK_USE_UDP   1

#define MAX_SOCKETS                     6 // NOMBRE DE CONNEXION MAXIMUM EN SIMULTANEES
#define MAX_UDP_SOCKETS                 4 // NOMBRE DE CONNEXION UDP MAXIMUM EN SIMULTANEES

#include "ccstcpip.h" // FICHIER DE CCS MIRCOCHIPS
#include "recept.h" // CONTIENT NOTRE FONCTION DE RECUPERATION RS232


//----------------------------------------------------------------------------------------------------------------------
// Note : recept() dans "recept.h" r�cup�re un caract�re par RS232 avec fgetc et le flux qu'on a d�finit
// 	  Il retourne ensuite le caract�re
//----------------------------------------------------------------------------------------------------------------------


#define UDP_SOURCE_PORT 1024 // PORT SOURCE
#define UDP_DESTINATION_PORT  11000 // PORT DESTINATION
#define UDP_NUM_LISTEN_SOCKETS   2 // NOMBRE DE PORTs QU'ON ECOUTE AU MAXIMUM

UDP_SOCKET last_rx_socket=INVALID_UDP_SOCKET; // d�claration de last_rx_socket qui contient le dernier port ouvert




void main(void)
{
   char chaine[36] = " "; // d�claration de la chaine
   int X = 0; // d�claration de variable enti�re
   static int8 tx_socket; // d�claration d'un port



   set_tris_b(0); // on met le port B en sortie


   init_user_io(); // INITIALISATION DES ENTREES SORTIES

   UDPInit(); // INITIALISATION UDP (FONCTIONS ET AUTRES)


   IPAddrInit(); // INITIALISATION IP (ADRESSES)
   MACAddrInit(); // INITIALISATION MAC (ADRESSE)
   MACInit(); // INITIALISATION MAC (FONCTIONS ET AUTRES)


//----------------------------------------------------------------------------------------------------------------------
// DEBUT DE LA BOUCLE PRINCIPALE
//----------------------------------------------------------------------------------------------------------------------


while(TRUE)
   {


//----------------------------------------------------------------------------------------------------------------------
// RECUPERATION DE LA CHAINE PAR RS232
//----------------------------------------------------------------------------------------------------------------------

   do
   {
   chaine[0] = recept(); 	// On r�cup�re un premier caract�re
			 	// Si ce caract�re est un X alors �a signifie qu'on re�oit le premier caract�re de la chaine
   }while(chaine[0] != 'X');	// Et on sort de la boucle, sinon on continue � attendre le premier caract�re

   for (X = 1; X<36; X++)	// On r�cup�re les caract�res suivants un � un
   {
   chaine[X] = recept();
   }


//----------------------------------------------------------------------------------------------------------------------
// UDP OUVERTURE
//----------------------------------------------------------------------------------------------------------------------

    tx_socket=UDPOpen(UDP_SOURCE_PORT, &UDPSocketInfo[last_rx_socket].remoteNode, UDP_DESTINATION_PORT); // OUVERTURE DES PORTS (PORT SOURCE, DERNIER PORT OUVERT, PORT DESTINATION)

    UDPSocketInfo[tx_socket].remoteNode.IPAddr.v[0] = 255; // ADRESSE IP DE DESTINATION (BROADCAST)
    UDPSocketInfo[tx_socket].remoteNode.IPAddr.v[1] = 255;
    UDPSocketInfo[tx_socket].remoteNode.IPAddr.v[2] = 255;
    UDPSocketInfo[tx_socket].remoteNode.IPAddr.v[3] = 255;

    UDPSocketInfo[tx_socket].remoteNode.MACAddr.v[0] = 0xFF; // ADRESSE ETHERNET (BROADCAST)
    UDPSocketInfo[tx_socket].remoteNode.MACAddr.v[1] = 0xFF;
    UDPSocketInfo[tx_socket].remoteNode.MACAddr.v[2] = 0xFF;
    UDPSocketInfo[tx_socket].remoteNode.MACAddr.v[3] = 0xFF;
    UDPSocketInfo[tx_socket].remoteNode.MACAddr.v[4] = 0xFF;
    UDPSocketInfo[tx_socket].remoteNode.MACAddr.v[5] = 0xFF;

// ADRESSE IP SOURCE (DE LA CARTE) DEFINIE DANS "ccstcpip.h"

   for (X = 0; X<36; X++) // ON PREPARE LA CHAINE
   {
   UDPPut(chaine[X]); // A CHAQUE TOUR DE BOUCLE ON RAJOUTE LE CARACTERE SUIVANT DANS LES DONNEES A ENVOYEES
   }
   UDPFlush(); // ON ENVOI LE TOUT
   UDPClose(tx_socket); // ON FERME LE PORT


//----------------------------------------------------------------------------------------------------------------------
// UDP FERMETURE
//----------------------------------------------------------------------------------------------------------------------



   }

}


