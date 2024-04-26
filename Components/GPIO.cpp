/*
 * GPIO.cpp
 *
 *  Created on: Dec 24, 2023
 *      Author: root-
 */

#include "GPIO.hpp"

GPIO::GPIO(const char gpio) :
		_PORT(this->GPIO_MAP[gpio]) {
}

GPIO::GPIO(GPIO_TypeDef *port) :
		_PORT(port) {
}

GPIO::Pin GPIO::operator [](uint16_t pin) {
	return Pin(this->_PORT, pin);
}

GPIO::Pin::Pin(GPIO_TypeDef *port, uint16_t pin) :
		_PORT(port), _PIN(pin) {

}
void GPIO::Pin::setMode(GPIO::Mode mode) {
	_PORT->MODER &= ~(0b11 << (_PIN << 1));
	_PORT->MODER |= mode << (_PIN << 1);
}
void GPIO::Pin::setPull(GPIO::Pull pull) {
	_PORT->PUPDR &= ~(0b11 << (_PIN << 1));
	_PORT->PUPDR |= pull << (_PIN << 1);
}
void GPIO::Pin::setSpeed(GPIO::Speed speed) {
	_PORT->OSPEEDR &= ~(0b11 << (_PIN << 1));
	_PORT->OSPEEDR |= speed << (_PIN << 1);
}
void GPIO::Pin::setType(GPIO::Type type) {
	_PORT->OTYPER &= ~(0b1 << _PIN);
	_PORT->OTYPER |= type << _PIN;
}
void GPIO::Pin::setAlternate(uint8_t AF){
	if (_PIN > 7){
		_PORT->AFR[1] &= ~(0xF << (4 * (_PIN - 7)));
		_PORT->AFR[1] |= AF << (4 * (_PIN - 7));
	} else {
		_PORT->AFR[0] &= ~(0xF << (4 * _PIN));
		_PORT->AFR[0] |= AF << (4 * _PIN);
	}
}

void GPIO::Pin::set() {
	_PORT-> BSRR = 1 << _PIN;
}
void GPIO::Pin::reset() {
	_PORT-> BRR = 1 << _PIN;
}

void GPIO::Pin::write(bool value) {
	if (value)
		this->set();
	else
		this->reset();
}
void GPIO::Pin::toggle() {
	_PORT->ODR ^= 1 << _PIN;
}
bool GPIO::Pin::read() {
	return (_PORT->IDR) & (1 << _PIN);
}

void GPIO::Pin::operator =(bool value) {
	this->write(value);
}

