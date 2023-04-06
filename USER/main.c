//////////////////////////////////////////////////////////////////////////////////	 
//  �� �� ��   : main.c
//  �� �� ��   : v2.0
//  ��    ��   : luxban
//  ��������   : 2022-6-01
//  ����޸�   : 
//  ��������   :��ʾ����(STM32F103ϵ��)
//              �ӿ�˵��: 
//              LED:PA8
//   
//              TFT-LCD: 
//              GND   ��Դ��
//              VCC   3.3v��Դ
//              SCL   PB4��SCLK��
//              SDA   PB5��MOSI��
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
	LED_Init();//LED��ʼ��
//	LCD_Init();//LCD��ʼ��
//	LCD_Fill(0,0,LCD_W,LCD_H,WHITE);
	uart_init(9600);
    USART_4G_Init();
//	DHT11_Init ();
	TIM3_Int_Init(5000-1,7200-1);//10Khz�ļ���Ƶ�ʣ�������5000Ϊ500ms  

//	gpio_for_w5500_config();						        /*��ʼ��MCU�������*/
//	reset_w5500();											/*Ӳ��λW5500*/
//	set_w5500_mac();										/*����MAC��ַ*/
//	set_w5500_ip();											/*����IP��ַ*/
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
////	   do_tcp_client();                  /*TCP_Client ���ݻػ����Գ���*/    

//		
//	}
}

