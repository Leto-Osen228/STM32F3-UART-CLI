/*
 * USART.h
 *
 *  Created on: Nov 10, 2023
 *      Author: root-
 */

#ifndef UART_H_
#define UART_H_

#include <stdint.h>
#include <stdbool.h>
#include <string>

#include "stm32f3xx.h"
#include "cmsis_os.h"

#include "Buffer.h"

class USART {
public:
	USART(USART_TypeDef*);
	virtual ~USART();

	void init();
	void handler();

	void write(const char *buf);
	void read(char *buf);

	std::string readline();

private:
	USART_TypeDef* _usart;

	osMutexId_t _tx_mutex;

	Buffer<char, 512> _tx;
	Buffer<char, 512> _rx;
};

#endif /* UART_H_ */
