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
	void AutoIncreaseYForOstacleObject(SDL_Rect& maincar);
	void ObjectNotMove();
	void render(SDL_Renderer *screen);

	void set_is_moving(const bool& val) { is_moving = val; }
	int GetObjectPositionY() const;
	SDL_Rect getObstacleObjectRect() const;

	bool get_is_moving() const { return is_moving; }
private:
	SDL_Rect BoxObstacleObject;

	bool is_moving;
};