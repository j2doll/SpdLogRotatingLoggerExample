// SpdLogRotatingLogger.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

#include "spdlog/sinks/rotating_file_sink.h"

int main()
{
	// Create a file rotating logger with OO mb size max and O rotated files
	size_t maxFileSize = 1024768;
	size_t msxFileCount = 0;
	auto rotating_logger = spdlog::rotating_logger_mt("some_logger_name", "rotating.txt", maxFileSize, msxFileCount);
    
	for (int ic = 0 ; ic < 100000; ic++ )
	{
		rotating_logger->warn("Easy padding in numbers like {:08d}", 12);
		rotating_logger->critical("Support for int: {0:d};  hex: {0:x};  oct: {0:o}; bin: {0:b}", 42);
		rotating_logger->info("Support for floats {:03.2f}", 1.23456);
		rotating_logger->info("Positional args are {1} {0}..", "too", "supported");
		rotating_logger->info("{:<30}", "left aligned");
	}

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
