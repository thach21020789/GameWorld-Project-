#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <SDL_mixer.h>
#include<SDL_ttf.h>
#include "Htexture.h"

class OstacleObject : public LTexture
{
public:
	const int OstacleObjectSpeed = 3;
	const int WithOfOstacleObject = 28;
	const int HeightOfOstacleObject = 25;
	OstacleObject();
	~OstacleObject();
	void SetStartPosition(const int& x, const int& y);
	bool LoadObstacleObject_texture(string path, SDL_Renderer * screen);
	void AutoIncreaseYForOstacleObject();
	void ObjectNotMove();
	void render(SDL_Renderer *screen);
	int GetObjectPositionY() const;
	SDL_Rect getObstacleObjectRect() const;
private:
	SDL_Rect BoxObstacleObject;
};