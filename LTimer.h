#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include<SDL_ttf.h>

class LTimer
{
public:
	LTimer();
	void start();
	void stop();
	void pause();
	void unpause();
	Uint32 getTicks();
	bool isStarted();
	bool isPaused();
	bool turn_off() const;
private:
	Uint32 mStartTicks;
	Uint32 mPausedTicks;
	bool mPaused;
	bool mStarted;

	bool turn_off_clock;
};

static LTimer delayTimecreateObstacleCar;
static LTimer delayTimecreateObstacleObject;
static LTimer delayTimecreateItemBuffPower;