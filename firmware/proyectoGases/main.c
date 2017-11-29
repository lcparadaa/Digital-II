/**
 * 
 */

#include "soc-hw.h"


void main()
{

	// uint8_t divisor;
	uint8_t msb;
	uint8_t lsb;
	
	
	spi_init();
	while (1) {

		
		spi_putchar(0xc0);

		msleep(2000);

		
	
		uart_putchar(0x01);
		uart_putchar(0x01);
	//	if(vg=0){
		
			//Cuando el nivel de voltaje es 0
	//	}

	//	else{

		//	uart2_putstr(vg);
			//Cuando se tiene valores en el registro		
		
	
	//	}   		
		
		}


}

//uart_putstr("Echo...\n");
//	while (1) {
//	   uart_putchar(uart_getchar());
//	}

//spi_putchar('1');
//		uart_putchar(spi_getchar()); 

//uart_putstr("+++");
//		uart_putstr("AT+CWMODE=2");
//		uart_putstr("AT+CWSAP="esp","0000",5,0");
//
//		uart1_putstr("+++");
//		uart1_putstr("AT+BAUD4");
//		uart1_putstr("AT+NAMEhq");
//		uart1_putstr("AT+PIN0000");




