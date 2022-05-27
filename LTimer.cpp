#include "LTimer.h"
LTimer::LTimer()
{
	mStartTicks = 0;
	mPausedTicks = 0;
	mPaused = false;
	mStarted = true;
}
void LTimer::start()
{
	turn_off_clock = false;
	mStarted = true;
	mPaused = false;
	mStartTicks = SDL_GetTicks();
	mPausedTicks = 0;
}
void LTimer::stop()
{
	turn_off_clock = true;
	mStarted = false;
	mPaused = false;
	mStartTicks = 0;
	mPausedTicks = 0;
}
void LTimer::pause()
{
	if (mStarted && !mPaused)
	{
		mPaused = true;
		mPausedTicks = SDL_GetTicks() - mStartTicks;
		mStartTicks = 0;
	}
}
void LTimer::unpause()
{
	if (mStarted && mPaused)
	{
		mPaused = false;
		mStartTicks = SDL_GetTicks() - mPausedTicks;
		mPausedTicks = 0;
	}
}
Uint32 LTimer::getTicks()
{
	Uint32 time = 0;
	if (mStarted)
	{
		if (mPaused)
		{
			time = mPausedTicks;
		}
		else
		{
			time = SDL_GetTicks() - mStartTicks;
		}
	}
	return time;
}

bool LTimer::isStarted()
{
	return mStarted;
}
bool LTimer::isPaused()
{
	return mPaused && mStarted;
}

bool LTimer::turn_off() const { return turn_off_clock; }