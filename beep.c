#include <avr/io.h>        
#include <util/delay.h>  
#include <math.h> 
 

void yichangliangduan(void){
PORTE = 0X08;      // PORTE输出高电平，使蜂鸣器不响
	DDRE = 0X08;      // 配置端口PE3为输出口
	while (1) {
        PORTE &= ~(1 << PE3);  //PE3置"0"，这种设置方法不改变PE口其余位
                           //的状态，平时程序中推荐这种使用方法
	    _delay_ms(100);    // 延时100毫秒，参数必须是整数吗?
		_delay_ms(100);
		_delay_ms(100);
		_delay_ms(100);
		_delay_ms(100);

		 PORTE |= (1 << PE3);  //使PE3输出高电平，蜂鸣器不响
		_delay_ms(100);
		_delay_ms(100);
		_delay_ms(100);
		_delay_ms(100);
		_delay_ms(100);

		PORTE &= ~(1 << PE3);  //PE3置"0"，这种设置方法不改变PE口其余位
                           //的状态，平时程序中推荐这种使用方法
	    _delay_ms(100);    // 延时100毫秒，参数必须是整数吗?
		_delay_ms(100);
		_delay_ms(50);

		PORTE |= (1 << PE3);  //使PE3输出高电平，蜂鸣器不响
		_delay_ms(100);
		_delay_ms(100);
		_delay_ms(50);

	


	 }
}

int beep(double ms)
{
   PORTE = 0X08;  
	DDRE = 0X08;
	 
	PORTE &= ~(1 << PE3);
	_delay_ms(ms);
	PORTE |= (1 << PE3);
	_delay_ms(ms);	
	return 0;
}


void sound(double freq)
{
int i=0;
double fff=500/freq;
while(i<=200)
{beep(fff);
++i;
}
}

int main(void)
{
	if (1) {yichangliangduan();return;}
	
	double a[20]={262,262,294,294,330,330,370, 392, 392,330,330,294,294,262};
	int i;
	for (i=0;i<sizeof(a);i++)
		sound(a[i]);
	return 0;
}

