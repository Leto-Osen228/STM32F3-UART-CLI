/*
 * USART.cpp
 *
 *  Created on: Nov 10, 2023
 *      Author: root-
 */

#include "UART.h"
#include "cmsis_os2.h"

USART::USART(USART_TypeDef *usart) :
		_usart(usart) {
}

USART::~USART() {
	// TODO Auto-generated destructor stub
}

void USART::init() {
	_usart->CR1 |= USART_CR1_IDLEIE;
	_usart->CR1 |= USART_CR1_RXNEIE;
	//_usart->CR1 |= USART_CR1_TXEIE;
	_usart->CR1 |= USART_CR1_TCIE;
}

void USART::handler() {
	if (_usart->ISR & USART_ISR_RXNE)
		_rx.add(_usart->RDR);

	if (_usart->ISR & USART_ISR_IDLE) {
		_usart->ICR |= USART_ICR_IDLECF;
		_rx.add('\n');
	}

	if (_usart->ISR & USART_ISR_TXE && _tx.len())
		_usart->TDR = _tx.get();

	if (_usart->ISR & USART_ISR_TC) {
		_usart->ICR |= USART_ICR_TCCF;
		_usart->CR1 &= ~USART_CR1_TXEIE;
	}
	if (_usart->ISR & USART_ISR_PE)
		_usart->ICR |= USART_ICR_PECF;
	if (_usart->ISR & USART_ISR_FE)
		_usart->ICR |= USART_ICR_FECF;
	if (_usart->ISR & USART_ISR_NE)
		_usart->ICR |= USART_ICR_NCF;

	if (_usart->ISR & USART_ISR_ORE)
		_usart->ICR |= USART_ICR_ORECF;

}

void USART::write(const char *buf) {
	while (*buf) {
//		while ((_usart->ISR & USART_ISR_TXE) == 0);
//		_usart->TDR = *buf++;
		_tx.add(*buf++);
	}
	if (_tx.len())
		_usart->CR1 |= USART_CR1_TXEIE;
}

void USART::read(char *buf) {
	while (char c = _rx.get())
		*buf++ = c;
	*buf = 0;
}

std::string USART::readline() {
	char c;
	std::string line;
	while (c != '\n') {
		c = _rx.get();
		if (c == '\n' || c == '\0'){
			osDelay(1);
			continue;
		}
		line.append(1, c);
	}
	return line;
}
