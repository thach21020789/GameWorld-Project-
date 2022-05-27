#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <SDL_mixer.h>
#include "Htexture.h"

class ItemToBuffPower : public LTexture
{
public:
	const int BOX_SPEED = 5;
	const int HeightOfOstacleObject = 35;
	const int WidthOfObjectBuffPower = 35;
	ItemToBuffPower();
	~ItemToBuffPower() ;
	void SetStatrtPositionOfObjectBuffPower(const int& x, const int& y);
	bool LoadObjectTobuffPower(string path, SDL_Renderer *screen);
	void AutoIncreaseYForObjectBuffPower(SDL_Rect &maincar);
	void ObjectBuffPowernotMove();
	void render(SDL_Renderer *screen);


	void set_is_moving(const bool& val) { is_moving = val; }

	int GetPositionYofObjectBuffPower() const;
	SDL_Rect GetBoxRect() const;
	bool get_is_moving() const { return is_moving; }
private:
	SDL_Rect BoxRect;
	bool is_moving;
};