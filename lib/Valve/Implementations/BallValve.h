#pragma once

#include <Arduino.h>
#include <Servo.h>


class BallValve{

    private:
    Servo servo;
    const uint8_t pin_num;
    int offset;

    public:
    BallValve(uint8_t BallValve_pin_num); //constructor without offset setting, default offset is 52
    BallValve(uint8_t BallValve_pin_num, int offset_setting); //constructor with offset setting
    void begin();   //set servo pin and initialize angle to 0 degrees

    void open();    //servo to 90 degrees
    void halfOpen();    //servo to 45 degrees
    void close();   //servo to 0 degrees

    void open(int angle);   //open to a specific angle(in degrees, 0~180)

    int showAngle();    //return servo angle in degrees

};

