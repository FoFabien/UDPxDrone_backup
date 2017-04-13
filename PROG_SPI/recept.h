#use rs232(baud=57600,xmit=PIN_C6,rcv=PIN_C7,bits=8,parity=N,stream=PROTO)

char recept()
{
char c = NULL; //chainers[36] = " ";
//int x = 0;
//char c;

/*for (x = 0; x<36; x++)
{
chainers[x] = fgetc();
delay_us(104);
}*/
c = fgetc(PROTO);

//#use rs232(baud=9600,xmit=PIN_C6,rcv=PIN_C7,bits=8,parity=N)

return c;
}

