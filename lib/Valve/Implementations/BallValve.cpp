#include "BallValve.h"



BallValve::BallValve(uint8_t BallValve_pin_num) : pin_num(BallValve_pin_num)    {}


void BallValve::begin() {
    servo.attach(pin_num,500,2500); //PWM pulse width range for https://www.amazon.com/Torque-Motors-Waterproof-Steering-Control/dp/B073F92G2S?th=1
    servo.write(0);
}

void BallValve::open() {
    servo.write(90);

}
void BallValve::halfOpen() {
    servo.write(45);
}

void BallValve::close() {
    servo.write(0);
}


void BallValve::open(int angle) {
    servo.write(angle);
}


int BallValve::showAngle() {
    return servo.read();
}
