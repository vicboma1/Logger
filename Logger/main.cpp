#include "pch.h"
#include "Logger.h"
#include <iostream>

using namespace std;

int main()
{
	auto msg = "Hello World!\n";

	auto fileName = "foo.txt";
	auto attr = "w";
	Logger* logger = new Logger(fileName, attr);
	logger->toString(msg)
		->toString("I'm")
		->toString("a")
		->toString("chainneable")
		->toString("method")
		->toString("pattern")
		->toString("---")
		->toString("fluent interface");

}