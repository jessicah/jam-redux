#pragma once

#include <string>
#include <exception>

class Exception : public std::runtime_error {
public:
	Exception() = default;
	Exception(const std::string& message)
		: std::runtime_error(message.c_str()) { }

	virtual ~Exception() = default;
};