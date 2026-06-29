#ifndef __TFT_H
#define __TFT_H

#define RED  	0xf800
#define GREEN	0x07e0
#define BLUE 	0x001f
#define WHITE	0xffff
#define BLACK	0x0000
#define YELLOW  0xFFE0
#define GRAY0   0xEF7D   	//灰色0 3165 00110 001011 00101
#define GRAY1   0x8410      	//灰色1      00000 000000 00000
#define GRAY2   0x4208      	//灰色2  1111111111011111

#define LCD_CTRLA   	  	GPIOA		//定义TFT数据端口
#define LCD_CTRLB   	  	GPIOB		//定义TFT数据端口

#define LCD_SCL        	GPIO_Pin_5	//PB13--->>TFT --SCL/SCK
#define LCD_SDA        	GPIO_Pin_7	//PB15 MOSI--->>TFT --SDA/DIN
#define LCD_RES					GPIO_Pin_0
#define LCD_DC          GPIO_Pin_1
#define LCD_CS          GPIO_Pin_10
#define LCD_BLK         GPIO_Pin_11

//液晶控制口置1操作语句宏定义
#define	LCD_SCL_SET  	LCD_CTRLA->BSRR=LCD_SCL    
#define	LCD_SDA_SET  	LCD_CTRLA->BSRR=LCD_SDA   
#define	LCD_CS_SET  	LCD_CTRLA->BSRR=LCD_CS   
#define	LCD_DC_SET  	LCD_CTRLB->BSRR=LCD_DC 
#define	LCD_RES_SET  	LCD_CTRLB->BSRR=LCD_RES 
//液晶控制口置0操作语句宏定义
#define	LCD_SCL_CLR  	LCD_CTRLA->BRR=LCD_SCL  
#define	LCD_SDA_CLR  	LCD_CTRLA->BRR=LCD_SDA 
#define	LCD_CS_CLR  	LCD_CTRLA->BRR=LCD_CS 
#define	LCD_RES_CLR  	LCD_CTRLB->BRR=LCD_RES
#define	LCD_DC_CLR  	LCD_CTRLB->BRR=LCD_DC 




void ST7735_INITIAL ();
void LCDTurnOnDisplay (void);
void LCDTurnOffDisplay (void);
void LCDTurnOnPartial (void);
void LCDTurnOffPartial (void);
void LCDTurnOnIdle (void);
void LCDTurnOffIdle (void);
void LCDSleepInMode (void);
void LCDSleepOutMode (void);



#endif
