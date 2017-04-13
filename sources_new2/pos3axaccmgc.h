
#use delay(clock=20000000)


unsigned int* simplregadis(int a)  //la fonction retournera un pointeur!

{

int ad[2];

int in;
unsigned int buffer[2];
unsigned int essai[2]= {0x00,0x03};
ad[1]=a;  //'a' pointe sur le tableau

output_low(PIN_C1);//CS_L   sélection de boitier
delay_us(2);

for(in=0; in<16; ++in)
{
      //delay_us(8);
      output_low(PIN_C3);//SCLK_L  horloge SPI
      delay_us(1);
      output_bit(PIN_C0,shift_left(&ad[0],2,1));// écriture DIN_ADIS
      delay_us(1);
       shift_left(buffer,2,input(PIN_C2));// lecture DOUT_ADIS

      //delay_us(1);
      output_high(PIN_C3);//SCLK_H
      delay_us(2);
  }
delay_us(2);
output_high(PIN_C1);//CS_H   fin sélection de boitier

delay_us(20);
//return(essai);  peut être utile pour essayer la fonction
return(buffer); //pointe les 2 octets du registre du capteur
}



float acc_z(int x)

{

int* var;
float acc;


var=simplregadis(x);

var[1] = var[1] & 63; //masque les 2 premiers bits
if(var[1]>32) //donc négatif
{
var[1]=(~var[1])-192;  //complément à 2
var[0]=(~var[0])+1;
acc=-((((var[1])*256+var[0])*0.073));  //0,073 degrés par lsb
}
else
acc=((((var[1])*256+var[0])*0.073));

return(acc);
}






