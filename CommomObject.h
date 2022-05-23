#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#include "ObstacleCar.h"
#include "ObjectBuffPower.h"
#include "ObstacleObject.h"


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
	void HandleObstaclecarList(bool& PauseGame, bool& IsStartGame, bool& IsIncreaseVelocity);
	void RenderObstaclecarList(SDL_Renderer* screen);
	vector<OBSTACLE_CAR*>GetListObstacleCar() const { return ListObstacleCar; }
	void LoadObstacleObject(string path, const int& pos, SDL_Renderer* screen);
	void HandleObstacleObject(bool& PauseGame, bool& IsStartGame);
	void RenderObstacleObject(SDL_Renderer* screen);
	vector<OstacleObject*> get_ListObstacleObject() const { return ListObstacleObject; }
	void LoadObjectToBuffPower(string path, const int& pos, SDL_Renderer* screen);
	void HandleObstacleListObjectToBuffPower(bool& PauseGame, bool& IsStartGame);
	void RenderObstacleListObjectToBuffPower(SDL_Renderer* screen);
	vector<ObjectToBuffPower*>GetListObjectToBuffPower() const { return ListObjectToBuffPower; }
	void ClearObstacleCar();
	void clearListObstacleObject();
	void clearListObjectToBuffPower();
private:
	vector<OBSTACLE_CAR*> ListObstacleCar;
	vector<OstacleObject*> ListObstacleObject;
	vector <ObjectToBuffPower*> ListObjectToBuffPower;
};
