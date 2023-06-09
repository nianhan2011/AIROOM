//////////////////////////////////////////////////////////////////////////////////	 
//  文 件 名   : main.c
//  版 本 号   : v2.0
//  作    者   : luxban
//  生成日期   : 2022-6-01
//  最近修改   : 
//  功能描述   :演示例程(STM32F103系列)
//              接口说明: 
//              LED:PA8
//   
//              TFT-LCD: 
//              GND   电源地
//              VCC   3.3v电源
//              SCL   PB4（SCLK）
//              SDA   PB5（MOSI）
//              RES   PB6
//              DC    PB7
//              CS    PB8
//              BLK   PB9
//              ----------------------------------------------------------------
//******************************************************************************/
#include "delay.h"
#include "sys.h"
#include "led.h"
#include "lcd_init.h"
#include "lcd.h"
#include "pic.h"
#include "usart.h"
#include "bsp_dht11.h"
#include "stdio.h"
#include "timer.h"
#include "tcp_demo.h"
#include "w5500.h"
#include "W5500_conf.h"
#include "socket.h"
#include "utility.h"
#include "bsp_4G.h"
#include "os_system.h"

void send_msg() {
	
	if (TCP_Is_Connect)
	{
	   TCP_Send("48656C6C6F21");

	}


}


int main(void)
{
  NVIC_Configuration();
	char buff[100];

	delay_init();
	LED_Init();//LED初始化
//	LCD_Init();//LCD初始化
//	LCD_Fill(0,0,LCD_W,LCD_H,WHITE);
	uart_init(9600);
    USART_4G_Init();
//	DHT11_Init ();
	TIM3_Int_Init(5000-1,7200-1);//10Khz的计数频率，计数到5000为500ms  

//	gpio_for_w5500_config();						        /*初始化MCU相关引脚*/
//	reset_w5500();											/*硬复位W5500*/
//	set_w5500_mac();										/*配置MAC地址*/
//	set_w5500_ip();											/*配置IP地址*/
//	socket_buf_init(txsize, rxsize);




	Start_ME();

    os_cpu_interrupt_register(cpu_critical_control);
    os_task_init();
	os_create_task(OS_TASK1, ReceiveString, 1, OS_SLEEP);
	os_create_task(OS_TASK2, send_msg, 2, OS_SLEEP);
    os_start();


//	while(1)
//	{

//		ReceiveString();
//		
//		
//		if (ReceiveMSG_Flag.Finish_Flag == 1) {
//		 if (TCP_Is_Connect)
//			{
//			 TCP_Send("48656C6C6F21");

//			}
//			
//			ReceiveMSG_Flag.Finish_Flag = 0;
//			
//		}

//		
//		
////	   do_tcp_client();                  /*TCP_Client 数据回环测试程序*/    

//		
//	}
}

