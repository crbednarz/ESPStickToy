#pragma once
#include "PCA9685.hpp"


class App
{
public:
	App();

	void update();
	
	void stop();

private:
	PCA9685 _motorDriver;
};
