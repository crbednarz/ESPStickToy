#include "Program.hpp"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"
#include "App.hpp"
#include "Stopwatch.hpp"
#include "I2CDevice.hpp"
#include <stdint.h>


void Program::launch()
{
	using namespace esc;
	I2CDevice::initialize();

	Stopwatch stopwatch;
	App app;

	xTaskCreatePinnedToCore(reinterpret_cast<TaskFunction_t>(&altCoreThreadEntry), "AltCoreThread", 2048, NULL, 25, NULL, 1);

	printf("RAM left %d\n", esp_get_free_heap_size());
	while (true) 
	{
		stopwatch.start();
		app.update();
		stopwatch.stop();
	
		if (stopwatch.recordCount() == 100)
		{
			auto averageTimeElapsed = stopwatch.averageTime();
			printf("Average Frame Time: %ffps\n", 1.0 / averageTimeElapsed);
			stopwatch.reset();
		}
	}

	app.stop();
	
	while (true)
	{

	}
}

void Program::altCoreThreadEntry()
{
	while (true)
	{

	}
}

/*
// This is to avoid potential calls to new: It'll create a compile-time error.
void* operator_new_blocker();

void* operator new(size_t size)
{
	return operator_new_blocker();
}

*/
extern "C" void app_main()
{
	Program::launch();
}
