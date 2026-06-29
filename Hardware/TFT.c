#include "TFT.h"
#include "Delay.h"


void  ST7735_INITIAL ()
{ 
	//------------------------------------ST7735R 复位时序-----------------------------------------//
	LCD_RES_SET; 
	Delay_ms(1);                                                              //延时 1ms 
	LCD_RES_CLR; 
	Delay_ms(1);                                                              //延时 1ms 
	LCD_RES_SET; 
	Delay_ms(120);                                                              //延时 120ms
	//--------------------------------ST7735R 复位时序结束--------------------------------------// 
	 
	//--------------------------------ST7735S 复位时序结束--------------------------------------// 
	LCD_WriteCommand(0x11); //退出睡眠
	Delay_ms(120);              //延时 120ms
	//------------------------------------ST7735S 帧速率-----------------------------------------// 
	LCD_WriteCommand(0xB1); 
	LCD_WriteData(0x05); 
	LCD_WriteData(0x3C); 
	LCD_WriteData(0x3C); 
	LCD_WriteCommand(0xB2); 
	LCD_WriteData(0x05); 
	LCD_WriteData(0x3C); 
	LCD_WriteData(0x3C); 
	LCD_WriteCommand(0xB3); 
	LCD_WriteData(0x05); 
	LCD_WriteData(0x3C); 
	LCD_WriteData(0x3C); 
	LCD_WriteData(0x05); 
	LCD_WriteData(0x3C); 
	LCD_WriteData(0x3C); 
	//------------------------------------ST7735S 帧速率结束---------------------------------// 
	LCD_WriteCommand(0xB4); //点反转
	LCD_WriteData(0x03); 
	//------------------------------------ST7735S 电源时序---------------------------------// 
	LCD_WriteCommand(0xC0); 
	LCD_WriteData(0x28); 
	LCD_WriteData(0x08); 
	LCD_WriteData(0x04); 
	LCD_WriteCommand(0xC1); 
	LCD_WriteData(0XC0); 
	LCD_WriteCommand(0xC2); 
	LCD_WriteData(0x0D); 
	LCD_WriteData(0x00); 
	LCD_WriteCommand(0xC3); 
	LCD_WriteData(0x8D); 
	LCD_WriteData(0x2A); 
	LCD_WriteCommand(0xC4); 
	LCD_WriteData(0x8D); 
	LCD_WriteData(0xEE); 
	//---------------------------------ST7735S 电源时序结束-------------------------------------// 
	LCD_WriteCommand(0xC5); //VCOM 公共电极电压
	LCD_WriteData(0x1A); 
	LCD_WriteCommand(0x36); //MX, MY, RGB 模式
	LCD_WriteData(0xC0); 
	//------------------------------------ST7735S Gamma 校正---------------------------------// 
	LCD_WriteCommand(0xE0); 
	LCD_WriteData(0x04); 
	LCD_WriteData(0x22); 
	LCD_WriteData(0x07); 
	LCD_WriteData(0x0A); 
	LCD_WriteData(0x2E); 
	LCD_WriteData(0x30); 
	LCD_WriteData(0x25); 
	LCD_WriteData(0x2A); 
	LCD_WriteData(0x28); 
	LCD_WriteData(0x26); 
	LCD_WriteData(0x2E); 
	LCD_WriteData(0x3A); 
	LCD_WriteData(0x00); 
	LCD_WriteData(0x01); 
	LCD_WriteData(0x03); 
	LCD_WriteData(0x13); 
	LCD_WriteCommand(0xE1); 
	LCD_WriteData(0x04); 
	LCD_WriteData(0x16); 
	LCD_WriteData(0x06); 
	LCD_WriteData(0x0D); 
	LCD_WriteData(0x2D); 
	LCD_WriteData(0x26); 
	LCD_WriteData(0x23); 
	LCD_WriteData(0x27); 
	LCD_WriteData(0x27); 
	LCD_WriteData(0x25); 
	LCD_WriteData(0x2D); 
	LCD_WriteData(0x3B); 
	LCD_WriteData(0x00); 
	LCD_WriteData(0x01); 
	LCD_WriteData(0x04); 
	LCD_WriteData(0x13); 
	//------------------------------------ST7735S Gamma 校正结束-----------------------------// 
	LCD_WriteCommand(0x3A); //65K 色模式
	LCD_WriteData(0x05); 
	LCD_WriteCommand(0x29); //开启显示
	 
} 

void LCDTurnOnDisplay (void)
{
	Write(COMMAND,0x29); //开启显示
}
void LCDTurnOffDisplay (void)
{
	Write(COMMAND,0x28); //关闭显示
}
void LCDTurnOnPartial (void)
{
	Write(COMMAND,0x30); //设置部分显示区域
	Write(DATA,0x00);
	Write(DATA,PSL); //PSL:起始行
	Write(DATA,0x00);
	Write(DATA,PEL); //PEL:结束行
	Write(COMMAND,0x12); //开启部分显示模式
}
void LCDTurnOffPartial (void)
{
	Write(COMMAND,0x13); //关闭部分显示模式
}
void LCDTurnOnIdle (void)
{
	Write(COMMAND,0x39); //开启空闲模式
}
void LCDTurnOffIdle (void)
{
	Write(COMMAND,0x38); //关闭空闲模式
}
void LCDSleepInMode (void)
{
	Write(COMMAND,0x10); //进入睡眠
	Delay_ms (120); //延时 120ms
}
void LCDSleepOutMode (void)
{
	Write(COMMAND,0x11); //退出睡眠
	Delay_ms (120); //延时 120ms
}
