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
	bool LoadObstacleCar(string path, SDL_Renderer* screen);
	void AutoIncreaseY(bool IsIncreaseVelocity);
	
	void ObstacleCarNotMove();

	void render(SDL_Renderer* screen);

	int GetObstacleCarPosY() const;
	SDL_Rect GetObstacleCarRect() const;

	SDL_Rect GetObstacleCarRect_box() const;

private:
	SDL_Rect ObstacleCarRect;
	SDL_Rect ObstacleCarBoxToCheckCollision;
};
