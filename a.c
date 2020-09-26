/*****************************************************
This program was produced by the
CodeWizardAVR V2.05.3 Standard
Automatic Program Generator
© Copyright 1998-2011 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project : 
Version : 
Date    : 21/05/2020
Author  : SangengoN
Company : 
Comments: 


Chip type               : ATmega16
Program type            : Application
AVR Core Clock frequency: 8.000000 MHz
Memory model            : Small
External RAM size       : 0
Data Stack size         : 256
*****************************************************/

#include <mega16.h>

// Alphanumeric LCD functions
#include <alcd.h>
#include <delay.h>
#include <stdio.h>
#include <stdlib.h>

#define ADC_VREF_TYPE 0x00

// Read the AD conversion result
unsigned int read_adc(unsigned char adc_input)
{
ADMUX=adc_input | (ADC_VREF_TYPE & 0xff);
// Delay needed for the stabilization of the ADC input voltage
delay_us(10);
// Start the AD conversion
ADCSRA|=0x40;
// Wait for the AD conversion to complete
while ((ADCSRA & 0x10)==0);
ADCSRA|=0x10;
return ADCW;
}

// Declare your global variables here
float voltage = 5.0;
float current = 4.0;

char lcd_buffer[33];
char lcd_buffer2[33];
float vinput;
int dataadc;

float arus1, vout1, daya,sinyal;
int adc1, count, dataMin, dataMax;
unsigned char buf_min[10];
unsigned char buf_max[10];
unsigned char buf_arus1[10];
unsigned char buf_daya[10];

 #define password 'jombloelit';
 #define auth 'jr4JZbDvkPOI-6C7Ra15UTvZsYsIxkYC';
 #define ssid 'WAKANDA';

