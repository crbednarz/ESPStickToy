#pragma once
#include "PCA9685.hpp"
#include "Nunchuck.hpp"


class App
{
public:
	App();

	void update();
	
	void stop();

private:
	PCA9685 _motorDriver;
	Nunchuck _nunchuck;
};
