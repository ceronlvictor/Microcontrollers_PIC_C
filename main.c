#include <18F4550.h>
#fuses NOWRT, NOPUT, NOWDT, NOLVP, NOCPD
#use delay(internal=500KHZ)
#use standard_io(b)
#use standard_io(d)
#int_TIMER0

long a = 31;
int x = 1;  //Variable para saber que motor usar
void main()
{
int16 b;
int16 pwm;

setup_ccp2(CCP_PWM);
set_adc_channel(0);
setup_ccp1(CCP_PWM);
SETUP_ADC_PORTS(AN0);
SETUP_ADC(ADC_CLOCK_INTERNAL);
setup_timer_2(T2_DIV_BY_16, 155, 1);

while(1) {

//Parte 1
b = read_adc();
pwm = (3*b/23)+31;
SET_PWM2_DUTY(pwm);
delay_us(10);

//Parte 2
if (input(PIN_A1) == 1 && a<=63)
  {
   set_pwm1_duty(a);
   a++;
  }
 if (input(PIN_A2) == 1 && a<=47) 
  {
   set_pwm1_duty(a);
   a++; 
  }
 if (input(PIN_A2) == 1 && a>=47) 
  {
   set_pwm1_duty(a);
   a--; 
  }
 if (input(PIN_A3) == 1 && a>=31)
  {
   set_pwm1_duty(a);
   a--; 
  }
 
 //Parte 3
 if (input(PIN_B2) == 1)
 {
 
    if (input(PIN_B0) == 1)
    {
      output_high(PIN_D1);//Encender PWM
      delay_us(1000);        
      output_low(PIN_D1); //Apagar PWM
      set_timer0(37035);//Precargar el timer0
   }
       if (input(PIN_B1) == 1)
    {
      output_high(PIN_D1);//Encender PWM
      delay_us(1000);        
      output_low(PIN_D1); //Apagar PWM
      set_timer0(37035);//Precargar el timer0
   }
      else if ( x == 2)
      {
      output_high(PIN_D1);//Encender PWM
      delay_us(1500);         
      output_low(PIN_D1);//Apagar PWM
      set_timer0(37785);//Precargar el timer0
   }
   //else{                     
     // output_high(PIN_D1);//Encender PWM
      //delay_us(2000);  //Esperar 2ms
      //output_low(PIN_D1); //Apagar PWM
      //set_timer0(38535); //Precargar el timer0
   //}
 }
 
 }
}
