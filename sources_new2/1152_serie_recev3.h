#include <math.h>
#include <string.h>




char* itoasigne(signed long acc,char a)
{

char sign;
long c,d,u ;
char trans[10]={'0','1','2','3','4','5','6','7','8','9'};

char tab[7] = {0,0,0,0,0,0,0};

//int ac= 12;
//acc = ac;
//acc -= 460;

if(acc<0)
{//acc=(65535 - abs(acc));//pb nombres signés
sign='-';}
else
sign='+';

acc= abs(acc);
c=floor(acc/100);
d=floor((acc-c*100)/10);
u=acc-(c*100+d*10);

 tab[0]= a;
 tab[1] =sign;
 tab[2] +=trans[c];
 tab[3] +=trans[d];
 tab[4] +=trans[u];
 tab[5]  = 'D';
 tab[6]  ='\0';
/*tab[0]='+';
 tab[1]='1';
 tab[2]='2';
 tab[3]='3';*/

return(tab);

}




signed long transcode(unsigned int x)
{
  unsigned int* ad;   //puisqu'il s'agit d'un pointeur sur un tableau
signed long accar;
//signed long accar0;
//int buffer[2];
float accf ;

//unsigned int reg[2] ={0xFE,0x3F};  pratique pour valider le fonctionnement
ad = x;

ad[1]  &= 63;//masque les MSB (il s'agissait bien d'un tableau)
if(ad[1]>32)
{
ad[1]=(~ad[1])-192;  //complément à 2
ad[0]=(~ad[0])+1;
accf=-(((((ad[1])*256)+ad[0])/10 )); //pas de respect de l'unité ( le G)
}
else
accf=(((((ad[1])*256)+ad[0])/10 ));

accar=floor(accf);
//accar -= ;
accar -= 509;  //gros offset pour ce capteur force d'attraction terrestre?
 return (accar);

}
