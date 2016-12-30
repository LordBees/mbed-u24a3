#include "mbed.h"
#include "TextLCD.h"
//#include "ultrasonic.h"
#include "HCSR04.h"
#include "sstream"

float dstc;//distance to convert
int button_toggle;


DigitalIn toggle_metric(p7);
TextLCD lcd(p15, p16, p17, p18, p19, p20);

 //void dist(int distance)
//{
    //put code here to happen when the distance is changed
    //distance = 3;
    //lcd.printf("Dist chgd ", (char*)distance,'\n');
//}


//ultrasonic ultrasonic(p8,p9);
//ultrasonic mu(p8, p9, .1, 1, &dist);


int main() {
    int button_toggle = 0;
    HCSR04 sensor(p8,p9);
    sensor.setRanges(2,100);
    //mu.startUpdates();
    while (1){
        lcd.cls();
        //lcd.printf("Hello World!\n");
        //rng = mu.getCurrentDistance();
        //dist(rng);
        //lcd.printf("test",(char*)rng,'\n');
        if (toggle_metric){
            button_toggle = !button_toggle;
            }
        dstc = sensor.getDistance_cm();//e_mm();
        if (button_toggle){
            lcd.printf("metric: ");

            }
        else{
            lcd.printf("imperial: ");
            dstc = dstc/2.54;
            }
        using namespace std;
        stringstream ss;
        ss << dstc;
        lcd.printf(ss.str().c_str());
        wait(1);
        //mu.checkDistance();
    }
    }