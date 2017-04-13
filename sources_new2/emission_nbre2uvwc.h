#use rs232 (baud =2000 , xmit = PIN_C5, bits=8,parity=n  )

void emattent()
{
printf("%c",'a');
}

void initem()
{

printf("%s","x+000+000+000a000000");
printf("%s","x+000+000+000a000000");
printf("%s","x+000+000+000a000000");

}



void emission2(char sign1,char sign2,char sign3,int ax1,int ax2,int ax3)
//passage des signes et des nombres par paramètres
{
int c,d,u ;
char trans[10]={'0','1','2','3','4','5','6','7','8','9'};
 //tableau de transcodage décimal ASCII pour rmplacer la fonction ITOA en C
char tab[12];


c=floor(ax1/100);
d=floor((ax1-c*100)/10);
u=ax1-(c*100+d*10);

 tab[0]=sign1;
 tab[1]=trans[c];
 tab[2]=trans[d];
 tab[3]=trans[u];

 c=floor(ax2/100);
d=floor((ax2-c*100)/10);
u=ax2-(c*100+d*10);

 tab[4]=sign2;
 tab[5]=trans[c];
 tab[6]=trans[d];
 tab[7]=trans[u];

 c=floor(ax3/100);
d=floor((ax3-c*100)/10);
u=ax3-(c*100+d*10);
 tab[8]=sign3;
 tab[9]=trans[c];
 tab[10]=trans[d];
 tab[11]=trans[u];



printf("%c",'x');    //indicateur de début de trame position angulaire
printf("%s",tab);   //envoi de la trame complète

      }

void pracc(unsigned int xacc)

{

unsigned int* varacc;
//int tab[2]={254,63}; //pour faire des essais

varacc=simplregadis(xacc);  //pas de traitement réduction du programme émission

putc(varacc[0]);
putc(varacc[1]);

//putc(tab[0]);     //pour faire des essais
//putc(tab[1]);
//putc(0);
//putc(0);
//printf("%d",varacc[0]);
//printf("%d",varacc[1]);


}
