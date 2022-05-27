#include "ObstacleCar.h"
#include "function.h"

OBSTACLE_CAR::OBSTACLE_CAR()
{
	ObstacleCarRect = { 0,0,WidthOfObstacleCar ,HeightOfObstacleCar };

	ObstacleCarBoxToCheckCollision = { 0,0,WidthOfObstacleCar - NumberToJust ,HeightOfObstacleCar - NumberToJust };

	OBSTACLESPEED = 0;

	is_moving = false;
}
OBSTACLE_CAR::~OBSTACLE_CAR() {};
void OBSTACLE_CAR::SetStartPosionOfObstacleCar(const int& x, const int& y)
{
	ObstacleCarRect.x = x;
	ObstacleCarRect.y = y;

	ObstacleCarBoxToCheckCollision.x = x + NumberToJust;
	ObstacleCarBoxToCheckCollision.y = y + NumberToJust;
}
bool OBSTACLE_CAR::LoadObstacleCar(string path, SDL_Renderer* screen)
{
	bool load = LTexture::loadFromFile(path, screen);
	return load;
}

void OBSTACLE_CAR::AutoIncreaseY(SDL_Rect maincar) {
	if (is_moving)
	{
		ObstacleCarRect.y += OBSTACLESPEED;
		ObstacleCarBoxToCheckCollision.y += OBSTACLESPEED;
	}
}

void OBSTACLE_CAR::ObstacleCarNotMove() { ObstacleCarRect.y += 0; }

void OBSTACLE_CAR::render(SDL_Renderer* screen)
{

	LTexture::render(screen, ObstacleCarRect.x, ObstacleCarRect.y);
	//SDL_SetRenderDrawColor(screen, 0, 0, 0, 255);
	//SDL_RenderDrawRect(screen, &ObstacleCarBoxToCheckCollision);
	//SDL_RenderDrawRect(screen, &ObstacleCarRect);
}

int OBSTACLE_CAR::GetObstacleCarPosY() const { return ObstacleCarRect.y; }

SDL_Rect OBSTACLE_CAR::GetObstacleCarRect() const { return ObstacleCarRect; }

SDL_Rect OBSTACLE_CAR::GetObstacleCarRect_box() const { return ObstacleCarBoxToCheckCollision; }
