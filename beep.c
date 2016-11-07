#include <avr/io.h>        
#include <util/delay.h>  
#include <math.h> 
 

void yichangliangduan(void){
PORTE = 0X08;      // PORTE����ߵ�ƽ��ʹ����������
	DDRE = 0X08;      // ���ö˿�PE3Ϊ�����
	while (1) {
        PORTE &= ~(1 << PE3);  //PE3��"0"���������÷������ı�PE������λ
                           //��״̬��ƽʱ�������Ƽ�����ʹ�÷���
	    _delay_ms(100);    // ��ʱ100���룬����������������?
		_delay_ms(100);
		_delay_ms(100);
		_delay_ms(100);
		_delay_ms(100);

		 PORTE |= (1 << PE3);  //ʹPE3����ߵ�ƽ������������
		_delay_ms(100);
		_delay_ms(100);
		_delay_ms(100);
		_delay_ms(100);
		_delay_ms(100);

		PORTE &= ~(1 << PE3);  //PE3��"0"���������÷������ı�PE������λ
                           //��״̬��ƽʱ�������Ƽ�����ʹ�÷���
	    _delay_ms(100);    // ��ʱ100���룬����������������?
		_delay_ms(100);
		_delay_ms(50);

		PORTE |= (1 << PE3);  //ʹPE3����ߵ�ƽ������������
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

