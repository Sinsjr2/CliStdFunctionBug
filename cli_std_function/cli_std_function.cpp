#include <iostream>
#include "CliWrapper.h"

int ExecCallback(std::function<int()> callback)
{
	return callback();
}

int main()
{
	{
		auto native1 = ExecCallback([]() { return 15; });
		std::cout << native1 << "\n";
	}
	{
		bool isCalled = false;
		auto cliGood = CliWrapper::ExecCallbackRef([&isCalled]() { isCalled = true; return 200; });
		std::cout << cliGood << "\n";
		std::cout << isCalled << "\n";
	}
	{
		bool isCalled = false;
		auto func = [&isCalled]() { isCalled = true; return 100; };
		std::cout << &func << "\n";
		auto cliBad = CliWrapper::ExecCallback(func);
		std::cout << cliBad << "\n";
		std::cout << isCalled << "\n";
	}
}
