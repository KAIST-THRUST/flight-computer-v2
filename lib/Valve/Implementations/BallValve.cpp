#include "BallValve.h"



BallValve::BallValve(uint8_t BallValve_pin_num) : pin_num(BallValve_pin_num)    {}


void BallValve::begin() {
    servo.attach(pin_num);
    servo.write(0);
}

void BallValve::open() {
    servo.write(90);

}
void BallValve::half_open() {
    servo.write(45);
}

void BallValve::close() {
    servo.write(0);
}

