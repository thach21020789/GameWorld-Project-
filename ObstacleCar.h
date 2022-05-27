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

class OBSTACLE_CAR :public LTexture
{
public:
	const int WidthOfObstacleCar = 60;
	const int HeightOfObstacleCar = 140;
	const int OBSTACLESPEED1 = 5;
	const int OBSTACLESPEED2 = 6;
	const int NumberToJust = 10;

	OBSTACLE_CAR();
	~OBSTACLE_CAR();
	
	void SetStartPosionOfObstacleCar(const int& x, const int& y);

	void set_is_moving(const bool& val) { is_moving = val; }

	bool LoadObstacleCar(string path, SDL_Renderer* screen);
	
	void AutoIncreaseY(SDL_Rect maincar);
	
	void ObstacleCarNotMove();

	void render(SDL_Renderer* screen);

	int GetObstacleCarPosY() const;
	SDL_Rect GetObstacleCarRect() const;

	SDL_Rect GetObstacleCarRect_box() const;

	bool get_is_moving_car() const { return is_moving; }

	void Set_OBSTACLESPEED(const int& val) { OBSTACLESPEED = val; }

private:
	SDL_Rect ObstacleCarRect;
	SDL_Rect ObstacleCarBoxToCheckCollision;

	int OBSTACLESPEED;
	bool is_moving;
};
