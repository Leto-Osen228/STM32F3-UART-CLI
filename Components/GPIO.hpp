/*
 * GPIO.h
 *
 *  Created on: Dec 24, 2023
 *      Author: Alex Petrov
 */

#ifndef INC_GPIO_H_
#define INC_GPIO_H_

#include <stdint.h>
#include <stdbool.h>
#include <map>
#include "stm32f3xx.h"

class GPIO {
public:
	std::map<char, GPIO_TypeDef*> GPIO_MAP = {
				{'A', GPIOA},
				{'B', GPIOB},
				{'C', GPIOC},
				{'D', GPIOD},
				{'E', GPIOE}
		};

	enum Mode {
		INPUT = 0b00, OUTPUT = 0b01, ALTERNATIVE = 0b10, ANALOG = 0b11,
	};

	enum Pull {
		NOPULL = 0, PULLUP = 0b01, PULLDOWN = 0b10,
	};

	enum Speed {
		LOW = 0, MEDIUM = 1, HIGH = 2,
	};

	enum Type {
		PUSHPULL = 0, OPENDRAIN = 1,
	};
/*
	enum Pin : uint16_t {
		GPIO_PIN_0 = 0x0001,
		GPIO_PIN_1 = 0x0002,
		GPIO_PIN_2 = 0x0004,
		GPIO_PIN_3 = 0x0008,
		GPIO_PIN_4 = 0x0010,
		GPIO_PIN_5 = 0x0020,
		GPIO_PIN_6 = 0x0040,
		GPIO_PIN_7 = 0x0080,
		GPIO_PIN_8 = 0x0100,
		GPIO_PIN_9 = 0x0200,
		GPIO_PIN_10 = 0x400,
		GPIO_PIN_11 = 0x800,
		GPIO_PIN_12 = 0x8000,
		GPIO_PIN_13 = 0x8000,
		GPIO_PIN_14 = 0x8000,
		GPIO_PIN_15 = 0x8000
	};
*/
	class Pin {
	public:
		Pin(GPIO_TypeDef *port, uint16_t pin);
		void setMode(GPIO::Mode = INPUT);
		void setPull(GPIO::Pull = NOPULL);
		void setSpeed(GPIO::Speed = LOW);
		void setType(GPIO::Type = PUSHPULL);
		void setAlternate(uint8_t);

		void set();
		void reset();

		void write(bool value);
		void toggle();
		bool read();

		void operator =(bool value);
	private:
		GPIO_TypeDef *_PORT;
		const uint16_t _PIN;

	};

	GPIO(const char);
	GPIO(GPIO_TypeDef *port);
	Pin operator [](uint16_t pin);
private:
	GPIO_TypeDef *_PORT;
};

#endif /* INC_GPIO_H_ */
