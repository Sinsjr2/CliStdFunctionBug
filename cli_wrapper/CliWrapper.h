#pragma once

#include <functional>

#ifdef EXPORT
#define DLL_FUNC __declspec(dllexport)
#else
#define DLL_FUNC __declspec(dllimport)
#endif


class CliWrapper
{
public:
	DLL_FUNC static int ExecCallback(std::function<int ()> callback);
	DLL_FUNC static int ExecCallbackRef(const std::function<int()>& callback);
};

