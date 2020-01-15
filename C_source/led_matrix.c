#include <stdio.h>
#include <wiringPi.h>
#include <wiringPiSPI.h>
#define  SPI_CHANNEL 0
#define  SPI_SPEED 1000000
#define  BRIGHT 0

void data_8x8led( unsigned char msb, int lsb, int select) {
	int i;
	unsigned char out[2] = { 0 };
	out[0] = msb;
	if(select ==2 ) {
		for( i = 0; i< 8; ++i){
			out[1] = (( lsb % 10) << 1 );
			lsb = lsb / 10;
		}
	}else {
		out[1] = lsb;
	}
	wiringPiSPIDataRW(SPI_CHANNEL, out, 2);
}


void init_8x8led_spi( void) {
	unsigned char out[2];
	int i;
	data_8x8led(0x0B, 0x07, 0);
	data_8x8led(0x09, 0x00, 0);
    data_8x8led(0x0F, 0x00, 0);
	data_8x8led(0x0A, BRIGHT, 0);
	data_8x8led(0x0C, 0x01, 0);

	for( i = 1; i< 9; ++i){
		data_8x8led (1, 0, 0);
	}
}
int main(void) {
	if( wiringPiSPISetup(SPI_CHANNEL, SPI_SPEED) == -1 ){
		printf("SPI ERROR\n");
		return 1;
	}
	init_8x8led_spi();
	printf("8x8 LED Matrix Test\n");
	
	while(1){
		data_8x8led(1, 36, 0);
		data_8x8led(2, 90, 0);
		data_8x8led(3, 129, 0);
		data_8x8led(4, 129, 0);
		data_8x8led(5, 66, 0);
		data_8x8led(6, 26, 0);
		data_8x8led(7, 24, 0);
		data_8x8led(8, 0, 0);
		delay(1000);
		
		data_8x8led(1, 0x18, 0);
		data_8x8led(2, 0x24, 0);
		data_8x8led(3, 0x42, 0);
		data_8x8led(4, 0xDB, 0);
		data_8x8led(5, 0x5A, 0);
		data_8x8led(6, 0x42, 0);
		data_8x8led(7, 0x7E, 0);
		data_8x8led(8, 0x00, 0);
		delay(1000);
	}
	return 0;
}
	
