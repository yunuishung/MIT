
## SPI 파이썬 제어
sudo apt get install build essential
sudo apt get install python dev python pip
sudo apt get install libfreetype6 dev libjpeg dev
git clone http://github.com/rm hull/luma.led_matrix.git
sudo H pip install upgrade luma.led_matrix


## Spidev SPI function Reference

import spidev               -  spidev를 사용하기 위해 python spidev 모듈 import
SpiDev object = SpiDev()    - SPI통신에 사용할 spidev objec 를 만듬 . 리턴값은 spidev objec 이며 이후 데이터 통신에 사용
spidev. Open (bus, device)  - bus : SPI 버스 , 현재는 0 을 사용
device :                    - 디바이스 번호 , 0 또는 1 이 가능
spi.dev, close()            - SPI 디바이스와의 연결종료
data = spidev. xfer([values])

## SPI 트랜잭션 수행
values :                           - 송신데이타
data = spidev.readbytes(len)       - SPI디바이스에서 수신할 데이타의 바이트 수
data = spidev.writebytes( values)  - SPI디바이스에서 송신할 데이터 values 를 송신
mode                               - mode는 함수가 아니며 속성 ( property )
                                   -[Clock Property][Clock Phase] (0b00=0, 0b01=1, 0b10=2, 0b11=3)
max_speed_hz                       - 현재의 통신속도 설정 값
