#include "App.hpp"
#include "Task.hpp"
#include <iostream>


App::App()
{
	_motorDriver.connect();
	_motorDriver.setFrequency(50.0f);

	for (size_t i = 0; i < _motorDriver.channelCount(); i++)
		_motorDriver.setRange(i, 0.52f, 2.56f);

	_motorDriver.set(0, 1.0f);
	_motorDriver.set(1, 1.0f);

	_nunchuck.connect();
}


void App::update()
{
	_nunchuck.poll();

	std::cout << "JOY: " << _nunchuck.joystick().x << " " << _nunchuck.joystick().y << std::endl;
	_motorDriver.set(0, _nunchuck.joystick().x);
	_motorDriver.set(1, _nunchuck.joystick().y);
}


void App::stop()
{
}