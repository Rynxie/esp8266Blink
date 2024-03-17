include <stdio.h>

#define GPIO_ENABLE_W1TS    0x60000310 //Output enable register 
#define GPIO_OUT_W1TS       0x60000304 //Set Output High register
#define GPIO_OUT_W1TC       0x60000308 //Set Output low register

void delay(unsigned int milliseconds) {
    for (unsigned int i = 0; i < milliseconds; i++) {
        for (volatile unsigned int j = 0; j < 10000; j++) { //Delay function for desired ms
        }
    }
}


void app_main(){

    volatile uint16_t * gpio_enable_w1ts = (volatile uint16_t*) GPIO_ENABLE_W1TS; 
    volatile uint16_t * gpio_out_w1ts = (volatile uint16_t*) GPIO_OUT_W1TS;
    volatile uint16_t * gpio_out_w1tc = (volatile uint16_t*) GPIO_OUT_W1TC;

    *gpio_enable_w1ts = (1<<4); //enable GPIO4


    while(1){
       *gpio_out_w1ts = (1<<4); //Set high GPIO4
       delay(1000);
       *gpio_out_w1tc = (1<<4); //Set low GPIO4
       delay(1000);
    }


}
