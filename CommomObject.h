#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <SDL_mixer.h>
#include "Htexture.h"
#include "ObstacleCar.h"
#include "ObjectBuffPower.h"
#include "ObstacleObject.h"


enum mode
{
	EASY = 0, MEDIUM = 1, HARD = 2, SUPER_HARD = 3
};

const int OBSTACLE_SPEED[4] = { 5,6,7,8 };

class OBJECT
{
public:
	const int PointEndScreen = 2000;
	const int PositionToRenderObstacle = -200;
	const int HeightOfOstacleObject = 25;
	const int ScreenHeight = 650;

	OBJECT();
	~OBJECT();

	void LoadObstacleCar(string path, const int& pos, SDL_Renderer* screen);
	void HandleObstaclecarList(SDL_Rect maincar, SDL_Renderer* screen, bool& lose_game, bool &use_power, Mix_Chunk* SoundWhenGameOver);
	void RenderObstaclecarList(SDL_Renderer* screen);
	vector<OBSTACLE_CAR*>GetListObstacleCar() const;

	void LoadObstacleObject(string path, const int& pos, SDL_Renderer* screen);
	void HandleObstacleObject(SDL_Rect maincar, SDL_Renderer* screen, bool& lose_game, bool& use_power, Mix_Chunk* SoundWhenGameOver);
	void RenderObstacleObject(SDL_Renderer* screen);
	vector<OstacleObject*> get_ListObstacleObject() const;

	void LoadObjectToBuffPower(string path, const int& pos, SDL_Renderer* screen);
	void HandleObstacleListObjectToBuffPower(SDL_Rect maincar, SDL_Renderer* screen, bool& switch_car_texture);
	void RenderObstacleListObjectToBuffPower(SDL_Renderer* screen);
	vector<ItemToBuffPower*>GetListObjectToBuffPower() const;


	void ClearObstacleCar();
	void clearListObstacleObject();
	void clearListObjectToBuffPower();

	void increaseHardMode() {
		if (hard_mode == EASY) hard_mode = MEDIUM;
		else if (hard_mode == MEDIUM) hard_mode = HARD;
		else if (hard_mode == HARD) hard_mode = SUPER_HARD;
	}
	void resetHardMode() { hard_mode = EASY; }
private:
	vector<OBSTACLE_CAR*> ListObstacleCar;
	vector<OstacleObject*> ListObstacleObject;
	vector <ItemToBuffPower*> ListObjectToBuffPower;

	int hard_mode;
};

static OBJECT ObjectList;
