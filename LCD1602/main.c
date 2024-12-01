#include<reg52.h>
#include<string.h>
#include<intrins.h>
#define uchar unsigned char
#define uint unsigned int
sbit RS = P2^6;
sbit EN = P2^7;
sbit RW = P2^5;
uchar code table[] = {"Temp 27.0"};
void delay1ms(uint time);//N ms delay
 void init_1602(void); //Initialize 1602
 void writecmd_1602(uint cmd); //Write instruction function
 void writedata_1602(uchar dat); //Write data function
 void display(uchar num); //Display function
 
int main()
{
	delay1ms(10);
	 init_1602(); //Initialize 1602
	delay1ms(5); 
	 writecmd_1602(0x82); //Set the starting position of the display
	delay1ms(5);
	display(strlen(table));
	while(1);
	return 0;
}	
void delay1ms(uint time)   	
{
    unsigned char a,b,i;
	for(i = time; i != 0;i--)
		for(b=199;b>0;b--)
			for(a=1;a>0;a--);
}
void init_1602(void)
{
	 delay1ms(15); //Delay 15ms
	 writecmd_1602(0x38); //Mode setting
 
	 writecmd_1602(0x0c); //Display settings
	
	 writecmd_1602(0x06); //Display mode
	
	 writecmd_1602(0x01); //Clear screen
}
void writecmd_1602(uint cmd)
{
	RS = 0;
	RW = 0;
	P0 = cmd;
	EN = 1;
	delay1ms(1);
	EN = 0;
}
void writedata_1602(uchar dat)
{
	RS = 1;
	RW = 0;
	P0 = dat;
	EN = 1;
	delay1ms(1);
	EN = 0;
}
void display(uchar num)
{
	uchar i;
	for(i = 0; i < num; i++)
	{
		writedata_1602(table[i]);
	}
	delay1ms(5);
}