#include "pch.h"
#include "Logger.h"
#include <sstream>
#include <comdef.h>
#include <time.h>

using namespace std;

Logger::Logger() {
}

Logger::Logger( char const* _fileName, char const* _mode) {

	auto fileName = std::string(getFormattedTime()) + std::string("-") + std::string(_fileName);

	if (auto err = fopen_s(&file, fileName.c_str(), _mode)) {
		char buff[256];
		strerror_s(buff, 100, 2);
		fprintf(stderr, "No se ha podido abrir el fichero '%s': %s\n", _fileName, buff);
		return;
	}
}

Logger * __stdcall Logger::toPrintFileMethod() {
	stringstream ss;
	ss << __LINE__;
	return toPrintFile( (std::string(__FUNCTION__) + std::string("  L: ") + ss.str() + std::string(" | ") + std::string(__FILE__) + std::string("\n")).c_str());
}

Logger* __stdcall Logger::toPrintFile(std::string &str) {
	return toPrintFile(str.c_str());
}

Logger* __stdcall Logger::toPrintFileln(std::string &str) {
	return toPrintFile((str+std::string("\n")).c_str());
}

Logger* __stdcall Logger::toPrintFile(const char * str, ...)
{
	if (!file)
		file = stdout;
	
	WaitForSingleObject(lock, INFINITE);
	print(str);
	ReleaseMutex(lock);

	return this;
}


Logger* __stdcall Logger::toPrintFileln(const char * str, ...) {
	return toPrintFile((std::string(str) + std::string("\n")).c_str());
}

Logger* __stdcall Logger::toPrintFile(const WCHAR * str, ...) {
	if (!file)
		file = stdout;

	WaitForSingleObject(lock, INFINITE);
	bstr_t b(str);
	const char* convert = b;
	print(convert);
	ReleaseMutex(lock);
	return this;
}

Logger* __stdcall Logger::toPrintFileln(const WCHAR * str, ...) {
	bstr_t b(str);
	return toPrintFile((std::string(b) + std::string("\n")).c_str());
}

Logger::~Logger() {
	if(this)
		free(this);
}

char* Logger::getFormattedTime(void) {
	time_t rawtime;
	struct tm* timeinfo;

	time(&rawtime);
	timeinfo = localtime(&rawtime);

	static char _retval[20];
	strftime(_retval, sizeof(_retval), "%Y-%m-%d_%H-%M-%S", timeinfo);

	return _retval;
}

void Logger::print(const char * str, ...) {
	va_list va;
	va_start(va, str);
	vfprintf(file, str, va);
	fflush(file);
	va_end(va);
}
