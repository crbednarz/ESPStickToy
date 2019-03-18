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
	esc::PCA9685 _motorDriver;
	esc::Nunchuck _nunchuck;
};
