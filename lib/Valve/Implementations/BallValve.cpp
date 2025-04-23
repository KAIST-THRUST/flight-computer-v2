#include "BallValve.h"



BallValve::BallValve(uint8_t BallValve_pin_num) : pin_num(BallValve_pin_num)    {}


void BallValve::begin(int offset_setting) {
    servo.attach(pin_num,500,2500); //PWM pulse width range for https://www.amazon.com/Torque-Motors-Waterproof-Steering-Control/dp/B073F92G2S?th=1
    offset=offset_setting;
    servo.write(0+offset);
}

void BallValve::open() {
    servo.write(90+offset);

}
void BallValve::halfOpen() {
    servo.write(45+offset);
}

void BallValve::close() {
    servo.write(0+offset);
}


void BallValve::open(int angle) {
    servo.write(angle+offset);
}


int BallValve::showAngle() {
    return servo.read()-offset;
}
