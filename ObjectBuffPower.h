#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <SDL_mixer.h>
#include "Htexture.h"

class ObjectToBuffPower : public LTexture
{
public:
	const int BOX_SPEED = 5;
	const int HeightOfOstacleObject = 35;
	const int WidthOfObjectBuffPower = 35;
	ObjectToBuffPower();
	~ObjectToBuffPower() ;
	void SetStatrtPositionOfObjectBuffPower(const int& x, const int& y);
	bool LoadObjectTobuffPower(string path, SDL_Renderer *screen);
	void AutoIncreaseYForObjectBuffPower();
	void ObjectBuffPowernotMove();
	void render(SDL_Renderer *screen);
	int GetPositionYofObjectBuffPower() const;
	SDL_Rect GetBoxRect() const;
private:
	SDL_Rect BoxRect;
};