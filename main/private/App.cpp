#include "App.hpp"
#include "Task.hpp"
#include <iostream>


App::App()
{
	_motorDriver.connect();
	_motorDriver.setFrequency(50.0f);

	for (size_t i = 0; i < _motorDriver.channelCount(); i++)
		_motorDriver.setRange(0, 0.52f, 2.56f);

	_motorDriver.set(0, 0.5f);
}


void App::update()
{
	_motorDriver.set(0, 0.0f);
	Task::sleep(1000);
	_motorDriver.set(1, 1.0f);
	Task::sleep(1000);
	_motorDriver.set(0, 1.0f);
	Task::sleep(1000);
	_motorDriver.set(1, 0.0f);
	Task::sleep(1000);
}


void App::stop()
{
}