/*
 * led_strip.c
 *
 * Created: 2018-04-07 18:51:12
 * Author : krist
 */ 
#define F_CPU 8000000
#include <avr/io.h>
#include <util/delay.h>
#define CHECK_BIT(var,pos) ((var) & (1<<(pos)))


void delayyyy() {
	asm volatile (
	"    lpm"	"\n"
	);
}

typedef	struct _led {
		uint8_t bits[3];
		uint8_t what_bit[3];
		uint8_t fade_up[3];
	} leds;


void fadeup(uint8_t *bit) {
	bit++;
}
void fadedown(uint8_t *bit) {
	bit--;
}


leds ledstrip[] = {
	{{0,255,0},{0,5,7},{1,0,0}},
	{{0,0,255},{0,5,7},{1,0,0}},
	{{255,0,0},{0,5,7},{1,0,0}}
};



int main(void)
{
	
	DDRB |= (1<<PB0);
	int colorswap=1;
	while(1) {
			
			
			if(ledstrip[0].what_bit[0] < 7) {
				fadeup(&ledstrip[0].what_bit[0]);
				
			} else {
				ledstrip[0].bits[0]=255;
			}
			
			
	/*
			if(fadeup[colorswap]) 
			{
				bits[colorswap] &= ~(1<<what_bit[colorswap]);
				what_bit[colorswap]++;
			} 
			else 
			{
				bits[colorswap] |= (1<<what_bit[colorswap]);
				what_bit[colorswap]--;	
			}
		
			if(what_bit[colorswap] == 7) {
				fadeup[colorswap] = 0;
			}
			else if(!what_bit[colorswap]) {
				fadeup[colorswap] = 1;
			}
				
		
			colorswap = ((colorswap + 1) %3);
		*/
		
		
		
		
			for (int ixx=0;ixx<3;ixx++) 
			{	
			
				for (int i=0;i<3;i++) 
				{
				
					for (int pos = 0 ; pos != 8 ; pos++) 
					{
					
						//if (bits[i] & (1 << pos)) 
						if(CHECK_BIT(ledstrip[ixx].bits[i],pos))
						{
							PORTB |= (1<<PB0);
							asm volatile ("nop"	"\n");
							asm volatile ("nop"	"\n");
							PORTB &= ~(1<<PB0);
							asm volatile ("nop"	"\n");
						} 
						
						else 
						{
							PORTB |= (1<<PB0);
							asm volatile ("nop"	"\n");
							PORTB &= ~(1<<PB0);
							asm volatile ("nop"	"\n");
							asm volatile ("nop"	"\n");
						}
					}		
				}
			}
		_delay_ms(100);
	}
}