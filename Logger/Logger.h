// include guard
#ifndef ___LOGGER_H_INCLUDED__
#define ___LOGGER_H_INCLUDED__

#ifdef _MSC_VER
#pragma once
#endif 

#define METHOD(message) toPrintFile(__FUNCTION__, __FILE__, __LINE__, (message));

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
	Logger* __stdcall toPrintFileMethod();
	Logger* __stdcall toPrintFile(std::string &str);
	Logger* __stdcall toPrintFile(const char *str, ...);
	Logger* __stdcall toPrintFile(const WCHAR *str, ...);
	Logger* __stdcall toPrintFileln(std::string &str);
	Logger* __stdcall toPrintFileln(const char * str, ...);
	Logger* __stdcall toPrintFileln(const WCHAR *str, ...);
	~Logger();

private:
	FILE *file = NULL;
	HANDLE lock = 0;
	void print(const char *, ...);
	static char* getFormattedTime(void);
};


#endif

