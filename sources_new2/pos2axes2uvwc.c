#include <16F876.h>

#device ICD=TRUE

#fuses HS,NOLVP,NOWDT,PUT

#use delay(clock=20000000)
#include <math.h>
#include "pos3axaccmgc.h" //pour la lecture SPI
#include "emission_nbre2uvwc.h" //pour la liaison HF en ASCII


 int adrz[2]; //registres capteur poids forts et poids faibles
 int adry[2];
 int adrx[2];


 float vit_angz1,vit_angz2,pos_angz,pos_angz0;char sz,sposz;int ar_pos_angz;int* accz;
  float vit_angy1,vit_angy2,pos_angy,pos_angy0;char sy,sposy;int ar_pos_angy;int* accy;
  float vit_angx1,vit_angx2,pos_angx,pos_angx0;char sx,sposx;int ar_pos_angx;int* accx;
 //Beaucoup de variables utilisées donc pas de possibilité de traiter l'accélération

unsigned int adraccelz[2];
unsigned int adraccely[2];
unsigned int adraccelx[2];
 int essai[2] = {0x0A,0x0B}; //permet de tester les fonctions

main()
{
initem(); //envoi d'une trame pour mettre le cube en position initiale

delay_us(4);
output_high(PIN_C1);//pour la liaison SPI

pos_angz=0;
pos_angy0=0;
pos_angy=0;

while(true)
{output_high(PIN_C1); //pour la liaison SPI


/*vit_angz1=0;
 vit_angz2=0;
vit_angy1=0;
 vit_angy2=0;
 vit_angx1=0;
 vit_angx2=0;*/

adrz[1]=0x09;     //registres vitesses angulaires
adrz[0]=0x08;
adry[1]=0x07;
 adry[0]=0x06;
 adrx[1]=0x05;
adrx[0]=0x04;
//adrz[0]=0x08;


adraccelx[0]=0x0A;      //registres accélérations normales
adraccelx[1]=0x0B;//accx
adraccely[0]=0x0C;
adraccely[1]=0x0D;//accy
adraccelz[0]=0x0E;
adraccelz[1]=0x0F;//accz

// le dernier registre lu était X
 vit_angz1= abs(acc_Z(adrz[1])+0.4);//x + offset capteur
 vit_angy1= abs(acc_Z(adry[1])+0.4);//z
 vit_angx1= abs(acc_Z(adrx[1])+0.4);//Y



 delay_ms(40);
 ar_pos_angz=floor(pos_angz); //valeurs arrondies pour gagner de la place en mémoire
 ar_pos_angy=floor(pos_angy);
 ar_pos_angx=floor(pos_angx);

//while((abs(ar_pos_angz)<2)&(abs(ar_pos_angy)<2)&(abs(ar_pos_angx)<2));
//pour ne pas bouger

  if (pos_angz<0)
  {ar_pos_angz=(255 - abs(ar_pos_angz));
  //pb nombres signés(mauvais choix de variables)
  sposz='-';}
  else
      sposz='+';

    if (pos_angy<0)
  {ar_pos_angy=(255 - abs(ar_pos_angy));
  sposy='-';}
  else
   sposy='+';


 if (pos_angx<0)
  {ar_pos_angx=(255 - abs(ar_pos_angx));
  sposx='-';}
  else
   sposx='+';

emission2(sposy,sposz,sposx,ar_pos_angy,ar_pos_angz,ar_pos_angx);
emattent();
simplregadis(adraccelz[1]);
pracc(adraccelx[1]);//z  envoie simple de la valeur décimale accélération
pracc(adraccely[1]);//x
pracc(adraccelz[1]);//y

/*simplregadis(adrx[1]);
pracc(adrz[1]);
//simplregadis(adrz[1]);
pracc(adry[1]);
//simplregadis(adrz[1]);
pracc(adrx[1]);*/
// pour essayer avec les vitesses angulaires

simplregadis(adrx[1]); // pour repartir de x
 vit_angz2= acc_Z(adrz[1])+0.4;//offset du 0° capteur  // x
 vit_angy2= acc_Z(adry[1])+0.4;                          //z
 vit_angx2= acc_Z(adrx[1])+0.4;                             //y


//while((abs(acc_Z(adrz[1])+1)<2.3)&(abs(acc_Z(adry[1])+1)<2.3)&(abs(acc_Z(adrx[1])+1)<2.3));
// peut être utilisé car le capteur vibre au repos avec offset = + 1




  if(vit_angz2<0)
  {
  sz='-';
 pos_angz = -(((abs(vit_angz2 )- vit_angz1)*0.07+vit_angz1*0.15)) + pos_angz0;
  }       //normalement0.05 et0.1 pour 100ms
 else
{
    sz='+';
  pos_angz = (((abs(vit_angz2 ) - vit_angz1)*0.07+vit_angz1*0.15)) + pos_angz0;
}

if(vit_angy2<0)
  {
  sy='-';
 pos_angy = -(((abs(vit_angy2 ) - vit_angy1)*0.07+vit_angy1*0.15)) + pos_angy0;
  }
 else
{
    sy='+';

  pos_angy = (((abs(vit_angy2 ) - vit_angy1)*0.07+vit_angy1*0.15)) + pos_angy0;
}

if(vit_angx2<0)
  {
  sx='-';
 pos_angx = -(((abs(vit_angx2 ) - vit_angx1)*0.07+vit_angx1*0.15)) + pos_angx0;
  }
 else
{
    sx='+';
  pos_angx = (((abs(vit_angx2 ) - vit_angx1)*0.07+vit_angx1*0.15)) + pos_angx0;
}


pos_angz0 = pos_angz;   //mémorisation de la position angulaire
pos_angy0 = pos_angy;
pos_angx0 = pos_angx;

        }
}
