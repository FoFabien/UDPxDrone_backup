

#include <16F877a.h>
#device ICD=TRUE
#include <string.h>
#fuses HS,NOLVP,NOWDT,PUT
#include <1152_serie_recev3.h>
#use delay(clock=20000000)

#define LED_VERTE PIN_A5
#define LED_JAUNE PIN_B4
#define LED_ROUGE PIN_B5




#use rs232 (baud = 2000 ,rcv = PIN_B0,bits =8,parity=N,stream=inproto)




#use rs232 (baud = 57600 ,xmit = PIN_C6,parity=N,bits=8,stream=outpc)

//2 flux différents
main()
{
unsigned int acctabu[2],acctabv[2],acctabw[2],essai[2] ;
signed long memoacu,memoacv,memoacw;
char stringz[7]="Z+000D";
char stringy[7]="Y+000D";
char stringx[7]="X+000D";
char stringu[7]="U+000D";
char stringv[7]="V+000D";
char stringw[7]="W+000D";
char chaine[37] = "\0";
/*char *stringu2;
char *stringv2;
char *stringw2;*/

int i=0;
essai[0] = 0xFE;//pour valider le fonctionnement
essai[1] = 0x3F;
output_low(LED_VERTE);
memoacu =0;memoacv =0;memoacw =0;
while(true)
{
//delay_ms(40);
output_low(LED_VERTE);


while(pin_d7==1);
while(fgetc(inproto)!='x');//lecture de la liaison HF x pour l'angle


for(i=1;i<5;i++)
stringz[i] =fgetc(inproto);
for(i=1;i<5;i++)
stringy[i] =fgetc(inproto);
for(i=1;i<5;i++)
stringx[i] =fgetc(inproto);

while(pin_d7==1);
while(fgetc(inproto)!='a');//a comme début accélérations

for(i=0;i<2;i++)
acctabv[i] = fgetc(inproto);//accz
for(i=0;i<2;i++)
acctabw[i] = fgetc(inproto);//accx
for(i=0;i<2;i++)
acctabu[i] = fgetc(inproto);//accy

memoacw = transcode(acctabw);
memoacu = transcode(acctabu);
memoacv = transcode(acctabv);

if(memoacw <= -20) //accélération = force inverse sur le capteur
memoacw= +255;
else
if (memoacw >= +20)
memoacw = -255;
else
memoacw = 0;//ok

if(memoacu <= -10) //accélération = force inverse sur le capteur
memoacu= +255;
else
if (memoacu >= +10)
memoacu = -255;
else
memoacu = 0;//ok

memoacv += 43;//offset sur l'axe Z
if(memoacv <= -10) //accélération = force inverse sur le capteur
memoacv= +255;
else
if (memoacv >= +10)
memoacv = -255;
else
memoacv = 0;

/*fprintf(outpc,stringx);
fprintf(outpc,stringy);
fprintf(outpc,stringz);//Ces trames sont déjà en ASCII



for(i=0;i<10;i++)   // celles-ci doivent être transformées
fprintf(outpc,(itoasigne ((memoacw ),'V')));//ok  axe x capteur
//utilisation de 2 fonctions en cascade
for(i=0;i<10;i++)
fprintf(outpc,(itoasigne ((memoacu ),'U')));//ok  axe y capteur

for(i=0;i<10;i++)
fprintf(outpc,(itoasigne ((memoacv ),'W')));//ok axe z capteur*/

chaine[0] = '\0';
strcat(chaine, stringx);
strcat(chaine, stringy);
strcat(chaine, stringz);

strcat(chaine, (itoasigne ((memoacu ),'U')));
strcat(chaine, (itoasigne ((memoacv ),'V')));
strcat(chaine, (itoasigne ((memoacw ),'W')));

fprintf(outpc, chaine);


output_high(LED_VERTE);
            }
}




