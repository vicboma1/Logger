// include guard
#ifndef ___LOGGER_H_INCLUDED__
#define ___LOGGER_H_INCLUDED__

#ifdef _MSC_VER
#pragma once
#endif // _MSC_VER

//=================================
// included dependencies
#include <windows.h>
#include <iostream>
//=================================
// the actual class
class Logger
{
public:
	Logger();
	Logger(char const* fileName, char const* mode);
	Logger* __stdcall toString(const char *str, ...);
	Logger* __stdcall toString(const WCHAR *str, ...);
	~Logger();

private:
	FILE *file = NULL;
	HANDLE lock = 0;
	void println(const char *str, ...);
	void println(const WCHAR *str, ...);
};


#endif // __LOGGER_H_INCLUDED__ 

