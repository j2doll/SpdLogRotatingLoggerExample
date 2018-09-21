# Example for spdlog Rotating Logger

- Example for spdlog Rotating Logger [https://github.com/j2doll/SpdLogRotatingLoggerExample](https://github.com/j2doll/SpdLogRotatingLoggerExample)
- spdlog is very fast, header only, C++ logging library. [https://github.com/gabime/spdlog](https://github.com/gabime/spdlog)
- Example runs on Visual Studio 2017.

## Main Code
 
```cpp
	// Create a file rotating logger with 1 mb size max and O rotated files
size_t maxFileSize = 1024768; // Maximum log file size is 1MB.
size_t msxFileCount = 0; // Only rotating.txt file is used.
auto rotating_logger = spdlog::rotating_logger_mt("some_logger_name", "rotating.txt", maxFileSize, msxFileCount);

for (int ic = 0 ; ic < 100000; ic++ ) 
{
	rotating_logger->warn("Easy padding in numbers like {:08d}", 12);
	rotating_logger->critical("Support for int: {0:d};  hex: {0:x};  oct: {0:o}; bin: {0:b}", 42);
	rotating_logger->info("Support for floats {:03.2f}", 1.23456);
	rotating_logger->info("Positional args are {1} {0}..", "too", "supported");
	rotating_logger->info("{:<30}", "left aligned");
}
```

## License
- MIT License
