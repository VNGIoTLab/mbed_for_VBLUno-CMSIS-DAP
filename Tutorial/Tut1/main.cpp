#include "mbed.h"

/*Config modules*/
DigitalOut myled(p7);   /*VBLUno: LED is p7*/
Serial pc(p10, p11);    /*VBLUno: TX is p10, RX is p11 (Serial)*/

/*MAIN funcrion*/
int main() {
    /*Init*/
    pc.baud(9600);              
    
    /*Endless Loop*/
    while(1) {
        myled = 1;
        wait(0.2);
        myled = 0;
        wait(0.2);
        pc.printf("VBLUno - mbed OS - Hello World!\r\n");
    }
}
