#pragma once

#include "stddef.h"

template<typename TYPE, size_t SIZE>
class Buffer {
public:
	enum State {
		ERROR = -1, OK = 0,
	};
	Buffer() {
	}

	~Buffer() {
	}

	State add(TYPE c) {
		if (_len + 1 > _size)
			return ERROR;

		size_t pointer = _end + 1;
		if (pointer >= _size)
			pointer -= _size;

		_buf[_end] = c;
		_len += 1;
		_end = pointer;
		return OK;
	}

	const TYPE get() {
		if (_len == 0)
			return 0;

		char c = _buf[_begin];
		_begin += 1;
		if (_begin >= _size)
			_begin -= _size;
		_len -= 1;
		return c;
	}

	const size_t len() {
		return _len;
	}

private:
	TYPE _buf[SIZE];
	size_t _begin = 0;
	size_t _end = 0;
	size_t _len = 0;
	const size_t _size = SIZE;
};
