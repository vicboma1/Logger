# Logger

### API 
```C
  Logger();
	Logger(char const* fileName, char const* mode);
	Logger* __stdcall toString(const char *str, ...);
	Logger* __stdcall toString(const WCHAR *str, ...);
	~Logger();
```

### EXAMPLE
```C
#include "pch.h"
#include "Logger.h"
#include <iostream>

using namespace std;

int main()
{
	wchar_t msg[1024];
	std::wcsncpy(msg, L"Hello World! \n", 1024);

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
		->toString("fluent interface")
		->~Logger();
}
```

### RESULT
![](https://raw.githubusercontent.com/vicboma1/Logger/master/assets/foo.gif)
