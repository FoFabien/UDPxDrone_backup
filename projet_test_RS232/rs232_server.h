#include <18F6722.h>
#device adc=8

#FUSES NOWDT                 	//No Watch Dog Timer
#FUSES WDT128                	//Watch Dog Timer uses 1:128 Postscale
#FUSES LP                    	//Low power osc < 200 khz
#FUSES NOPROTECT             	//Code not protected from reading
#FUSES IESO                  	//Internal External Switch Over mode enabled
#FUSES BROWNOUT              	//Reset when brownout detected
#FUSES BORV25                	//Brownout reset at 2.5V
#FUSES NOPUT                 	//No Power Up Timer
#FUSES NOCPD                 	//No EE protection
#FUSES STVREN                	//Stack full/underflow will cause reset
#FUSES NODEBUG               	//No Debug mode for ICD
#FUSES LVP                   	//Low Voltage Programming on B3(PIC16) or B5(PIC18)
#FUSES NOWRT                 	//Program memory not write protected
#FUSES NOCPB                 	//No Boot Block code protection
#FUSES NOEBTRB               	//Boot block not protected from table reads
#FUSES NOEBTR                	//Memory not protected from table reads
#FUSES NOWRTD                	//Data EEPROM not write protected
#FUSES NOWRTC                	//configuration not registers write protected
#FUSES NOWRTB                	//Boot block not write protected
#FUSES FCMEN                 	//Fail-safe clock monitor enabled
#FUSES LPT1OSC               	//Timer1 configured for low-power operation
#FUSES MCLR                  	//Master Clear pin enabled
#FUSES NOXINST               	//Extended set extension and Indexed Addressing mode disabled (Legacy mode)
#FUSES BBSIZ1K               	//1K words Boot Block size

#use delay(clock=20000000)
#use rs232(baud=9600,parity=N,xmit=PIN_C6,rcv=PIN_C7,bits=8)

