#include "Exception.h"

const char* OutOfRangeException::what() const noexcept {
	return message.c_str();
}

const char* IncompatibleDimException::what() const noexcept {
	return message.c_str();
}