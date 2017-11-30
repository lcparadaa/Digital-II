#include "soc-hw.h"

uart_t  *uart0  = (uart_t *)   0x20000000;
timer_t *timer0 = (timer_t *)  0x30000000;
uart_t  *uart1  = (uart_t *)   0x40000000;
spi_t   *spi0    = (spi_t *)    0x50000000;
uart_t  *uart2  = (uart_t *)   0x60000000;
gpio_t  *gpio = (gpio_t *)   0x70000000;

isr_ptr_t isr_table[32];

void prueba()
{
	   uart0->rxtx=30;
	   timer0->tcr0 = 0xAA;
	   spi0->rxtx=1;
	   spi0->cs=3;
	   spi0->divisor=4;
	   uart0->rxtx=30;

           
	  
}	
void tic_isr();
/***************************************************************************
 * IRQ handling
 */
void isr_null()
{
}

void irq_handler(uint32_t pending)
{
	int i;

	for(i=0; i<32; i++) {
		if (pending & 0x01) (*isr_table[i])();
		pending >>= 1;
	}
}

void isr_init()
{
	int i;
	for(i=0; i<32; i++)
		isr_table[i] = &isr_null;
}

void isr_register(int irq, isr_ptr_t isr)
{
	isr_table[irq] = isr;
}

void isr_unregister(int irq)
{
	isr_table[irq] = &isr_null;
}

/***************************************************************************
 * TIMER Functions
 */
void msleep(uint32_t msec)
{
	uint32_t tcr;

	// Use timer0.1
	timer0->compare1 = (FCPU/1000000)*msec;
	timer0->counter1 = 0;
	timer0->tcr1 = TIMER_EN;

	do {
		//halt();
 		tcr = timer0->tcr1;
 	} while ( ! (tcr & TIMER_TRIG) );
}

void nsleep(uint32_t nsec)
{
	uint32_t tcr;

	// Use timer0.1
	timer0->compare1 = (30)*nsec;
	timer0->counter1 = 0;
	timer0->tcr1 = TIMER_EN;

	do {
		//halt();
 		tcr = timer0->tcr1;
 	} while ( ! (tcr & TIMER_TRIG) );
}


uint32_t tic_msec;

void tic_isr()
{
	tic_msec++;
	timer0->tcr0     = TIMER_EN | TIMER_AR | TIMER_IRQEN;
}

void tic_init()
{
	tic_msec = 0;

	// Setup timer0.0
	timer0->compare0 = (FCPU/10000);
	timer0->counter0 = 0;
	timer0->tcr0     = TIMER_EN | TIMER_AR | TIMER_IRQEN;

	isr_register(1, &tic_isr);
}
/***************************************************************************
 * GPIO Functions
 */

char gpio_read(char numPin){
	char value = gpio -> gpio;
	return value >>(numPin-1);
}
void gpio_write(char numPin, char value){
	V_a = gpio -> gpio;
	V_p = value<<(numPin-1);
	if (V_p)
	   gpio -> gpio = V_p | V_a;
	else 
	   V_p=  ~(1<< numPin - 1);
}

/***************************************************************************
 * UART Functions
 */
void uart_init()
{
	//uart0->ier = 0x00;  // Interrupt Enable Register
	//uart0->lcr = 0x03;  // Line Control Register:    8N1
	//uart0->mcr = 0x00;  // Modem Control Register

	// Setup Divisor register (Fclk / Baud)
	//uart0->div = (FCPU/(57600*16));
}

char uart_getchar()
{   
	while (! (uart0->ucr & UART_DR)) ;
	return uart0->rxtx;
}

void uart_putchar(char c)
{
	while (uart0->ucr & UART_BUSY) ;
	uart0->rxtx = c;
}

void uart_putstr(char *str)
{
	char *c = str;
	while(*c) {
		uart_putchar(*c);
		c++;
	}
}

/***************************************************************************
 * UART1 Functions
 */
void uart1_init()
{
	//uart0->ier = 0x00;  // Interrupt Enable Register
	//uart0->lcr = 0x03;  // Line Control Register:    8N1
	//uart0->mcr = 0x00;  // Modem Control Register

	// Setup Divisor register (Fclk / Baud)
	//uart0->div = (FCPU/(57600*16));
}

char uart1_getchar()
{   
	while (! (uart1->ucr & UART_DR)) ;
	return uart1->rxtx;
}

void uart1_putchar(char c)
{
	while (uart1->ucr & UART_BUSY) ;
	uart1->rxtx = c;
}

void uart1_putstr(char *str)
{
	char *c = str;
	while(*c) {
		uart1_putchar(*c);
		c++;
	}
}


/***************************************************************************
 * UART2 Functions
 */
void uart2_init()
{
	//uart0->ier = 0x00;  // Interrupt Enable Register
	//uart0->lcr = 0x03;  // Line Control Register:    8N1
	//uart0->mcr = 0x00;  // Modem Control Register

	// Setup Divisor register (Fclk / Baud)
	//uart0->div = (FCPU/(57600*16));
}

char uart2_getchar()
{   
	while (! (uart2->ucr & UART_DR)) ;
	return uart2->rxtx;
}

void uart2_putchar(char c)
{
	while (uart2->ucr & UART_BUSY) ;
	uart2->rxtx = c;
}

void uart2_putstr(char *str)
{
	char *c = str;
	while(*c) {
		uart2_putchar(*c);
		c++;
	}
}

/***************************************************************************
 * SPI Functions
 */

void spi_init()
{
	spi0->divisor = (1000);
}


void spi_putchar(char c)
{
	while (spi0->run & 1) ;
	spi0->rxtx = c;
}

char spi_getchar()
{   
	while (spi0->run & 1) ;
	return spi0->rxtx;
}