void main(void)
{
// Declare your local variables here

// Input/Output Ports initialization
// Port A initialization
// Func7=In Func6=In Func5=In Func4=In Func3=In Func2=In Func1=In Func0=In 
// State7=T State6=T State5=T State4=T State3=T State2=T State1=T State0=T 
PORTA=0x00;
DDRA=0x00;

// Port B initialization
// Func7=In Func6=In Func5=In Func4=In Func3=In Func2=In Func1=In Func0=In 
// State7=T State6=T State5=T State4=T State3=T State2=T State1=T State0=T 
PORTB=0x00;
DDRB=0x00;

// Port C initialization
// Func7=In Func6=In Func5=In Func4=In Func3=In Func2=In Func1=In Func0=Out 
// State7=T State6=T State5=T State4=T State3=T State2=T State1=T State0=1 
PORTC=0x01;
DDRC=0x01;

// Port D initialization
// Func7=In Func6=In Func5=In Func4=In Func3=In Func2=In Func1=In Func0=In 
// State7=T State6=T State5=T State4=T State3=T State2=T State1=T State0=T 
PORTD=0x00;
DDRD=0x00;

// Timer/Counter 0 initialization
// Clock source: System Clock
// Clock value: Timer 0 Stopped
// Mode: Normal top=0xFF
// OC0 output: Disconnected
TCCR0=0x00;
TCNT0=0x00;
OCR0=0x00;

// Timer/Counter 1 initialization
// Clock source: System Clock
// Clock value: Timer1 Stopped
// Mode: Normal top=0xFFFF
// OC1A output: Discon.
// OC1B output: Discon.
// Noise Canceler: Off
// Input Capture on Falling Edge
// Timer1 Overflow Interrupt: Off
// Input Capture Interrupt: Off
// Compare A Match Interrupt: Off
// Compare B Match Interrupt: Off
TCCR1A=0x00;
TCCR1B=0x00;
TCNT1H=0x00;
TCNT1L=0x00;
ICR1H=0x00;
ICR1L=0x00;
OCR1AH=0x00;
OCR1AL=0x00;
OCR1BH=0x00;
OCR1BL=0x00;

// Timer/Counter 2 initialization
// Clock source: System Clock
// Clock value: Timer2 Stopped
// Mode: Normal top=0xFF
// OC2 output: Disconnected
ASSR=0x00;
TCCR2=0x00;
TCNT2=0x00;
OCR2=0x00;

// External Interrupt(s) initialization
// INT0: Off
// INT1: Off
// INT2: Off
MCUCR=0x00;
MCUCSR=0x00;

// Timer(s)/Counter(s) Interrupt(s) initialization
TIMSK=0x00;

// USART initialization
// Communication Parameters: 8 Data, 1 Stop, No Parity
// USART Receiver: Off
// USART Transmitter: On
// USART Mode: Asynchronous
// USART Baud Rate: 9600
UCSRA=0x00;
UCSRB=0x08;
UCSRC=0x86;
UBRRH=0x00;
UBRRL=0x33;

// Analog Comparator initialization
// Analog Comparator: Off
// Analog Comparator Input Capture by Timer/Counter 1: Off
ACSR=0x80;
SFIOR=0x00;

// ADC initialization
// ADC Clock frequency: 125.000 kHz
// ADC Voltage Reference: AREF pin
// ADC Auto Trigger Source: ADC Stopped
ADMUX=ADC_VREF_TYPE & 0xff;
ADCSRA=0x86;

// SPI initialization
// SPI disabled
SPCR=0x00;

// TWI initialization
// TWI disabled
TWCR=0x00;

// Alphanumeric LCD initialization
// Connections are specified in the
// Project|Configure|C Compiler|Libraries|Alphanumeric LCD menu:
// RS - PORTC Bit 7
// RD - PORTC Bit 6
// EN - PORTC Bit 5
// D4 - PORTC Bit 4
// D5 - PORTC Bit 3
// D6 - PORTC Bit 2
// D7 - PORTC Bit 1
// Characters/line: 16
lcd_init(16);


/*

 char password[10];
 char auth[50];
 char ssid[10];

*/

 // printf("{\"voltage\":%0.1f, \"current\":%0.1f, \"sinyal\":%0.1f}\r\n",vinput,current,sinyal);  
 
 //sprintf("{\"auth\":%s, \"ssid\":%s, \"pass\":%s}\r\n",auth,ssid,password); 
   delay_ms(5000);
  printf("{\"auth\":\"jr4JZbDvkPOI-6C7Ra15UTvZsYsIxkYC\",\"ssid\":\"WAKANDA\",\"pass\":\"jombloelit\"}");              
  delay_ms(1000);   
   printf("{\"auth\":\"jr4JZbDvkPOI-6C7Ra15UTvZsYsIxkYC\",\"ssid\":\"WAKANDA\",\"pass\":\"jombloelit\"}");   
   delay_ms(1000);       
   printf("{\"auth\":\"jr4JZbDvkPOI-6C7Ra15UTvZsYsIxkYC\",\"ssid\":\"WAKANDA\",\"pass\":\"jombloelit\"}");              
  delay_ms(1000);   
   printf("{\"auth\":\"jr4JZbDvkPOI-6C7Ra15UTvZsYsIxkYC\",\"ssid\":\"WAKANDA\",\"pass\":\"jombloelit\"}");   
   delay_ms(1000);
   

while(1){

 float a = 90.0,b=10.0;
      current = 1.2;

 
 // vcc = 5v ; adc 10 bit = 1024 desimal  
 //sprintf(lcd_buffer,"Volt :%0.0001f V",vinput);


//sprintf(lcd_buffer,"Current :%0.0001f A",current);


// printf("%0.1f %0.1f %0.1f %0.1f\r\n", vinput,current,a,b);
//printf("%0.0002f",dataadc);
 dataadc=read_adc(0);
//if(dataadc<600)dataadc = 0;

vinput=((float)(dataadc*17)/700);
sinyal = vinput/19.3*100; 
if(sinyal>100){
sinyal =100;
}

for ( count = 0; count <= 1000; count++){
    adc1 = read_adc(1);
    if ( adc1 > dataMax ) dataMax = adc1;
            if ( adc1 < dataMin ) dataMin = adc1;
            delay_ms(1);
        }

    vout1 = dataMax*(5.0/1023);
      //arus1 = fabs(vout1-2.50)/0.066;
      arus1 = fabs(vout1-2.50)/0.066;
      arus1 = arus1/3;
      current = arus1;
      if(current>10){
      current = 0;}
      
     // adc1 = read_adc(1);
printf("{\"voltage\":%0.1f, \"current\":%0.01f, \"sinyal\":%0.1f}\r\n",vinput,current,sinyal);
sprintf(lcd_buffer,"%0.1f %0.1f %0.1f\n", vinput,current,sinyal);
sprintf(lcd_buffer2," V    Ir     S");
lcd_gotoxy(0,0);
lcd_puts(lcd_buffer2);
lcd_gotoxy(0,1);
lcd_puts(lcd_buffer);
//printf("{\"auth\":\"jr4JZbDvkPOI-6C7Ra15UTvZsYsIxkYC\",\"ssid\":\"WAKANDA\",\"pass\":\"jombloelit\"}");
delay_ms(5000);


      


};           }


//while (1)
//      {
//      
//      char buff[33];
//      
//      float a = 90.0,b=90.0;
//      current = 1.0;
//    //  voltage = 9.8;current = 1.2; 
//     dataadc=read_adc(0);
//    // if(dataadc<600)dataadc = 0;
//    vinput=((float)(dataadc*17)/700);
//    sprintf(lcd_buffer,"Volt :%i V",dataadc);
//      lcd_gotoxy(0,1);
//        lcd_puts(lcd_buffer);         
//      lcd_gotoxy(0,0);
//      printf("%0.1f %0.1f %0.1f %0.1f\r\n", voltage,current,a,b);
//      lcd_puts("a");
//      DDRC=0x00;
//      delay_ms(500);    
//      DDRC=0x01;
//      delay_ms(500);
//      //voltage +=0.1;
//     // current +=0.2;
//      
//     //  if(voltage>300){voltage = 0;}
//     //  if(current>300){current = 0;}
//      // Place your code here 
//      //lcd_clear();
//
//      };
//}
