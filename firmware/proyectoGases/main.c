/**
 * 
 */

#include "soc-hw.h"


void main()
{

	// uint8_t divisor;
	//uint8_t msb;
	//uint8_t lsb;
	
	
	//gpio_init();
	while (1) {

		
	spi_putchar(0xc0);

	msleep(2000);
// sck
	gpio_write(1,0);
	nsleep(100);
	gpio_write(1,1);//1er ciclo
	nsleep(100);
	gpio_write(1,0);
	nsleep(100);
	gpio_write(1,1);//2do ciclo
	nsleep(100);
	gpio_write(1,0);
	nsleep(100);
	gpio_write(1,1);//3er ciclo
	nsleep(100);
	gpio_write(1,0);
	nsleep(100);
	gpio_write(1,1);//4to ciclo
	nsleep(100);
	gpio_write(1,0);
	nsleep(100);
	gpio_write(1,1);//5to ciclo
	nsleep(100);
	gpio_write(1,0);
	nsleep(100);
	gpio_write(1,1);//6to ciclo
	nsleep(100);
	gpio_write(1,0);
	nsleep(100);
	gpio_write(1,1);//7to ciclo
	nsleep(100);
	gpio_write(1,0);

//mosi
	gpio_write(2,1);
	nsleep(400);

		
	
	//uart_putchar(0x01);
	//uart_putchar(0x01);
	//if(vg=0){
		
	//Cuando el nivel de voltaje es 0
	//}
	//else{
	//uart2_putstr(vg);
	//Cuando se tiene valores en el registro		
	//}   		
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




