#include "pch.h"
#include "Logger.h"
#include <iostream>

using namespace std;

int main(void)
{
	Logger* logger = new Logger("foo.txt", "w");

	wchar_t msg[1024];
	std::wcsncpy(msg, L"Hello World! \n", 1024);

	logger->toPrintFileMethod()
		->toPrintFileln(msg)
		->toPrintFileln("I'm")
		->toPrintFileln("a")
		->toPrintFileln("chainneable")
		->toPrintFileln("method")
		->toPrintFile("pattern")
		->toPrintFile(" --- ")
		->toPrintFileln("fluent interface")
		->~Logger();
}
