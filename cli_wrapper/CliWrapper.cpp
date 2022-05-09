#include "CliWrapper.h"

#include <iostream>

int CliWrapper::ExecCallback(std::function<int()> callback)
{
	std::cout << &callback << "\n";
	return callback();
}

int CliWrapper::ExecCallbackRef(const std::function<int()>& callback)
{
	return callback();
}
