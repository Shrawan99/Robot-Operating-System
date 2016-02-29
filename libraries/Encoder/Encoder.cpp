#include <Arduino.h>
#include "Encoder.h"

Encoder::Encoder(unsigned int intPin, unsigned int dirPin)
{
	this->intPin = intPin;
 	this->dirPin = dirPin;
 	pinMode(intPin,INPUT);
	digitalWrite(intPin,HIGH);//pullup
 	pinMode(dirPin,INPUT);
	digitalWrite(dirPin,HIGH);//pullup
}

void Encoder::increment()
{	
	//this->isCheck = false;
	if (digitalRead(this->dirPin)==1){
      this->noOfClick++;
    }
    else{
      this->noOfClick--;
    } 	
}
/*
void Encoder::check()
{
	this->isCheck = true;
}

bool Encoder::intReceived(){
	return this->isCheck;
}
*/
