#pragma once


class Program
{
public:
	Program() = delete;

	static void launch();
	
private:
	static void altCoreThreadEntry();
};
