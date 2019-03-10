# Logger

### API 
```C
  Logger();
  Logger(char const* fileName, char const* mode);
  Logger* __stdcall toPrintFileMethod(const object obj);
  Logger* __stdcall toPrintFile(std::string &str);
  Logger* __stdcall toPrintFile(std::string &str);
  Logger* __stdcall toPrintFile(const char *str, ...);
  Logger* __stdcall toPrintFile(const WCHAR *str, ...);
  Logger* __stdcall toPrintFileln(std::string &str);
  Logger* __stdcall toPrintFileln(const char * str, ...);
  Logger* __stdcall toPrintFileln(const WCHAR *str, ...);
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
```

### RESULT
![](https://raw.githubusercontent.com/vicboma1/Logger/master/assets/foo.gif)
