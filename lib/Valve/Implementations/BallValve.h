#pragma once

#include <Arduino.h>
#include <Servo.h>


class BallValve{

    private:
    Servo servo;
    const uint8_t pin_num;

    public:
    BallValve(uint8_t BallValve_pin_num);
    void begin();

    void open();
    void half_open();
    void close();

};

