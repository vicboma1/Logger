#include "pch.h"
#include "Logger.h"
using namespace std;

Logger::Logger()
{
}

Logger::Logger(
	char const* _fileName,
	char const* _mode)
{

	if (auto err = fopen_s(&file, _fileName, _mode)) {
		char buff[256];
		strerror_s(buff, 100, 2);
		fprintf(stderr, "No se ha podido abrir el fichero '%s': %s\n", _fileName, buff);
		return;
	}
}

Logger* __stdcall Logger::toString(const char * str, ...)
{
	if (!file)
		file = stdout;
	
	WaitForSingleObject(lock, INFINITE);
	println("%s\n",str);
	ReleaseMutex(lock);

	return this;
}

Logger* __stdcall Logger::toString(const WCHAR * str, ...)
{
	if (!file)
		file = stdout;

	WaitForSingleObject(lock, INFINITE);
	println(str);
	ReleaseMutex(lock);
	return this;
}

Logger::~Logger()
{
	free(this);
}


void Logger::println(const char * str, ...)
{
	va_list va;
	va_start(va, str);
	vfprintf(file, str, va);
	fflush(file);
	va_end(va);
}

void Logger::println(const WCHAR * str, ...)
{
	va_list va;
	va_start(va, str);
	vfwprintf(file, str, va);
	fflush(file);
	va_end(va);
}